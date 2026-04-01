#include "crypto/hash_adapter.h"

#include "sha256.h"

#include <string.h>

/**
 * @brief Wipe a sensitive buffer in a way that the compiler keeps.
 */
static void auth_secure_zero(void *buffer, size_t length)
{
    volatile uint8_t *cursor = buffer;

    while (length > 0u) {
        *cursor = 0u;
        ++cursor;
        --length;
    }
}

static bool auth_is_nullable_buffer_valid(const uint8_t *buffer, size_t length)
{
    return buffer != nullptr || length == 0u;
}

/**
 * @brief Compare two byte strings without early exit.
 */
static bool auth_constant_time_equal(const uint8_t *left,
                                     const uint8_t *right,
                                     size_t length)
{
    uint8_t diff = 0u;

    for (size_t index = 0; index < length; ++index) {
        diff |= left[index] ^ right[index];
    }

    return diff == 0u;
}

static void auth_bytes_to_hex(const uint8_t *bytes, size_t length, char *output)
{
    static const char digits[] = "0123456789abcdef";

    for (size_t index = 0; index < length; ++index) {
        output[index * 2u] = digits[(bytes[index] >> 4u) & 0x0fu];
        output[(index * 2u) + 1u] = digits[bytes[index] & 0x0fu];
    }

    output[length * 2u] = '\0';
}

/**
 * @brief Compute HMAC-SHA256 over one or two concatenated message fragments.
 *
 * The adapter uses the two-fragment form to avoid allocating a temporary
 * buffer for "salt || block_index" during PBKDF2.
 */
static void auth_hmac_sha256_concat(const uint8_t *key,
                                    size_t key_len,
                                    const uint8_t *part1,
                                    size_t part1_len,
                                    const uint8_t *part2,
                                    size_t part2_len,
                                    uint8_t digest[AUTH_SHA256_DIGEST_BYTES])
{
    auth_sha256_ctx_t ctx;
    uint8_t key_block[AUTH_SHA256_BLOCK_BYTES];
    uint8_t inner_pad[AUTH_SHA256_BLOCK_BYTES];
    uint8_t outer_pad[AUTH_SHA256_BLOCK_BYTES];
    uint8_t inner_digest[AUTH_SHA256_DIGEST_BYTES];

    memset(key_block, 0, sizeof(key_block));
    if (key_len > AUTH_SHA256_BLOCK_BYTES) {
        auth_sha256_digest(key, key_len, key_block);
    } else if (key_len > 0u) {
        memcpy(key_block, key, key_len);
    }

    for (size_t index = 0; index < AUTH_SHA256_BLOCK_BYTES; ++index) {
        inner_pad[index] = key_block[index] ^ 0x36u;
        outer_pad[index] = key_block[index] ^ 0x5cu;
    }

    auth_sha256_init(&ctx);
    auth_sha256_update(&ctx, inner_pad, sizeof(inner_pad));
    if (part1_len > 0u) {
        auth_sha256_update(&ctx, part1, part1_len);
    }
    if (part2_len > 0u) {
        auth_sha256_update(&ctx, part2, part2_len);
    }
    auth_sha256_finalize(&ctx, inner_digest);

    auth_sha256_init(&ctx);
    auth_sha256_update(&ctx, outer_pad, sizeof(outer_pad));
    auth_sha256_update(&ctx, inner_digest, sizeof(inner_digest));
    auth_sha256_finalize(&ctx, digest);

    auth_secure_zero(key_block, sizeof(key_block));
    auth_secure_zero(inner_pad, sizeof(inner_pad));
    auth_secure_zero(outer_pad, sizeof(outer_pad));
    auth_secure_zero(inner_digest, sizeof(inner_digest));
}

static void auth_hmac_sha256(const uint8_t *key,
                             size_t key_len,
                             const uint8_t *message,
                             size_t message_len,
                             uint8_t digest[AUTH_SHA256_DIGEST_BYTES])
{
    auth_hmac_sha256_concat(key, key_len, message, message_len, nullptr, 0u, digest);
}

/**
 * @brief Derive the first PBKDF2-HMAC-SHA256 block and return it as raw bytes.
 *
 * Because the engine only needs a 32-byte derived key, the implementation
 * computes a single PBKDF2 block and XOR-accumulates U1..Uc in place.
 */
static void auth_pbkdf2_hmac_sha256_32(const uint8_t *password,
                                       size_t password_len,
                                       const uint8_t *salt,
                                       size_t salt_len,
                                       uint32_t iterations,
                                       uint8_t derived_key[AUTH_HASH_DERIVED_KEY_BYTES])
{
    const uint8_t block_index[4] = {0u, 0u, 0u, 1u};
    uint8_t block[AUTH_SHA256_DIGEST_BYTES];
    uint8_t accumulator[AUTH_SHA256_DIGEST_BYTES];

    auth_hmac_sha256_concat(password, password_len, salt, salt_len,
                            block_index, sizeof(block_index), block);
    memcpy(accumulator, block, sizeof(accumulator));

    for (uint32_t round = 1u; round < iterations; ++round) {
        auth_hmac_sha256(password, password_len, block, sizeof(block), block);

        for (size_t index = 0; index < sizeof(accumulator); ++index) {
            accumulator[index] ^= block[index];
        }
    }

    memcpy(derived_key, accumulator, AUTH_HASH_DERIVED_KEY_BYTES);
    auth_secure_zero(block, sizeof(block));
    auth_secure_zero(accumulator, sizeof(accumulator));
}

auth_hash_status_t auth_hash_password(const uint8_t *password,
                                      size_t password_len,
                                      const uint8_t *salt,
                                      size_t salt_len,
                                      char *output,
                                      size_t output_size)
{
    return auth_hash_password_with_iterations(password, password_len,
                                              salt, salt_len,
                                              AUTH_HASH_PBKDF2_ITERATIONS,
                                              output, output_size);
}

auth_hash_status_t auth_hash_password_with_iterations(const uint8_t *password,
                                                      size_t password_len,
                                                      const uint8_t *salt,
                                                      size_t salt_len,
                                                      uint32_t iterations,
                                                      char *output,
                                                      size_t output_size)
{
    uint8_t derived_key[AUTH_HASH_DERIVED_KEY_BYTES];

    if (!auth_is_nullable_buffer_valid(password, password_len) ||
        !auth_is_nullable_buffer_valid(salt, salt_len) ||
        output == nullptr ||
        iterations == 0u) {
        return AUTH_HASH_STATUS_INVALID_ARGUMENT;
    }

    if (output_size < AUTH_HASH_ENCODED_LENGTH) {
        return AUTH_HASH_STATUS_OUTPUT_TOO_SMALL;
    }

    auth_pbkdf2_hmac_sha256_32(password, password_len, salt, salt_len,
                               iterations, derived_key);
    auth_bytes_to_hex(derived_key, sizeof(derived_key), output);
    auth_secure_zero(derived_key, sizeof(derived_key));

    return AUTH_HASH_STATUS_OK;
}

bool auth_hash_verify_password(const uint8_t *password,
                               size_t password_len,
                               const uint8_t *salt,
                               size_t salt_len,
                               const char *expected_hash)
{
    return auth_hash_verify_password_with_iterations(password, password_len,
                                                     salt, salt_len,
                                                     expected_hash,
                                                     AUTH_HASH_PBKDF2_ITERATIONS);
}

bool auth_hash_verify_password_with_iterations(const uint8_t *password,
                                               size_t password_len,
                                               const uint8_t *salt,
                                               size_t salt_len,
                                               const char *expected_hash,
                                               uint32_t iterations)
{
    char actual_hash[AUTH_HASH_ENCODED_LENGTH];
    bool matches = false;

    if (expected_hash == nullptr ||
        strlen(expected_hash) != (AUTH_HASH_ENCODED_LENGTH - 1u)) {
        return false;
    }

    if (auth_hash_password_with_iterations(password, password_len,
                                           salt, salt_len,
                                           iterations,
                                           actual_hash,
                                           sizeof(actual_hash)) != AUTH_HASH_STATUS_OK) {
        return false;
    }

    matches = auth_constant_time_equal((const uint8_t *)actual_hash,
                                       (const uint8_t *)expected_hash,
                                       AUTH_HASH_ENCODED_LENGTH - 1u);
    auth_secure_zero(actual_hash, sizeof(actual_hash));

    return matches;
}

const char *auth_hash_status_string(auth_hash_status_t status)
{
    switch (status) {
    case AUTH_HASH_STATUS_OK:
        return "ok";
    case AUTH_HASH_STATUS_INVALID_ARGUMENT:
        return "invalid_argument";
    case AUTH_HASH_STATUS_OUTPUT_TOO_SMALL:
        return "output_too_small";
    default:
        return "unknown_hash_status";
    }
}

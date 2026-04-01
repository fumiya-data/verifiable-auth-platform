#include "crypto/salt_adapter.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#if defined(_WIN32)
#include <windows.h>
#include <bcrypt.h>
#endif

static void auth_salt_bytes_to_hex(const uint8_t *bytes, size_t length, char *output)
{
    static const char digits[] = "0123456789abcdef";

    for (size_t index = 0; index < length; ++index) {
        output[index * 2u] = digits[(bytes[index] >> 4u) & 0x0fu];
        output[(index * 2u) + 1u] = digits[bytes[index] & 0x0fu];
    }

    output[length * 2u] = '\0';
}

static bool auth_salt_is_hex_digit(const char value)
{
    return isxdigit((unsigned char)value) != 0;
}

/**
 * @brief Fill a raw byte buffer from the platform's cryptographic RNG.
 */
#if defined(_WIN32)
static auth_salt_status_t auth_salt_fill_random_impl(uint8_t *output, size_t output_size)
{
    if (output_size > (size_t)ULONG_MAX) {
        return AUTH_SALT_STATUS_RANDOM_SOURCE_FAILURE;
    }

    const NTSTATUS status =
        BCryptGenRandom(nullptr, output, (ULONG)output_size, BCRYPT_USE_SYSTEM_PREFERRED_RNG);

    return BCRYPT_SUCCESS(status) ? AUTH_SALT_STATUS_OK
                                  : AUTH_SALT_STATUS_RANDOM_SOURCE_FAILURE;
}
#else
static auth_salt_status_t auth_salt_fill_random_impl(uint8_t *output, size_t output_size)
{
    FILE *random_source = fopen("/dev/urandom", "rb");

    if (random_source == nullptr) {
        return AUTH_SALT_STATUS_RANDOM_SOURCE_FAILURE;
    }

    const size_t bytes_read = fread(output, 1u, output_size, random_source);
    const bool has_stream_error = ferror(random_source) != 0;

    fclose(random_source);

    if (has_stream_error || bytes_read != output_size) {
        return AUTH_SALT_STATUS_RANDOM_SOURCE_FAILURE;
    }

    return AUTH_SALT_STATUS_OK;
}
#endif

auth_salt_status_t auth_salt_fill_bytes(uint8_t *output, size_t output_size)
{
    if (output == nullptr) {
        return AUTH_SALT_STATUS_INVALID_ARGUMENT;
    }

    if (output_size < AUTH_SALT_BYTES) {
        return AUTH_SALT_STATUS_OUTPUT_TOO_SMALL;
    }

    return auth_salt_fill_random_impl(output, AUTH_SALT_BYTES);
}

auth_salt_status_t auth_salt_generate(char *output, size_t output_size)
{
    uint8_t raw_salt[AUTH_SALT_BYTES];
    const auth_salt_status_t status = auth_salt_fill_bytes(raw_salt, sizeof(raw_salt));

    if (status != AUTH_SALT_STATUS_OK) {
        return status;
    }

    if (output == nullptr) {
        return AUTH_SALT_STATUS_INVALID_ARGUMENT;
    }

    if (output_size < AUTH_SALT_ENCODED_LENGTH) {
        return AUTH_SALT_STATUS_OUTPUT_TOO_SMALL;
    }

    auth_salt_bytes_to_hex(raw_salt, sizeof(raw_salt), output);
    memset(raw_salt, 0, sizeof(raw_salt));

    return AUTH_SALT_STATUS_OK;
}

bool auth_salt_is_valid(const char *salt)
{
    if (salt == nullptr || strlen(salt) != (AUTH_SALT_ENCODED_LENGTH - 1u)) {
        return false;
    }

    for (size_t index = 0; index < AUTH_SALT_ENCODED_LENGTH - 1u; ++index) {
        if (!auth_salt_is_hex_digit(salt[index])) {
            return false;
        }
    }

    return true;
}

const char *auth_salt_status_string(auth_salt_status_t status)
{
    switch (status) {
    case AUTH_SALT_STATUS_OK:
        return "ok";
    case AUTH_SALT_STATUS_INVALID_ARGUMENT:
        return "invalid_argument";
    case AUTH_SALT_STATUS_OUTPUT_TOO_SMALL:
        return "output_too_small";
    case AUTH_SALT_STATUS_RANDOM_SOURCE_FAILURE:
        return "random_source_failure";
    default:
        return "unknown_salt_status";
    }
}

#ifndef VERIFIABLE_AUTH_PLATFORM_ENGINE_CRYPTO_SHA256_H
#define VERIFIABLE_AUTH_PLATFORM_ENGINE_CRYPTO_SHA256_H

#include <stddef.h>
#include <stdint.h>

/** SHA-256 compression block width in bytes. */
#define AUTH_SHA256_BLOCK_BYTES 64u
/** SHA-256 digest width in bytes. */
#define AUTH_SHA256_DIGEST_BYTES 32u

/**
 * @brief Mutable SHA-256 state used by the streaming update/finalize API.
 */
typedef struct auth_sha256_ctx {
    /** Current chaining value for the eight SHA-256 working words. */
    uint32_t state[8];
    /** Total message length in bytes, used when appending the final bit length. */
    uint64_t total_len;
    /** Partial input block that has not reached 64 bytes yet. */
    uint8_t buffer[AUTH_SHA256_BLOCK_BYTES];
    /** Number of bytes currently stored in @p buffer. */
    size_t buffer_len;
} auth_sha256_ctx_t;

/** @brief Initialize a SHA-256 context for a new message. */
void auth_sha256_init(auth_sha256_ctx_t *ctx);
/** @brief Feed message bytes into an initialized SHA-256 context. */
void auth_sha256_update(auth_sha256_ctx_t *ctx, const uint8_t *data, size_t length);
/** @brief Finalize the context and write the 32-byte digest. */
void auth_sha256_finalize(auth_sha256_ctx_t *ctx,
                          uint8_t digest[AUTH_SHA256_DIGEST_BYTES]);
/** @brief Convenience helper for hashing one contiguous byte range. */
void auth_sha256_digest(const uint8_t *data,
                        size_t length,
                        uint8_t digest[AUTH_SHA256_DIGEST_BYTES]);

#endif

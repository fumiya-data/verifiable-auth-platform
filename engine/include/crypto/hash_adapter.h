#ifndef VERIFIABLE_AUTH_PLATFORM_ENGINE_CRYPTO_HASH_ADAPTER_H
#define VERIFIABLE_AUTH_PLATFORM_ENGINE_CRYPTO_HASH_ADAPTER_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/** Number of bytes derived from PBKDF2-HMAC-SHA256. */
#define AUTH_HASH_DERIVED_KEY_BYTES 32u
/** Number of bytes required to store the lowercase hex digest plus '\0'. */
#define AUTH_HASH_ENCODED_LENGTH ((AUTH_HASH_DERIVED_KEY_BYTES * 2u) + 1u)
/** Default PBKDF2 iteration count used by the engine. */
#define AUTH_HASH_PBKDF2_ITERATIONS 100000u

/** Stable status codes returned by the password hashing adapter. */
typedef enum auth_hash_status {
    AUTH_HASH_STATUS_OK = 0,
    AUTH_HASH_STATUS_INVALID_ARGUMENT,
    AUTH_HASH_STATUS_OUTPUT_TOO_SMALL,
} auth_hash_status_t;

/**
 * @brief Derive the default password hash for a password and salt pair.
 *
 * The adapter uses PBKDF2-HMAC-SHA256 and encodes the result as lowercase hex.
 *
 * @param password Password bytes. May be empty but must not be nullptr when
 *                 @p password_len is non-zero.
 * @param password_len Number of password bytes.
 * @param salt Salt bytes. May be empty but must not be nullptr when
 *             @p salt_len is non-zero.
 * @param salt_len Number of salt bytes.
 * @param output Destination buffer for the encoded hash string.
 * @param output_size Size of @p output in bytes.
 * @return Status code describing success or the validation failure.
 */
auth_hash_status_t auth_hash_password(const uint8_t *password,
                                      size_t password_len,
                                      const uint8_t *salt,
                                      size_t salt_len,
                                      char *output,
                                      size_t output_size);

/**
 * @brief Derive a password hash with an explicit PBKDF2 iteration count.
 *
 * This variant exists mainly for deterministic tests and future migration work.
 *
 * @param password Password bytes.
 * @param password_len Number of password bytes.
 * @param salt Salt bytes.
 * @param salt_len Number of salt bytes.
 * @param iterations PBKDF2 iteration count. Must be greater than zero.
 * @param output Destination buffer for the encoded hash string.
 * @param output_size Size of @p output in bytes.
 * @return Status code describing success or the validation failure.
 */
auth_hash_status_t auth_hash_password_with_iterations(const uint8_t *password,
                                                      size_t password_len,
                                                      const uint8_t *salt,
                                                      size_t salt_len,
                                                      uint32_t iterations,
                                                      char *output,
                                                      size_t output_size);

/**
 * @brief Verify a plaintext password against a stored encoded hash.
 *
 * @param password Password bytes to verify.
 * @param password_len Number of password bytes.
 * @param salt Salt bytes used during hashing.
 * @param salt_len Number of salt bytes.
 * @param expected_hash Stored lowercase hex hash.
 * @return true when the password derives the expected hash.
 */
bool auth_hash_verify_password(const uint8_t *password,
                               size_t password_len,
                               const uint8_t *salt,
                               size_t salt_len,
                               const char *expected_hash);

/**
 * @brief Verify a plaintext password against a stored encoded hash with an
 *        explicit PBKDF2 iteration count.
 *
 * @param password Password bytes to verify.
 * @param password_len Number of password bytes.
 * @param salt Salt bytes used during hashing.
 * @param salt_len Number of salt bytes.
 * @param expected_hash Stored lowercase hex hash.
 * @param iterations PBKDF2 iteration count.
 * @return true when the password derives the expected hash.
 */
bool auth_hash_verify_password_with_iterations(const uint8_t *password,
                                               size_t password_len,
                                               const uint8_t *salt,
                                               size_t salt_len,
                                               const char *expected_hash,
                                               uint32_t iterations);

/**
 * @brief Convert a hash adapter status code to a stable string.
 *
 * @param status Status code returned by the adapter.
 * @return Stable string literal for logging or JSON serialization.
 */
const char *auth_hash_status_string(auth_hash_status_t status);

#endif

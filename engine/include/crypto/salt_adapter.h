#ifndef VERIFIABLE_AUTH_PLATFORM_ENGINE_CRYPTO_SALT_ADAPTER_H
#define VERIFIABLE_AUTH_PLATFORM_ENGINE_CRYPTO_SALT_ADAPTER_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/** Number of random bytes generated for each salt. */
#define AUTH_SALT_BYTES 16u
/** Number of bytes required to store the lowercase hex salt plus '\0'. */
#define AUTH_SALT_ENCODED_LENGTH ((AUTH_SALT_BYTES * 2u) + 1u)

/** Stable status codes returned by the salt generation adapter. */
typedef enum auth_salt_status {
    AUTH_SALT_STATUS_OK = 0,
    AUTH_SALT_STATUS_INVALID_ARGUMENT,
    AUTH_SALT_STATUS_OUTPUT_TOO_SMALL,
    AUTH_SALT_STATUS_RANDOM_SOURCE_FAILURE,
} auth_salt_status_t;

/**
 * @brief Fill a caller-provided buffer with one salt's worth of random bytes.
 *
 * @param output Destination buffer for raw random bytes.
 * @param output_size Size of @p output in bytes.
 * @return Status code describing success or the validation failure.
 */
auth_salt_status_t auth_salt_fill_bytes(uint8_t *output, size_t output_size);

/**
 * @brief Generate a new salt encoded as lowercase hexadecimal text.
 *
 * @param output Destination buffer for the encoded salt string.
 * @param output_size Size of @p output in bytes.
 * @return Status code describing success or the validation failure.
 */
auth_salt_status_t auth_salt_generate(char *output, size_t output_size);

/**
 * @brief Validate that a stored salt string matches the engine format.
 *
 * @param salt Lowercase hex salt string.
 * @return true when the string has the expected width and encoding.
 */
bool auth_salt_is_valid(const char *salt);

/**
 * @brief Convert a salt adapter status code to a stable string.
 *
 * @param status Status code returned by the adapter.
 * @return Stable string literal for logging or JSON serialization.
 */
const char *auth_salt_status_string(auth_salt_status_t status);

#endif

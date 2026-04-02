#ifndef VERIFIABLE_AUTH_PLATFORM_ENGINE_STORAGE_USER_STORE_H
#define VERIFIABLE_AUTH_PLATFORM_ENGINE_STORAGE_USER_STORE_H

#include "auth/state.h"

/**
 * @brief Stable status codes returned by the persisted user store adapter.
 */
typedef enum storage_user_store_status {
    /** The requested operation completed successfully. */
    STORAGE_USER_STORE_STATUS_OK = 0,
    /** One or more required arguments were nullptr or otherwise invalid. */
    STORAGE_USER_STORE_STATUS_INVALID_ARGUMENT,
    /** The persisted representation could not be parsed as valid auth state. */
    STORAGE_USER_STORE_STATUS_PARSE_ERROR,
    /** The underlying file operation failed. */
    STORAGE_USER_STORE_STATUS_IO_ERROR,
} storage_user_store_status_t;

/**
 * @brief Load persisted users into the in-memory auth state.
 *
 * On success the function resets `state` and replaces its user list from the
 * file contents.
 *
 * @param path Path to the persisted user store file.
 * @param state State object to populate.
 * @return Status describing success, parse failure, or file I/O failure.
 */
storage_user_store_status_t storage_user_store_load(const char *path, auth_state_t *state);

/**
 * @brief Save the in-memory user list to the persisted user store file.
 *
 * @param path Destination file path.
 * @param state State whose users should be persisted.
 * @return Status describing success or file I/O failure.
 */
storage_user_store_status_t storage_user_store_save(const char *path, const auth_state_t *state);

/**
 * @brief Convert a user store status code to a stable string.
 *
 * @param status User store status code.
 * @return Stable string literal for diagnostics and JSON serialization.
 */
const char *storage_user_store_status_string(storage_user_store_status_t status);

#endif

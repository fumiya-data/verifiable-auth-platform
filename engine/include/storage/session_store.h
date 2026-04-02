#ifndef VERIFIABLE_AUTH_PLATFORM_ENGINE_STORAGE_SESSION_STORE_H
#define VERIFIABLE_AUTH_PLATFORM_ENGINE_STORAGE_SESSION_STORE_H

#include "auth/state.h"

/**
 * @brief Stable status codes returned by the persisted session store adapter.
 */
typedef enum storage_session_store_status {
    /** The requested operation completed successfully. */
    STORAGE_SESSION_STORE_STATUS_OK = 0,
    /** One or more required arguments were nullptr or otherwise invalid. */
    STORAGE_SESSION_STORE_STATUS_INVALID_ARGUMENT,
    /** The persisted representation could not be parsed as valid session data. */
    STORAGE_SESSION_STORE_STATUS_PARSE_ERROR,
    /** The underlying file operation failed. */
    STORAGE_SESSION_STORE_STATUS_IO_ERROR,
} storage_session_store_status_t;

/**
 * @brief Load persisted session state into the in-memory auth state.
 *
 * The session file stores either an empty unauthenticated session or the login
 * ID of the authenticated user.
 *
 * @param path Path to the persisted session file.
 * @param state State object to populate.
 * @return Status describing success, parse failure, or file I/O failure.
 */
storage_session_store_status_t storage_session_store_load(const char *path, auth_state_t *state);

/**
 * @brief Save the current authenticated session to persistent storage.
 *
 * @param path Destination file path.
 * @param state State whose session should be persisted.
 * @return Status describing success or file I/O failure.
 */
storage_session_store_status_t storage_session_store_save(const char *path, const auth_state_t *state);

/**
 * @brief Convert a session store status code to a stable string.
 *
 * @param status Session store status code.
 * @return Stable string literal for diagnostics and JSON serialization.
 */
const char *storage_session_store_status_string(storage_session_store_status_t status);

#endif

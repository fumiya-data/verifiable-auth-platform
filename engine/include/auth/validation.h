#ifndef VERIFIABLE_AUTH_PLATFORM_ENGINE_AUTH_VALIDATION_H
#define VERIFIABLE_AUTH_PLATFORM_ENGINE_AUTH_VALIDATION_H

/**
 * @brief Result codes returned by input validation helpers.
 */
typedef enum auth_validation_result {
    /** Validation succeeded. */
    AUTH_VALIDATION_RESULT_OK = 0,
    /** The input pointer was nullptr. */
    AUTH_VALIDATION_RESULT_NULL,
    /** The input string was empty. */
    AUTH_VALIDATION_RESULT_EMPTY,
    /** The input string exceeded the configured maximum length. */
    AUTH_VALIDATION_RESULT_TOO_LONG,
} auth_validation_result_t;

/**
 * @brief Validate a login ID for use in the core auth functions.
 *
 * @param login_id Candidate login ID.
 * @return Validation result for the supplied login ID.
 */
auth_validation_result_t auth_validate_login_id(const char *login_id);

/**
 * @brief Validate a password for use in the core auth functions.
 *
 * @param password Candidate password string.
 * @return Validation result for the supplied password.
 */
auth_validation_result_t auth_validate_password(const char *password);

#endif

#ifndef VERIFIABLE_AUTH_PLATFORM_ENGINE_AUTH_RESULT_H
#define VERIFIABLE_AUTH_PLATFORM_ENGINE_AUTH_RESULT_H

/**
 * @brief Result codes for the register operation.
 */
typedef enum auth_register_result {
    /** The user was created successfully. */
    AUTH_REGISTER_RESULT_SUCCESS = 0,
    /** A user with the same login ID already exists. */
    AUTH_REGISTER_RESULT_DUPLICATE,
} auth_register_result_t;

/**
 * @brief Result codes for the login operation.
 */
typedef enum auth_login_result {
    /** Authentication succeeded and the session is now active. */
    AUTH_LOGIN_RESULT_SUCCESS = 0,
    /** No user with the requested login ID exists. */
    AUTH_LOGIN_RESULT_UNKNOWN_USER,
    /** The user was already locked or the current failure caused a lockout. */
    AUTH_LOGIN_RESULT_LOCKED_OUT,
    /** The password did not match and the threshold was not reached yet. */
    AUTH_LOGIN_RESULT_WRONG_PASSWORD,
    /** Another session is already active in the current state. */
    AUTH_LOGIN_RESULT_ALREADY_AUTHENTICATED,
} auth_login_result_t;

/**
 * @brief Result codes for the change_password operation.
 */
typedef enum auth_change_password_result {
    /** The password was changed and rehashed successfully. */
    AUTH_CHANGE_PASSWORD_RESULT_SUCCESS = 0,
    /** No authenticated session exists. */
    AUTH_CHANGE_PASSWORD_RESULT_UNAUTHORIZED,
    /** The provided old password did not match the current hash. */
    AUTH_CHANGE_PASSWORD_RESULT_WRONG_PASSWORD,
    /** The authenticated user record was missing from state. */
    AUTH_CHANGE_PASSWORD_RESULT_SYSTEM_ERROR,
} auth_change_password_result_t;

/**
 * @brief Result codes for the logout operation.
 */
typedef enum auth_logout_result {
    /** The session was cleared successfully. */
    AUTH_LOGOUT_RESULT_SUCCESS = 0,
} auth_logout_result_t;

#endif

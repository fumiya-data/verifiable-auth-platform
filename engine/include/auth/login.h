#ifndef VERIFIABLE_AUTH_PLATFORM_ENGINE_AUTH_LOGIN_H
#define VERIFIABLE_AUTH_PLATFORM_ENGINE_AUTH_LOGIN_H

#include "auth/result.h"
#include "auth/state.h"

/**
 * @brief Authenticate a user against the current in-memory state.
 *
 * @param state State to inspect and possibly mutate.
 * @param login_id Login ID to authenticate.
 * @param password Plaintext password to verify.
 * @return Login result code defined by the specification.
 */
auth_login_result_t auth_login(auth_state_t *state,
                               const char *login_id,
                               const char *password);

#endif

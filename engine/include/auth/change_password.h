#ifndef VERIFIABLE_AUTH_PLATFORM_ENGINE_AUTH_CHANGE_PASSWORD_H
#define VERIFIABLE_AUTH_PLATFORM_ENGINE_AUTH_CHANGE_PASSWORD_H

#include "auth/result.h"
#include "auth/state.h"

/**
 * @brief Change the password of the currently authenticated user.
 *
 * @param state State to inspect and mutate.
 * @param old_password Existing plaintext password for verification.
 * @param new_password Replacement plaintext password.
 * @return Change-password result code defined by the specification.
 */
auth_change_password_result_t auth_change_password(auth_state_t *state,
                                                   const char *old_password,
                                                   const char *new_password);

#endif

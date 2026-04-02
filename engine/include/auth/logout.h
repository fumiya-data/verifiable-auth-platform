#ifndef VERIFIABLE_AUTH_PLATFORM_ENGINE_AUTH_LOGOUT_H
#define VERIFIABLE_AUTH_PLATFORM_ENGINE_AUTH_LOGOUT_H

#include "auth/result.h"
#include "auth/state.h"

/**
 * @brief Clear the current authenticated session.
 *
 * @param state State whose authenticated session should be removed.
 * @return Logout result code defined by the specification.
 */
auth_logout_result_t auth_logout(auth_state_t *state);

#endif

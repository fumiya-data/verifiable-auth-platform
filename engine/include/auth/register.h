#ifndef VERIFIABLE_AUTH_PLATFORM_ENGINE_AUTH_REGISTER_H
#define VERIFIABLE_AUTH_PLATFORM_ENGINE_AUTH_REGISTER_H

#include "auth/result.h"
#include "auth/state.h"

/**
 * @brief Register a new user in the in-memory authentication state.
 *
 * The operation follows the specification branch set exactly: success or
 * duplicate.
 *
 * @param state State to mutate.
 * @param login_id Login ID for the new user.
 * @param password Plaintext password to hash with a fresh salt.
 * @return Register result code defined by the specification.
 */
auth_register_result_t auth_register(auth_state_t *state,
                                     const char *login_id,
                                     const char *password);

#endif

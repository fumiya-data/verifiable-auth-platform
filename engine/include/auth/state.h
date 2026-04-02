#ifndef VERIFIABLE_AUTH_PLATFORM_ENGINE_AUTH_STATE_H
#define VERIFIABLE_AUTH_PLATFORM_ENGINE_AUTH_STATE_H

#include <stdbool.h>
#include <stddef.h>

#include "auth/types.h"

/**
 * @brief Entire in-memory authentication state modeled by the core layer.
 */
typedef struct auth_state {
    /** User records currently registered in the state machine. */
    auth_user_t users[AUTH_MAX_USERS];
    /** Number of occupied elements in @p users. */
    size_t user_count;
    /** Whether the state currently contains an authenticated session. */
    bool authenticated;
    /** Login ID of the authenticated user when @p authenticated is true. */
    char authenticated_login_id[AUTH_LOGIN_ID_MAX_LENGTH + 1u];
} auth_state_t;

/**
 * @brief Initialize an empty authentication state.
 *
 * @param state State object to reset to the unauthenticated empty state.
 */
void auth_state_init(auth_state_t *state);

/**
 * @brief Return the user with the given login ID, or nullptr when missing.
 *
 * @param state State to search.
 * @param login_id Login ID to match exactly.
 * @return Matching user pointer or nullptr.
 */
const auth_user_t *auth_state_find_user(const auth_state_t *state, const char *login_id);

/**
 * @brief Return a mutable user with the given login ID, or nullptr when
 *        missing.
 *
 * @param state State to search.
 * @param login_id Login ID to match exactly.
 * @return Mutable matching user pointer or nullptr.
 */
auth_user_t *auth_state_find_user_mut(auth_state_t *state, const char *login_id);

/**
 * @brief Clear the current authenticated session.
 *
 * @param state State whose session flag and login ID should be cleared.
 */
void auth_state_clear_session(auth_state_t *state);

/**
 * @brief Mark the given login ID as authenticated.
 *
 * @param state State to update.
 * @param login_id Login ID that becomes the current authenticated user.
 */
void auth_state_set_authenticated_user(auth_state_t *state, const char *login_id);

#endif

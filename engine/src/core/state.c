#include "auth/state.h"

#include <string.h>

void auth_state_init(auth_state_t *state)
{
    if (state == nullptr) {
        return;
    }

    /* Zero-initialization maps directly to the empty unauthenticated state. */
    memset(state, 0, sizeof(*state));
}

const auth_user_t *auth_state_find_user(const auth_state_t *state, const char *login_id)
{
    if (state == nullptr || login_id == nullptr) {
        return nullptr;
    }

    for (size_t index = 0; index < state->user_count; ++index) {
        /* The current in-memory core uses a linear scan over the user array. */
        if (strcmp(state->users[index].login_id, login_id) == 0) {
            return &state->users[index];
        }
    }

    return nullptr;
}

auth_user_t *auth_state_find_user_mut(auth_state_t *state, const char *login_id)
{
    if (state == nullptr || login_id == nullptr) {
        return nullptr;
    }

    for (size_t index = 0; index < state->user_count; ++index) {
        if (strcmp(state->users[index].login_id, login_id) == 0) {
            return &state->users[index];
        }
    }

    return nullptr;
}

void auth_state_clear_session(auth_state_t *state)
{
    if (state == nullptr) {
        return;
    }

    /* Clearing both fields keeps the explicit session flag and payload aligned. */
    state->authenticated = false;
    memset(state->authenticated_login_id, 0, sizeof(state->authenticated_login_id));
}

void auth_state_set_authenticated_user(auth_state_t *state, const char *login_id)
{
    const size_t login_id_len = strlen(login_id);

    /* The session stores the authenticated login ID directly in state. */
    state->authenticated = true;
    memset(state->authenticated_login_id, 0, sizeof(state->authenticated_login_id));
    memcpy(state->authenticated_login_id, login_id, login_id_len + 1u);
}

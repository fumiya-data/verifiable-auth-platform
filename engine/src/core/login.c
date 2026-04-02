#include "auth/login.h"

#include <assert.h>
#include <string.h>

#include "crypto/hash_adapter.h"

auth_login_result_t auth_login(auth_state_t *state,
                               const char *login_id,
                               const char *password)
{
    auth_user_t *user = nullptr;

    assert(state != nullptr);
    assert(login_id != nullptr);
    assert(password != nullptr);

    if (state->authenticated) {
        return AUTH_LOGIN_RESULT_ALREADY_AUTHENTICATED;
    }

    user = auth_state_find_user_mut(state, login_id);
    if (user == nullptr) {
        return AUTH_LOGIN_RESULT_UNKNOWN_USER;
    }

    if (user->lock_state == AUTH_LOCK_STATE_LOCKED) {
        return AUTH_LOGIN_RESULT_LOCKED_OUT;
    }

    /* Failed logins are the only failure branch that may mutate user state. */
    if (!auth_hash_verify_password((const uint8_t *)password,
                                   strlen(password),
                                   (const uint8_t *)user->salt,
                                   strlen(user->salt),
                                   user->password_hash)) {
        user->failed_attempts += 1u;
        if (user->failed_attempts >= AUTH_LOCKOUT_THRESHOLD) {
            user->lock_state = AUTH_LOCK_STATE_LOCKED;
            return AUTH_LOGIN_RESULT_LOCKED_OUT;
        }

        return AUTH_LOGIN_RESULT_WRONG_PASSWORD;
    }

    /* Successful login clears the failure counter and installs the session. */
    user->failed_attempts = 0u;
    auth_state_set_authenticated_user(state, login_id);

    return AUTH_LOGIN_RESULT_SUCCESS;
}

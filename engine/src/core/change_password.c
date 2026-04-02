#include "auth/change_password.h"

#include <assert.h>
#include <string.h>

#include "crypto/hash_adapter.h"
#include "crypto/salt_adapter.h"

auth_change_password_result_t auth_change_password(auth_state_t *state,
                                                   const char *old_password,
                                                   const char *new_password)
{
    auth_user_t *user = nullptr;

    assert(state != nullptr);
    assert(old_password != nullptr);
    assert(new_password != nullptr);

    if (!state->authenticated) {
        return AUTH_CHANGE_PASSWORD_RESULT_UNAUTHORIZED;
    }

    user = auth_state_find_user_mut(state, state->authenticated_login_id);
    if (user == nullptr) {
        return AUTH_CHANGE_PASSWORD_RESULT_SYSTEM_ERROR;
    }

    if (!auth_hash_verify_password((const uint8_t *)old_password,
                                   strlen(old_password),
                                   (const uint8_t *)user->salt,
                                   strlen(user->salt),
                                   user->password_hash)) {
        return AUTH_CHANGE_PASSWORD_RESULT_WRONG_PASSWORD;
    }

    /* The spec requires both the salt and the hash to be replaced together. */
    assert(auth_salt_generate(user->salt, sizeof(user->salt)) == AUTH_SALT_STATUS_OK);

    assert(auth_hash_password((const uint8_t *)new_password,
                              strlen(new_password),
                              (const uint8_t *)user->salt,
                              strlen(user->salt),
                              user->password_hash,
                              sizeof(user->password_hash)) == AUTH_HASH_STATUS_OK);

    /* A successful password change also clears lockout-related account state. */
    user->failed_attempts = 0u;
    user->lock_state = AUTH_LOCK_STATE_ACTIVE;

    return AUTH_CHANGE_PASSWORD_RESULT_SUCCESS;
}

#include "auth/register.h"

#include <assert.h>
#include <string.h>

#include "crypto/hash_adapter.h"
#include "crypto/salt_adapter.h"

auth_register_result_t auth_register(auth_state_t *state,
                                     const char *login_id,
                                     const char *password)
{
    const auth_user_t *user = nullptr;
    auth_user_t new_user;
    const size_t login_id_len = strlen(login_id);
    const size_t password_len = strlen(password);

    assert(state != nullptr);
    assert(login_id != nullptr);
    assert(password != nullptr);
    assert(state->user_count < AUTH_MAX_USERS);

    user = auth_state_find_user(state, login_id);
    if (user != nullptr) {
        return AUTH_REGISTER_RESULT_DUPLICATE;
    }

    /* A successful register creates a fresh active account without touching the
     * current authentication session. */
    memset(&new_user, 0, sizeof(new_user));
    memcpy(new_user.login_id, login_id, login_id_len + 1u);
    new_user.failed_attempts = 0u;
    new_user.lock_state = AUTH_LOCK_STATE_ACTIVE;

    assert(auth_salt_generate(new_user.salt, sizeof(new_user.salt)) == AUTH_SALT_STATUS_OK);

    assert(auth_hash_password((const uint8_t *)password,
                              password_len,
                              (const uint8_t *)new_user.salt,
                              strlen(new_user.salt),
                              new_user.password_hash,
                              sizeof(new_user.password_hash)) == AUTH_HASH_STATUS_OK);

    /* Append-only insertion is enough while the core still uses a fixed array. */
    state->users[state->user_count] = new_user;
    state->user_count += 1u;

    return AUTH_REGISTER_RESULT_SUCCESS;
}

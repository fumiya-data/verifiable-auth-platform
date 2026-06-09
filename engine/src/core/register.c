#include "auth/register.h"

#include <assert.h>
#include <string.h>

#include "auth/validation.h"
#include "crypto/hash_adapter.h"
#include "crypto/salt_adapter.h"

auth_register_result_t auth_register(auth_state_t *state,
                                     const char *login_id,
                                     const char *password)
{
    const auth_user_t *user = nullptr;
    auth_user_t new_user;
    size_t login_id_len = 0u;
    size_t password_len = 0u;

    if (state == nullptr || login_id == nullptr || password == nullptr) {
        return AUTH_REGISTER_RESULT_SYSTEM_ERROR;
    }

    assert(state != nullptr);
    assert(login_id != nullptr);
    assert(password != nullptr);

    if (auth_validate_login_id(login_id) != AUTH_VALIDATION_RESULT_OK ||
        auth_validate_password(password) != AUTH_VALIDATION_RESULT_OK ||
        state->user_count >= AUTH_MAX_USERS) {
        return AUTH_REGISTER_RESULT_SYSTEM_ERROR;
    }

    login_id_len = strlen(login_id);
    password_len = strlen(password);

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

    if (auth_salt_generate(new_user.salt, sizeof(new_user.salt)) != AUTH_SALT_STATUS_OK) {
        return AUTH_REGISTER_RESULT_SYSTEM_ERROR;
    }

    if (auth_hash_password((const uint8_t *)password,
                           password_len,
                           (const uint8_t *)new_user.salt,
                           strlen(new_user.salt),
                           new_user.password_hash,
                           sizeof(new_user.password_hash)) != AUTH_HASH_STATUS_OK) {
        return AUTH_REGISTER_RESULT_SYSTEM_ERROR;
    }

    /* Append-only insertion is enough while the core still uses a fixed array. */
    state->users[state->user_count] = new_user;
    state->user_count += 1u;

    return AUTH_REGISTER_RESULT_SUCCESS;
}

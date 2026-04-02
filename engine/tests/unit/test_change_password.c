#include <assert.h>
#include <string.h>

#include "auth/change_password.h"
#include "auth/login.h"
#include "auth/register.h"
#include "auth/state.h"

static void test_change_password_requires_authentication(void)
{
    auth_state_t state;

    auth_state_init(&state);
    assert(auth_change_password(&state, "old", "new") ==
           AUTH_CHANGE_PASSWORD_RESULT_UNAUTHORIZED);
}

static void test_change_password_wrong_password(void)
{
    auth_state_t state;
    char original_salt[AUTH_SALT_ENCODED_LENGTH];
    char original_hash[AUTH_HASH_ENCODED_LENGTH];

    auth_state_init(&state);
    assert(auth_register(&state, "alice", "hunter2") == AUTH_REGISTER_RESULT_SUCCESS);
    assert(auth_login(&state, "alice", "hunter2") == AUTH_LOGIN_RESULT_SUCCESS);

    memcpy(original_salt, state.users[0].salt, sizeof(original_salt));
    memcpy(original_hash, state.users[0].password_hash, sizeof(original_hash));

    assert(auth_change_password(&state, "wrong", "new-secret") ==
           AUTH_CHANGE_PASSWORD_RESULT_WRONG_PASSWORD);
    assert(strcmp(state.users[0].salt, original_salt) == 0);
    assert(strcmp(state.users[0].password_hash, original_hash) == 0);
}

static void test_change_password_success(void)
{
    auth_state_t state;
    char original_salt[AUTH_SALT_ENCODED_LENGTH];
    char original_hash[AUTH_HASH_ENCODED_LENGTH];

    auth_state_init(&state);
    assert(auth_register(&state, "alice", "hunter2") == AUTH_REGISTER_RESULT_SUCCESS);
    assert(auth_login(&state, "alice", "hunter2") == AUTH_LOGIN_RESULT_SUCCESS);

    memcpy(original_salt, state.users[0].salt, sizeof(original_salt));
    memcpy(original_hash, state.users[0].password_hash, sizeof(original_hash));

    assert(auth_change_password(&state, "hunter2", "new-secret") ==
           AUTH_CHANGE_PASSWORD_RESULT_SUCCESS);
    assert(state.authenticated);
    assert(strcmp(state.authenticated_login_id, "alice") == 0);
    assert(strcmp(state.users[0].salt, original_salt) != 0);
    assert(strcmp(state.users[0].password_hash, original_hash) != 0);
    assert(state.users[0].failed_attempts == 0u);
    assert(state.users[0].lock_state == AUTH_LOCK_STATE_ACTIVE);
}

static void test_change_password_system_error_when_session_user_is_missing(void)
{
    auth_state_t state;

    auth_state_init(&state);
    state.authenticated = true;
    memcpy(state.authenticated_login_id, "ghost", sizeof("ghost"));

    assert(auth_change_password(&state, "old-password", "new-password") ==
           AUTH_CHANGE_PASSWORD_RESULT_SYSTEM_ERROR);
}

int main(void)
{
    test_change_password_requires_authentication();
    test_change_password_wrong_password();
    test_change_password_success();
    test_change_password_system_error_when_session_user_is_missing();
    return 0;
}

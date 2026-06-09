#include "test_support.h"
#include <string.h>

#include "auth/register.h"
#include "auth/state.h"
#include "crypto/salt_adapter.h"

static void test_register_success(void)
{
    auth_state_t state;

    auth_state_init(&state);

    TEST_CHECK(auth_register(&state, "alice", "hunter2") == AUTH_REGISTER_RESULT_SUCCESS);
    TEST_CHECK(state.user_count == 1u);
    TEST_CHECK(strcmp(state.users[0].login_id, "alice") == 0);
    TEST_CHECK(auth_salt_is_valid(state.users[0].salt));
    TEST_CHECK(strlen(state.users[0].password_hash) == AUTH_HASH_ENCODED_LENGTH - 1u);
    TEST_CHECK(strcmp(state.users[0].password_hash, "hunter2") != 0);
    TEST_CHECK(state.users[0].failed_attempts == 0u);
    TEST_CHECK(state.users[0].lock_state == AUTH_LOCK_STATE_ACTIVE);
    TEST_CHECK(!state.authenticated);
}

static void test_register_duplicate(void)
{
    auth_state_t state;

    auth_state_init(&state);

    TEST_CHECK(auth_register(&state, "alice", "hunter2") == AUTH_REGISTER_RESULT_SUCCESS);
    TEST_CHECK(auth_register(&state, "alice", "new-password") == AUTH_REGISTER_RESULT_DUPLICATE);
    TEST_CHECK(state.user_count == 1u);
}

static void test_register_rejects_invalid_login_id(void)
{
    auth_state_t state;
    char too_long_login_id[AUTH_LOGIN_ID_MAX_LENGTH + 2u];

    auth_state_init(&state);
    memset(too_long_login_id, 'a', sizeof(too_long_login_id) - 1u);
    too_long_login_id[sizeof(too_long_login_id) - 1u] = '\0';

    TEST_CHECK(auth_register(&state, too_long_login_id, "hunter2") ==
               AUTH_REGISTER_RESULT_SYSTEM_ERROR);
    TEST_CHECK(state.user_count == 0u);
}

static void test_register_rejects_null_arguments(void)
{
    auth_state_t state;

    auth_state_init(&state);

    TEST_CHECK(auth_register(nullptr, "alice", "hunter2") == AUTH_REGISTER_RESULT_SYSTEM_ERROR);
    TEST_CHECK(auth_register(&state, nullptr, "hunter2") == AUTH_REGISTER_RESULT_SYSTEM_ERROR);
    TEST_CHECK(auth_register(&state, "alice", nullptr) == AUTH_REGISTER_RESULT_SYSTEM_ERROR);
    TEST_CHECK(state.user_count == 0u);
}

static void test_register_rejects_full_state(void)
{
    auth_state_t state;

    auth_state_init(&state);
    state.user_count = AUTH_MAX_USERS;

    TEST_CHECK(auth_register(&state, "alice", "hunter2") ==
               AUTH_REGISTER_RESULT_SYSTEM_ERROR);
    TEST_CHECK(state.user_count == AUTH_MAX_USERS);
}

int main(void)
{
    test_register_success();
    test_register_duplicate();
    test_register_rejects_invalid_login_id();
    test_register_rejects_null_arguments();
    test_register_rejects_full_state();
    return 0;
}

#include "test_support.h"

#include "auth/login.h"
#include "auth/register.h"
#include "auth/state.h"

static void test_login_success(void)
{
    auth_state_t state;

    auth_state_init(&state);
    TEST_CHECK(auth_register(&state, "alice", "hunter2") == AUTH_REGISTER_RESULT_SUCCESS);

    TEST_CHECK(auth_login(&state, "alice", "hunter2") == AUTH_LOGIN_RESULT_SUCCESS);
    TEST_CHECK(state.authenticated);
    TEST_CHECK(state.users[0].failed_attempts == 0u);
}

static void test_login_failures_and_lockout(void)
{
    auth_state_t state;

    auth_state_init(&state);
    TEST_CHECK(auth_register(&state, "alice", "hunter2") == AUTH_REGISTER_RESULT_SUCCESS);

    TEST_CHECK(auth_login(&state, "alice", "wrong-1") == AUTH_LOGIN_RESULT_WRONG_PASSWORD);
    TEST_CHECK(state.users[0].failed_attempts == 1u);
    TEST_CHECK(auth_login(&state, "alice", "wrong-2") == AUTH_LOGIN_RESULT_WRONG_PASSWORD);
    TEST_CHECK(state.users[0].failed_attempts == 2u);
    TEST_CHECK(auth_login(&state, "alice", "wrong-3") == AUTH_LOGIN_RESULT_LOCKED_OUT);
    TEST_CHECK(state.users[0].failed_attempts == 3u);
    TEST_CHECK(state.users[0].lock_state == AUTH_LOCK_STATE_LOCKED);
}

static void test_login_already_authenticated_and_unknown_user(void)
{
    auth_state_t state;

    auth_state_init(&state);
    TEST_CHECK(auth_register(&state, "alice", "hunter2") == AUTH_REGISTER_RESULT_SUCCESS);
    TEST_CHECK(auth_login(&state, "nobody", "hunter2") == AUTH_LOGIN_RESULT_UNKNOWN_USER);
    TEST_CHECK(auth_login(&state, "alice", "hunter2") == AUTH_LOGIN_RESULT_SUCCESS);
    TEST_CHECK(auth_login(&state, "alice", "hunter2") == AUTH_LOGIN_RESULT_ALREADY_AUTHENTICATED);
}

int main(void)
{
    test_login_success();
    test_login_failures_and_lockout();
    test_login_already_authenticated_and_unknown_user();
    return 0;
}

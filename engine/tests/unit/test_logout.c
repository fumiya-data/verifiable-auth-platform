#include "test_support.h"

#include "auth/login.h"
#include "auth/logout.h"
#include "auth/register.h"
#include "auth/state.h"

static void test_logout_clears_session(void)
{
    auth_state_t state;

    auth_state_init(&state);
    TEST_CHECK(auth_register(&state, "alice", "hunter2") == AUTH_REGISTER_RESULT_SUCCESS);
    TEST_CHECK(auth_login(&state, "alice", "hunter2") == AUTH_LOGIN_RESULT_SUCCESS);

    TEST_CHECK(auth_logout(&state) == AUTH_LOGOUT_RESULT_SUCCESS);
    TEST_CHECK(!state.authenticated);
    TEST_CHECK(state.user_count == 1u);
}

int main(void)
{
    test_logout_clears_session();
    return 0;
}

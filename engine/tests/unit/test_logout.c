#include <assert.h>

#include "auth/login.h"
#include "auth/logout.h"
#include "auth/register.h"
#include "auth/state.h"

static void test_logout_clears_session(void)
{
    auth_state_t state;

    auth_state_init(&state);
    assert(auth_register(&state, "alice", "hunter2") == AUTH_REGISTER_RESULT_SUCCESS);
    assert(auth_login(&state, "alice", "hunter2") == AUTH_LOGIN_RESULT_SUCCESS);

    assert(auth_logout(&state) == AUTH_LOGOUT_RESULT_SUCCESS);
    assert(!state.authenticated);
    assert(state.user_count == 1u);
}

int main(void)
{
    test_logout_clears_session();
    return 0;
}

#include <assert.h>
#include <string.h>

#include "auth/register.h"
#include "auth/state.h"
#include "crypto/salt_adapter.h"

static void test_register_success(void)
{
    auth_state_t state;

    auth_state_init(&state);

    assert(auth_register(&state, "alice", "hunter2") == AUTH_REGISTER_RESULT_SUCCESS);
    assert(state.user_count == 1u);
    assert(strcmp(state.users[0].login_id, "alice") == 0);
    assert(auth_salt_is_valid(state.users[0].salt));
    assert(strcmp(state.users[0].password_hash, "hunter2") != 0);
    assert(state.users[0].failed_attempts == 0u);
    assert(state.users[0].lock_state == AUTH_LOCK_STATE_ACTIVE);
    assert(!state.authenticated);
}

static void test_register_duplicate(void)
{
    auth_state_t state;

    auth_state_init(&state);

    assert(auth_register(&state, "alice", "hunter2") == AUTH_REGISTER_RESULT_SUCCESS);
    assert(auth_register(&state, "alice", "new-password") == AUTH_REGISTER_RESULT_DUPLICATE);
    assert(state.user_count == 1u);
}

int main(void)
{
    test_register_success();
    test_register_duplicate();
    return 0;
}

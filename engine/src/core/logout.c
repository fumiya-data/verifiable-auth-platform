#include "auth/logout.h"

auth_logout_result_t auth_logout(auth_state_t *state)
{
    /* Logout only touches the session; user records remain unchanged. */
    auth_state_clear_session(state);
    return AUTH_LOGOUT_RESULT_SUCCESS;
}

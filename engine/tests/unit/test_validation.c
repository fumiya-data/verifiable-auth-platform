#include <assert.h>
#include <string.h>

#include "auth/validation.h"
#include "auth/types.h"

static void test_login_id_validation(void)
{
    char too_long[AUTH_LOGIN_ID_MAX_LENGTH + 2u];

    memset(too_long, 'a', sizeof(too_long) - 1u);
    too_long[sizeof(too_long) - 1u] = '\0';

    assert(auth_validate_login_id(nullptr) == AUTH_VALIDATION_RESULT_NULL);
    assert(auth_validate_login_id("") == AUTH_VALIDATION_RESULT_EMPTY);
    assert(auth_validate_login_id("alice") == AUTH_VALIDATION_RESULT_OK);
    assert(auth_validate_login_id(too_long) == AUTH_VALIDATION_RESULT_TOO_LONG);
}

static void test_password_validation(void)
{
    char too_long[AUTH_PASSWORD_MAX_LENGTH + 2u];

    memset(too_long, 'p', sizeof(too_long) - 1u);
    too_long[sizeof(too_long) - 1u] = '\0';

    assert(auth_validate_password(nullptr) == AUTH_VALIDATION_RESULT_NULL);
    assert(auth_validate_password("") == AUTH_VALIDATION_RESULT_EMPTY);
    assert(auth_validate_password("correct horse battery staple") == AUTH_VALIDATION_RESULT_OK);
    assert(auth_validate_password(too_long) == AUTH_VALIDATION_RESULT_TOO_LONG);
}

int main(void)
{
    test_login_id_validation();
    test_password_validation();
    return 0;
}

#include "auth/validation.h"

#include <string.h>

#include "auth/types.h"

auth_validation_result_t auth_validate_login_id(const char *login_id)
{
    const size_t length = login_id == nullptr ? 0u : strlen(login_id);

    /* Validation stays separate from the state transitions so tests can use it
     * independently without changing the spec-defined result branches. */
    if (login_id == nullptr) {
        return AUTH_VALIDATION_RESULT_NULL;
    }

    if (length == 0u) {
        return AUTH_VALIDATION_RESULT_EMPTY;
    }

    if (length > AUTH_LOGIN_ID_MAX_LENGTH) {
        return AUTH_VALIDATION_RESULT_TOO_LONG;
    }

    return AUTH_VALIDATION_RESULT_OK;
}

auth_validation_result_t auth_validate_password(const char *password)
{
    const size_t length = password == nullptr ? 0u : strlen(password);

    if (password == nullptr) {
        return AUTH_VALIDATION_RESULT_NULL;
    }

    if (length == 0u) {
        return AUTH_VALIDATION_RESULT_EMPTY;
    }

    if (length > AUTH_PASSWORD_MAX_LENGTH) {
        return AUTH_VALIDATION_RESULT_TOO_LONG;
    }

    return AUTH_VALIDATION_RESULT_OK;
}

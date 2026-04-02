#include "storage/session_store.h"

#include <string.h>

#include "util/file_io.h"

storage_session_store_status_t storage_session_store_load(const char *path, auth_state_t *state)
{
    char session_buffer[AUTH_LOGIN_ID_MAX_LENGTH + 4u];
    util_file_io_status_t status;

    if (path == nullptr || state == nullptr) {
        return STORAGE_SESSION_STORE_STATUS_INVALID_ARGUMENT;
    }

    status = util_file_io_read_text(path, session_buffer, sizeof(session_buffer));
    if (status == UTIL_FILE_IO_STATUS_NOT_FOUND) {
        auth_state_clear_session(state);
        return STORAGE_SESSION_STORE_STATUS_OK;
    }

    if (status != UTIL_FILE_IO_STATUS_OK) {
        return STORAGE_SESSION_STORE_STATUS_IO_ERROR;
    }

    for (size_t index = 0; session_buffer[index] != '\0'; ++index) {
        if (session_buffer[index] == '\n' || session_buffer[index] == '\r') {
            session_buffer[index] = '\0';
            break;
        }
    }

    if (session_buffer[0] == '\0') {
        auth_state_clear_session(state);
        return STORAGE_SESSION_STORE_STATUS_OK;
    }

    if (auth_state_find_user(state, session_buffer) == nullptr) {
        auth_state_clear_session(state);
        return STORAGE_SESSION_STORE_STATUS_PARSE_ERROR;
    }

    auth_state_set_authenticated_user(state, session_buffer);
    return STORAGE_SESSION_STORE_STATUS_OK;
}

storage_session_store_status_t storage_session_store_save(const char *path, const auth_state_t *state)
{
    const util_file_io_status_t status =
        path == nullptr || state == nullptr
            ? UTIL_FILE_IO_STATUS_IO_ERROR
            : util_file_io_write_text(path, state->authenticated ? state->authenticated_login_id : "");

    if (path == nullptr || state == nullptr) {
        return STORAGE_SESSION_STORE_STATUS_INVALID_ARGUMENT;
    }

    return status == UTIL_FILE_IO_STATUS_OK ? STORAGE_SESSION_STORE_STATUS_OK
                                            : STORAGE_SESSION_STORE_STATUS_IO_ERROR;
}

const char *storage_session_store_status_string(storage_session_store_status_t status)
{
    switch (status) {
    case STORAGE_SESSION_STORE_STATUS_OK:
        return "ok";
    case STORAGE_SESSION_STORE_STATUS_INVALID_ARGUMENT:
        return "invalid_argument";
    case STORAGE_SESSION_STORE_STATUS_PARSE_ERROR:
        return "parse_error";
    case STORAGE_SESSION_STORE_STATUS_IO_ERROR:
        return "io_error";
    default:
        return "unknown_session_store_status";
    }
}

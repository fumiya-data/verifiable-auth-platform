#include "storage/user_store.h"

#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "crypto/salt_adapter.h"
#include "util/file_io.h"
#include "util/parse.h"
#include "util/string_view.h"

#define STORAGE_USER_STORE_LINE_BUFFER 512u

static bool storage_user_store_is_lower_hex_view(util_string_view_t view,
                                                 size_t expected_length)
{
    if (view.length != expected_length) {
        return false;
    }

    for (size_t index = 0; index < view.length; ++index) {
        const char ch = view.data[index];
        const bool is_digit = ch >= '0' && ch <= '9';
        const bool is_lower_hex = ch >= 'a' && ch <= 'f';

        if (!is_digit && !is_lower_hex) {
            return false;
        }
    }

    return true;
}

static bool storage_user_store_is_record_well_formed(const auth_user_t *user)
{
    /* The file format is concrete, but it still has to preserve the same core
     * invariants as the in-memory state machine. */
    if (!auth_salt_is_valid(user->salt)) {
        return false;
    }

    if (strlen(user->password_hash) != AUTH_HASH_ENCODED_LENGTH - 1u) {
        return false;
    }

    if (!storage_user_store_is_lower_hex_view(
            (util_string_view_t){user->password_hash, strlen(user->password_hash)},
            AUTH_HASH_ENCODED_LENGTH - 1u)) {
        return false;
    }

    if (user->failed_attempts >= AUTH_LOCKOUT_THRESHOLD &&
        user->lock_state != AUTH_LOCK_STATE_LOCKED) {
        return false;
    }

    return true;
}

static bool storage_user_store_parse_lock_state(util_string_view_t view, auth_lock_state_t *lock_state)
{
    if (util_string_view_equal_cstr(view, "active")) {
        *lock_state = AUTH_LOCK_STATE_ACTIVE;
        return true;
    }

    if (util_string_view_equal_cstr(view, "locked")) {
        *lock_state = AUTH_LOCK_STATE_LOCKED;
        return true;
    }

    return false;
}

storage_user_store_status_t storage_user_store_load(const char *path, auth_state_t *state)
{
    FILE *stream = nullptr;
    char line[STORAGE_USER_STORE_LINE_BUFFER];

    if (path == nullptr || state == nullptr) {
        return STORAGE_USER_STORE_STATUS_INVALID_ARGUMENT;
    }

    auth_state_init(state);

    stream = fopen(path, "rb");
    if (stream == nullptr) {
        return errno == ENOENT ? STORAGE_USER_STORE_STATUS_OK
                               : STORAGE_USER_STORE_STATUS_IO_ERROR;
    }

    while (fgets(line, sizeof(line), stream) != nullptr) {
        util_string_view_t fields[5];
        util_string_view_t remainder = util_string_view_trim_line_endings(util_string_view_from_cstr(line));
        auth_user_t *user = nullptr;

        if (remainder.length == 0u) {
            continue;
        }

        if (state->user_count >= AUTH_MAX_USERS) {
            fclose(stream);
            return STORAGE_USER_STORE_STATUS_PARSE_ERROR;
        }

        for (size_t index = 0; index < 4u; ++index) {
            if (!util_string_view_split_once(remainder, '\t', &fields[index], &remainder)) {
                fclose(stream);
                return STORAGE_USER_STORE_STATUS_PARSE_ERROR;
            }
        }
        fields[4] = remainder;

        user = &state->users[state->user_count];
        memset(user, 0, sizeof(*user));

        if (!util_string_view_copy(fields[0], user->login_id, sizeof(user->login_id)) ||
            !util_string_view_copy(fields[1], user->salt, sizeof(user->salt)) ||
            !util_string_view_copy(fields[2], user->password_hash, sizeof(user->password_hash)) ||
            !util_parse_u32(fields[3], &user->failed_attempts) ||
            !storage_user_store_parse_lock_state(fields[4], &user->lock_state)) {
            fclose(stream);
            return STORAGE_USER_STORE_STATUS_PARSE_ERROR;
        }

        if (auth_state_find_user(state, user->login_id) != nullptr ||
            !storage_user_store_is_record_well_formed(user)) {
            fclose(stream);
            return STORAGE_USER_STORE_STATUS_PARSE_ERROR;
        }

        state->user_count += 1u;
    }

    if (ferror(stream) != 0) {
        fclose(stream);
        return STORAGE_USER_STORE_STATUS_IO_ERROR;
    }

    fclose(stream);
    return STORAGE_USER_STORE_STATUS_OK;
}

storage_user_store_status_t storage_user_store_save(const char *path, const auth_state_t *state)
{
    FILE *stream = nullptr;

    if (path == nullptr || state == nullptr) {
        return STORAGE_USER_STORE_STATUS_INVALID_ARGUMENT;
    }

    stream = fopen(path, "wb");
    if (stream == nullptr) {
        return STORAGE_USER_STORE_STATUS_IO_ERROR;
    }

    for (size_t index = 0; index < state->user_count; ++index) {
        const auth_user_t *user = &state->users[index];
        const char *lock_state = user->lock_state == AUTH_LOCK_STATE_LOCKED ? "locked" : "active";

        if (fprintf(stream,
                    "%s\t%s\t%s\t%u\t%s\n",
                    user->login_id,
                    user->salt,
                    user->password_hash,
                    user->failed_attempts,
                    lock_state) < 0) {
            fclose(stream);
            return STORAGE_USER_STORE_STATUS_IO_ERROR;
        }
    }

    if (fclose(stream) != 0) {
        return STORAGE_USER_STORE_STATUS_IO_ERROR;
    }

    return STORAGE_USER_STORE_STATUS_OK;
}

const char *storage_user_store_status_string(storage_user_store_status_t status)
{
    switch (status) {
    case STORAGE_USER_STORE_STATUS_OK:
        return "ok";
    case STORAGE_USER_STORE_STATUS_INVALID_ARGUMENT:
        return "invalid_argument";
    case STORAGE_USER_STORE_STATUS_PARSE_ERROR:
        return "parse_error";
    case STORAGE_USER_STORE_STATUS_IO_ERROR:
        return "io_error";
    default:
        return "unknown_user_store_status";
    }
}

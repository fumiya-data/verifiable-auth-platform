#include "storage/audit_log.h"

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "util/file_io.h"
#include "util/string_view.h"

#define STORAGE_AUDIT_LINE_BUFFER 512u

static bool storage_audit_log_format_timestamp(char *output, size_t output_size)
{
    const time_t now = time(nullptr);
    const struct tm *current_tm = gmtime(&now);

    if (current_tm == nullptr) {
        return false;
    }

    return strftime(output, output_size, "%Y-%m-%dT%H:%M:%SZ", current_tm) != 0u;
}

static bool storage_audit_log_parse_event_type(util_string_view_t view,
                                               storage_audit_event_type_t *event_type)
{
    if (util_string_view_equal_cstr(view, "Register")) {
        *event_type = STORAGE_AUDIT_EVENT_TYPE_REGISTER;
        return true;
    }

    if (util_string_view_equal_cstr(view, "LoginSuccess")) {
        *event_type = STORAGE_AUDIT_EVENT_TYPE_LOGIN_SUCCESS;
        return true;
    }

    if (util_string_view_equal_cstr(view, "LoginFailure")) {
        *event_type = STORAGE_AUDIT_EVENT_TYPE_LOGIN_FAILURE;
        return true;
    }

    if (util_string_view_equal_cstr(view, "Lock")) {
        *event_type = STORAGE_AUDIT_EVENT_TYPE_LOCK;
        return true;
    }

    if (util_string_view_equal_cstr(view, "PasswordChange")) {
        *event_type = STORAGE_AUDIT_EVENT_TYPE_PASSWORD_CHANGE;
        return true;
    }

    if (util_string_view_equal_cstr(view, "Logout")) {
        *event_type = STORAGE_AUDIT_EVENT_TYPE_LOGOUT;
        return true;
    }

    return false;
}

static bool storage_audit_log_counts_as_login_failure(const storage_audit_event_t *event)
{
    /* The spec records already-authenticated login attempts as LoginFailure for
     * audit traceability, but excludes them from the derived failure metric. */
    if (event->event_type == STORAGE_AUDIT_EVENT_TYPE_LOCK) {
        return true;
    }

    if (event->event_type != STORAGE_AUDIT_EVENT_TYPE_LOGIN_FAILURE) {
        return false;
    }

    return strcmp(event->result, "already_authenticated") != 0;
}

storage_audit_log_status_t storage_audit_log_append(const char *path,
                                                    storage_audit_event_type_t event_type,
                                                    const char *login_id,
                                                    const char *result)
{
    char timestamp[STORAGE_AUDIT_TIMESTAMP_LENGTH];
    char line[256];
    int line_length = 0;

    if (path == nullptr || login_id == nullptr || result == nullptr) {
        return STORAGE_AUDIT_LOG_STATUS_INVALID_ARGUMENT;
    }

    if (!storage_audit_log_format_timestamp(timestamp, sizeof(timestamp))) {
        return STORAGE_AUDIT_LOG_STATUS_IO_ERROR;
    }

    line_length = snprintf(line,
                           sizeof(line),
                           "%s\t%s\t%s\t%s\n",
                           timestamp,
                           storage_audit_event_type_string(event_type),
                           login_id,
                           result);
    if (line_length < 0 || (size_t)line_length >= sizeof(line)) {
        return STORAGE_AUDIT_LOG_STATUS_IO_ERROR;
    }

    return util_file_io_append_text(path, line) == UTIL_FILE_IO_STATUS_OK
               ? STORAGE_AUDIT_LOG_STATUS_OK
               : STORAGE_AUDIT_LOG_STATUS_IO_ERROR;
}

storage_audit_log_status_t storage_audit_log_load(const char *path, storage_audit_log_t *log)
{
    FILE *stream = nullptr;
    char line[STORAGE_AUDIT_LINE_BUFFER];

    if (path == nullptr || log == nullptr) {
        return STORAGE_AUDIT_LOG_STATUS_INVALID_ARGUMENT;
    }

    memset(log, 0, sizeof(*log));

    stream = fopen(path, "rb");
    if (stream == nullptr) {
        return errno == ENOENT ? STORAGE_AUDIT_LOG_STATUS_OK
                               : STORAGE_AUDIT_LOG_STATUS_IO_ERROR;
    }

    while (fgets(line, sizeof(line), stream) != nullptr) {
        util_string_view_t fields[4];
        util_string_view_t remainder = util_string_view_trim_line_endings(util_string_view_from_cstr(line));
        storage_audit_event_t *event = nullptr;

        if (remainder.length == 0u) {
            continue;
        }

        if (log->event_count >= STORAGE_AUDIT_MAX_EVENTS) {
            fclose(stream);
            return STORAGE_AUDIT_LOG_STATUS_PARSE_ERROR;
        }

        for (size_t index = 0; index < 3u; ++index) {
            if (!util_string_view_split_once(remainder, '\t', &fields[index], &remainder)) {
                fclose(stream);
                return STORAGE_AUDIT_LOG_STATUS_PARSE_ERROR;
            }
        }
        fields[3] = remainder;

        event = &log->events[log->event_count];
        memset(event, 0, sizeof(*event));

        if (!util_string_view_copy(fields[0], event->timestamp, sizeof(event->timestamp)) ||
            !storage_audit_log_parse_event_type(fields[1], &event->event_type) ||
            !util_string_view_copy(fields[2], event->login_id, sizeof(event->login_id)) ||
            !util_string_view_copy(fields[3], event->result, sizeof(event->result))) {
            fclose(stream);
            return STORAGE_AUDIT_LOG_STATUS_PARSE_ERROR;
        }

        log->event_count += 1u;
    }

    if (ferror(stream) != 0) {
        fclose(stream);
        return STORAGE_AUDIT_LOG_STATUS_IO_ERROR;
    }

    fclose(stream);
    return STORAGE_AUDIT_LOG_STATUS_OK;
}

void storage_audit_log_compute_metrics(const storage_audit_log_t *log, storage_metrics_t *metrics)
{
    if (metrics == nullptr) {
        return;
    }

    memset(metrics, 0, sizeof(*metrics));
    if (log == nullptr) {
        return;
    }

    for (size_t index = 0; index < log->event_count; ++index) {
        const storage_audit_event_t *event = &log->events[index];

        if (event->event_type == STORAGE_AUDIT_EVENT_TYPE_LOGIN_SUCCESS) {
            metrics->login_success_count += 1u;
        }

        if (storage_audit_log_counts_as_login_failure(event)) {
            metrics->login_failure_count += 1u;
        }

        if (event->event_type == STORAGE_AUDIT_EVENT_TYPE_LOCK) {
            metrics->lockout_count += 1u;
        }
    }
}

const char *storage_audit_event_type_string(storage_audit_event_type_t event_type)
{
    switch (event_type) {
    case STORAGE_AUDIT_EVENT_TYPE_REGISTER:
        return "Register";
    case STORAGE_AUDIT_EVENT_TYPE_LOGIN_SUCCESS:
        return "LoginSuccess";
    case STORAGE_AUDIT_EVENT_TYPE_LOGIN_FAILURE:
        return "LoginFailure";
    case STORAGE_AUDIT_EVENT_TYPE_LOCK:
        return "Lock";
    case STORAGE_AUDIT_EVENT_TYPE_PASSWORD_CHANGE:
        return "PasswordChange";
    case STORAGE_AUDIT_EVENT_TYPE_LOGOUT:
        return "Logout";
    default:
        return "Unknown";
    }
}

const char *storage_audit_log_status_string(storage_audit_log_status_t status)
{
    switch (status) {
    case STORAGE_AUDIT_LOG_STATUS_OK:
        return "ok";
    case STORAGE_AUDIT_LOG_STATUS_INVALID_ARGUMENT:
        return "invalid_argument";
    case STORAGE_AUDIT_LOG_STATUS_PARSE_ERROR:
        return "parse_error";
    case STORAGE_AUDIT_LOG_STATUS_IO_ERROR:
        return "io_error";
    default:
        return "unknown_audit_log_status";
    }
}

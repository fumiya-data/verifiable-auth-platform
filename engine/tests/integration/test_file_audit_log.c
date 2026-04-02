#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "storage/audit_log.h"
#include "util/file_io.h"

static void cleanup_file(const char *path)
{
    (void)remove(path);
}

int main(void)
{
    const char *path = ".scratch/it_audit_log.txt";
    storage_audit_log_t log;
    storage_metrics_t metrics;

    assert(util_file_io_ensure_directory(".scratch") == UTIL_FILE_IO_STATUS_OK);
    cleanup_file(path);

    assert(storage_audit_log_append(path,
                                    STORAGE_AUDIT_EVENT_TYPE_REGISTER,
                                    "alice",
                                    "success") == STORAGE_AUDIT_LOG_STATUS_OK);
    assert(storage_audit_log_append(path,
                                    STORAGE_AUDIT_EVENT_TYPE_LOGIN_SUCCESS,
                                    "alice",
                                    "success") == STORAGE_AUDIT_LOG_STATUS_OK);
    assert(storage_audit_log_append(path,
                                    STORAGE_AUDIT_EVENT_TYPE_LOGIN_FAILURE,
                                    "alice",
                                    "wrong_password") == STORAGE_AUDIT_LOG_STATUS_OK);
    assert(storage_audit_log_append(path,
                                    STORAGE_AUDIT_EVENT_TYPE_LOGIN_FAILURE,
                                    "alice",
                                    "already_authenticated") == STORAGE_AUDIT_LOG_STATUS_OK);
    assert(storage_audit_log_append(path,
                                    STORAGE_AUDIT_EVENT_TYPE_LOCK,
                                    "alice",
                                    "locked_out") == STORAGE_AUDIT_LOG_STATUS_OK);

    assert(storage_audit_log_load(path, &log) == STORAGE_AUDIT_LOG_STATUS_OK);
    assert(log.event_count == 5u);
    assert(log.events[0].event_type == STORAGE_AUDIT_EVENT_TYPE_REGISTER);
    assert(strcmp(log.events[1].result, "success") == 0);
    assert(strcmp(log.events[2].result, "wrong_password") == 0);
    assert(strcmp(log.events[3].result, "already_authenticated") == 0);
    assert(log.events[4].event_type == STORAGE_AUDIT_EVENT_TYPE_LOCK);

    storage_audit_log_compute_metrics(&log, &metrics);
    assert(metrics.login_success_count == 1u);
    assert(metrics.login_failure_count == 2u);
    assert(metrics.lockout_count == 1u);

    cleanup_file(path);
    return 0;
}

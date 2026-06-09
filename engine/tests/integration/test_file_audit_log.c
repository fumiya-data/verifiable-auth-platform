#include "test_support.h"
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
    char oversized_login_id[256];

    TEST_CHECK(util_file_io_ensure_directory(".scratch") == UTIL_FILE_IO_STATUS_OK);
    cleanup_file(path);

    TEST_CHECK(storage_audit_log_append(path,
                                    STORAGE_AUDIT_EVENT_TYPE_REGISTER,
                                    "alice",
                                    "success") == STORAGE_AUDIT_LOG_STATUS_OK);
    TEST_CHECK(storage_audit_log_append(path,
                                    STORAGE_AUDIT_EVENT_TYPE_LOGIN_SUCCESS,
                                    "alice",
                                    "success") == STORAGE_AUDIT_LOG_STATUS_OK);
    TEST_CHECK(storage_audit_log_append(path,
                                    STORAGE_AUDIT_EVENT_TYPE_LOGIN_FAILURE,
                                    "alice",
                                    "wrong_password") == STORAGE_AUDIT_LOG_STATUS_OK);
    TEST_CHECK(storage_audit_log_append(path,
                                    STORAGE_AUDIT_EVENT_TYPE_LOGIN_FAILURE,
                                    "alice",
                                    "already_authenticated") == STORAGE_AUDIT_LOG_STATUS_OK);
    TEST_CHECK(storage_audit_log_append(path,
                                    STORAGE_AUDIT_EVENT_TYPE_LOCK,
                                    "alice",
                                    "locked_out") == STORAGE_AUDIT_LOG_STATUS_OK);

    memset(oversized_login_id, 'a', sizeof(oversized_login_id) - 1u);
    oversized_login_id[sizeof(oversized_login_id) - 1u] = '\0';
    TEST_CHECK(storage_audit_log_append(path,
                                        STORAGE_AUDIT_EVENT_TYPE_LOGIN_FAILURE,
                                        oversized_login_id,
                                        "unknown_user") == STORAGE_AUDIT_LOG_STATUS_IO_ERROR);

    TEST_CHECK(storage_audit_log_load(path, &log) == STORAGE_AUDIT_LOG_STATUS_OK);
    TEST_CHECK(log.event_count == 5u);
    TEST_CHECK(log.events[0].event_type == STORAGE_AUDIT_EVENT_TYPE_REGISTER);
    TEST_CHECK(strcmp(log.events[1].result, "success") == 0);
    TEST_CHECK(strcmp(log.events[2].result, "wrong_password") == 0);
    TEST_CHECK(strcmp(log.events[3].result, "already_authenticated") == 0);
    TEST_CHECK(log.events[4].event_type == STORAGE_AUDIT_EVENT_TYPE_LOCK);

    storage_audit_log_compute_metrics(&log, &metrics);
    TEST_CHECK(metrics.login_success_count == 1u);
    TEST_CHECK(metrics.login_failure_count == 2u);
    TEST_CHECK(metrics.lockout_count == 1u);

    cleanup_file(path);
    return 0;
}

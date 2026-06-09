#include "cli_test_support.h"
#include <string.h>

#include "util/file_io.h"

static void cleanup_path(const char *path)
{
    (void)remove(path);
}

int main(void)
{
    const char *data_dir = ".scratch/it_cli_show_audit_data";
    const char *users_path = ".scratch/it_cli_show_audit_data/users.tsv";
    const char *session_path = ".scratch/it_cli_show_audit_data/session.txt";
    const char *audit_path = ".scratch/it_cli_show_audit_data/audit.log";
    char output[2048];
    char *register_argv[] = {
        "engine_cli",
        "register",
        "--data-dir", ".scratch/it_cli_show_audit_data",
        "--login-id", "alice",
        "--password-stdin",
    };
    char *show_audit_argv[] = {
        "engine_cli",
        "show-audit",
        "--data-dir", ".scratch/it_cli_show_audit_data",
    };

    TEST_CHECK(util_file_io_ensure_directory(".scratch") == UTIL_FILE_IO_STATUS_OK);
    cleanup_path(users_path);
    cleanup_path(session_path);
    cleanup_path(audit_path);
    TEST_CHECK(util_file_io_ensure_directory(data_dir) == UTIL_FILE_IO_STATUS_OK);

    TEST_CHECK(test_cli_run_command(7, register_argv, "hunter2\n", output, sizeof(output)) == 0);
    TEST_CHECK(test_cli_run_command(4, show_audit_argv, "", output, sizeof(output)) == 0);
    TEST_CHECK(strstr(output, "\"ok\":true") != nullptr);
    TEST_CHECK(strstr(output, "\"events\":[") != nullptr);
    TEST_CHECK(strstr(output, "\"event_type\":\"Register\"") != nullptr);
    TEST_CHECK(strstr(output, "\"login_id\":\"alice\"") != nullptr);
    TEST_CHECK(strstr(output, "\"result\":\"success\"") != nullptr);

    cleanup_path(users_path);
    cleanup_path(session_path);
    cleanup_path(audit_path);
    return 0;
}

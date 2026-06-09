#include "cli_test_support.h"
#include <string.h>

#include "util/file_io.h"

static void cleanup_path(const char *path)
{
    (void)remove(path);
}

int main(void)
{
    const char *data_dir = ".scratch/it_cli_login_data";
    const char *users_path = ".scratch/it_cli_login_data/users.tsv";
    const char *session_path = ".scratch/it_cli_login_data/session.txt";
    const char *audit_path = ".scratch/it_cli_login_data/audit.log";
    char output[512];
    char session_file[128];
    char *register_argv[] = {
        "engine_cli",
        "register",
        "--data-dir", ".scratch/it_cli_login_data",
        "--login-id", "alice",
        "--password-stdin",
    };
    char *login_argv[] = {
        "engine_cli",
        "login",
        "--data-dir", ".scratch/it_cli_login_data",
        "--login-id", "alice",
        "--password-stdin",
    };

    TEST_CHECK(util_file_io_ensure_directory(".scratch") == UTIL_FILE_IO_STATUS_OK);
    cleanup_path(users_path);
    cleanup_path(session_path);
    cleanup_path(audit_path);
    TEST_CHECK(util_file_io_ensure_directory(data_dir) == UTIL_FILE_IO_STATUS_OK);

    TEST_CHECK(test_cli_run_command(7, register_argv, "hunter2\n", output, sizeof(output)) == 0);
    TEST_CHECK(test_cli_run_command(7, login_argv, "hunter2\n", output, sizeof(output)) == 0);
    TEST_CHECK(strstr(output, "\"result\":\"success\"") != nullptr);
    TEST_CHECK(util_file_io_read_text(session_path, session_file, sizeof(session_file)) == UTIL_FILE_IO_STATUS_OK);
    TEST_CHECK(strstr(session_file, "alice") != nullptr);

    cleanup_path(users_path);
    cleanup_path(session_path);
    cleanup_path(audit_path);
    return 0;
}

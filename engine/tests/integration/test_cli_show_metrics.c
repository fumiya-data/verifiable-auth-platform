#include "cli_test_support.h"
#include <string.h>

#include "util/file_io.h"

static void cleanup_path(const char *path)
{
    (void)remove(path);
}

int main(void)
{
    const char *data_dir = ".scratch/it_cli_show_metrics_data";
    const char *users_path = ".scratch/it_cli_show_metrics_data/users.tsv";
    const char *session_path = ".scratch/it_cli_show_metrics_data/session.txt";
    const char *audit_path = ".scratch/it_cli_show_metrics_data/audit.log";
    char output[2048];
    char *register_argv[] = {
        "engine_cli",
        "register",
        "--data-dir", ".scratch/it_cli_show_metrics_data",
        "--login-id", "alice",
        "--password-stdin",
    };
    char *login_argv[] = {
        "engine_cli",
        "login",
        "--data-dir", ".scratch/it_cli_show_metrics_data",
        "--login-id", "alice",
        "--password-stdin",
    };
    char *login_again_argv[] = {
        "engine_cli",
        "login",
        "--data-dir", ".scratch/it_cli_show_metrics_data",
        "--login-id", "alice",
        "--password-stdin",
    };
    char *logout_argv[] = {
        "engine_cli",
        "logout",
        "--data-dir", ".scratch/it_cli_show_metrics_data",
    };
    char *wrong_password_argv[] = {
        "engine_cli",
        "login",
        "--data-dir", ".scratch/it_cli_show_metrics_data",
        "--login-id", "alice",
        "--password-stdin",
    };
    char *show_metrics_argv[] = {
        "engine_cli",
        "show-metrics",
        "--data-dir", ".scratch/it_cli_show_metrics_data",
    };

    TEST_CHECK(util_file_io_ensure_directory(".scratch") == UTIL_FILE_IO_STATUS_OK);
    cleanup_path(users_path);
    cleanup_path(session_path);
    cleanup_path(audit_path);
    TEST_CHECK(util_file_io_ensure_directory(data_dir) == UTIL_FILE_IO_STATUS_OK);

    TEST_CHECK(test_cli_run_command(7, register_argv, "hunter2\n", output, sizeof(output)) == 0);
    TEST_CHECK(test_cli_run_command(7, login_argv, "hunter2\n", output, sizeof(output)) == 0);
    TEST_CHECK(test_cli_run_command(7, login_again_argv, "hunter2\n", output, sizeof(output)) == 0);
    TEST_CHECK(strstr(output, "\"result\":\"already_authenticated\"") != nullptr);
    TEST_CHECK(test_cli_run_command(4, logout_argv, "", output, sizeof(output)) == 0);
    TEST_CHECK(test_cli_run_command(7, wrong_password_argv, "wrong-password\n", output, sizeof(output)) == 0);
    TEST_CHECK(strstr(output, "\"result\":\"wrong_password\"") != nullptr);
    TEST_CHECK(test_cli_run_command(4, show_metrics_argv, "", output, sizeof(output)) == 0);
    TEST_CHECK(strstr(output, "\"ok\":true") != nullptr);
    TEST_CHECK(strstr(output, "\"login_success_count\":1") != nullptr);
    TEST_CHECK(strstr(output, "\"login_failure_count\":1") != nullptr);
    TEST_CHECK(strstr(output, "\"lockout_count\":0") != nullptr);

    cleanup_path(users_path);
    cleanup_path(session_path);
    cleanup_path(audit_path);
    return 0;
}

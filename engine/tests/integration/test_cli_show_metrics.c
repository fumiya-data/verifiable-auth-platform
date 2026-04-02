#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "cli/command_runner.h"
#include "util/file_io.h"

static void read_stream(FILE *stream, char *buffer, size_t buffer_size)
{
    const size_t bytes_read = fread(buffer, 1u, buffer_size - 1u, stream);
    buffer[bytes_read] = '\0';
}

static void cleanup_path(const char *path)
{
    (void)remove(path);
}

static int run_command(int argc, char **argv, char *output, size_t output_size)
{
    FILE *stdout_capture = tmpfile();
    FILE *stderr_capture = tmpfile();
    const int exit_code = cli_command_runner_run_with_streams(argc, argv, stdout_capture, stderr_capture);

    rewind(stdout_capture);
    read_stream(stdout_capture, output, output_size);
    fclose(stdout_capture);
    fclose(stderr_capture);
    return exit_code;
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
        "--password", "hunter2",
    };
    char *login_argv[] = {
        "engine_cli",
        "login",
        "--data-dir", ".scratch/it_cli_show_metrics_data",
        "--login-id", "alice",
        "--password", "hunter2",
    };
    char *login_again_argv[] = {
        "engine_cli",
        "login",
        "--data-dir", ".scratch/it_cli_show_metrics_data",
        "--login-id", "alice",
        "--password", "hunter2",
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
        "--password", "wrong-password",
    };
    char *show_metrics_argv[] = {
        "engine_cli",
        "show-metrics",
        "--data-dir", ".scratch/it_cli_show_metrics_data",
    };

    assert(util_file_io_ensure_directory(".scratch") == UTIL_FILE_IO_STATUS_OK);
    cleanup_path(users_path);
    cleanup_path(session_path);
    cleanup_path(audit_path);
    assert(util_file_io_ensure_directory(data_dir) == UTIL_FILE_IO_STATUS_OK);

    assert(run_command(8, register_argv, output, sizeof(output)) == 0);
    assert(run_command(8, login_argv, output, sizeof(output)) == 0);
    assert(run_command(8, login_again_argv, output, sizeof(output)) == 0);
    assert(strstr(output, "\"result\":\"already_authenticated\"") != nullptr);
    assert(run_command(4, logout_argv, output, sizeof(output)) == 0);
    assert(run_command(8, wrong_password_argv, output, sizeof(output)) == 0);
    assert(strstr(output, "\"result\":\"wrong_password\"") != nullptr);
    assert(run_command(4, show_metrics_argv, output, sizeof(output)) == 0);
    assert(strstr(output, "\"ok\":true") != nullptr);
    assert(strstr(output, "\"login_success_count\":1") != nullptr);
    assert(strstr(output, "\"login_failure_count\":1") != nullptr);
    assert(strstr(output, "\"lockout_count\":0") != nullptr);

    cleanup_path(users_path);
    cleanup_path(session_path);
    cleanup_path(audit_path);
    return 0;
}

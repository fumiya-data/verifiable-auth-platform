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

static void cleanup_data_dir(const char *users_path, const char *session_path, const char *audit_path)
{
    cleanup_path(users_path);
    cleanup_path(session_path);
    cleanup_path(audit_path);
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

static void assert_matches_golden(const char *output, const char *golden_path)
{
    char expected[256];

    assert(util_file_io_read_text(golden_path, expected, sizeof(expected)) == UTIL_FILE_IO_STATUS_OK);
    assert(strcmp(output, expected) == 0);
}

static void prepare_data_dir(const char *data_dir, const char *users_path, const char *session_path, const char *audit_path)
{
    assert(util_file_io_ensure_directory(".scratch") == UTIL_FILE_IO_STATUS_OK);
    assert(util_file_io_ensure_directory(data_dir) == UTIL_FILE_IO_STATUS_OK);
    cleanup_data_dir(users_path, session_path, audit_path);
}

static void test_register_outputs(void)
{
    const char *data_dir = ".scratch/golden_cli_json_data";
    const char *users_path = ".scratch/golden_cli_json_data/users.tsv";
    const char *session_path = ".scratch/golden_cli_json_data/session.txt";
    const char *audit_path = ".scratch/golden_cli_json_data/audit.log";
    char output[256];
    char *register_argv[] = {
        "engine_cli",
        "register",
        "--data-dir", ".scratch/golden_cli_json_data",
        "--login-id", "alice",
        "--password", "hunter2",
    };

    prepare_data_dir(data_dir, users_path, session_path, audit_path);

    assert(run_command(8, register_argv, output, sizeof(output)) == 0);
    assert_matches_golden(output, "../tests/golden/cli-json/register-success.json");
    assert(run_command(8, register_argv, output, sizeof(output)) == 0);
    assert_matches_golden(output, "../tests/golden/cli-json/register-duplicate.json");

    cleanup_data_dir(users_path, session_path, audit_path);
}

static void test_login_outputs(void)
{
    const char *data_dir = ".scratch/golden_cli_json_data";
    const char *users_path = ".scratch/golden_cli_json_data/users.tsv";
    const char *session_path = ".scratch/golden_cli_json_data/session.txt";
    const char *audit_path = ".scratch/golden_cli_json_data/audit.log";
    char output[256];
    char *register_argv[] = {
        "engine_cli",
        "register",
        "--data-dir", ".scratch/golden_cli_json_data",
        "--login-id", "alice",
        "--password", "hunter2",
    };
    char *login_success_argv[] = {
        "engine_cli",
        "login",
        "--data-dir", ".scratch/golden_cli_json_data",
        "--login-id", "alice",
        "--password", "hunter2",
    };
    char *login_unknown_user_argv[] = {
        "engine_cli",
        "login",
        "--data-dir", ".scratch/golden_cli_json_data",
        "--login-id", "nobody",
        "--password", "hunter2",
    };
    char *login_wrong_password_argv[] = {
        "engine_cli",
        "login",
        "--data-dir", ".scratch/golden_cli_json_data",
        "--login-id", "alice",
        "--password", "wrong-password",
    };

    prepare_data_dir(data_dir, users_path, session_path, audit_path);

    assert(run_command(8, login_unknown_user_argv, output, sizeof(output)) == 0);
    assert_matches_golden(output, "../tests/golden/cli-json/login-unknown-user.json");

    assert(run_command(8, register_argv, output, sizeof(output)) == 0);
    assert(run_command(8, login_success_argv, output, sizeof(output)) == 0);
    assert_matches_golden(output, "../tests/golden/cli-json/login-success.json");
    assert(run_command(8, login_success_argv, output, sizeof(output)) == 0);
    assert_matches_golden(output, "../tests/golden/cli-json/login-already-authenticated.json");

    cleanup_data_dir(users_path, session_path, audit_path);
    prepare_data_dir(data_dir, users_path, session_path, audit_path);

    assert(run_command(8, register_argv, output, sizeof(output)) == 0);
    assert(run_command(8, login_wrong_password_argv, output, sizeof(output)) == 0);
    assert_matches_golden(output, "../tests/golden/cli-json/login-wrong-password.json");
    assert(run_command(8, login_wrong_password_argv, output, sizeof(output)) == 0);
    assert(run_command(8, login_wrong_password_argv, output, sizeof(output)) == 0);
    assert_matches_golden(output, "../tests/golden/cli-json/login-locked-out.json");

    cleanup_data_dir(users_path, session_path, audit_path);
}

static void test_change_password_outputs(void)
{
    const char *data_dir = ".scratch/golden_cli_json_data";
    const char *users_path = ".scratch/golden_cli_json_data/users.tsv";
    const char *session_path = ".scratch/golden_cli_json_data/session.txt";
    const char *audit_path = ".scratch/golden_cli_json_data/audit.log";
    char output[256];
    char *register_argv[] = {
        "engine_cli",
        "register",
        "--data-dir", ".scratch/golden_cli_json_data",
        "--login-id", "alice",
        "--password", "hunter2",
    };
    char *login_argv[] = {
        "engine_cli",
        "login",
        "--data-dir", ".scratch/golden_cli_json_data",
        "--login-id", "alice",
        "--password", "hunter2",
    };
    char *change_password_success_argv[] = {
        "engine_cli",
        "change-password",
        "--data-dir", ".scratch/golden_cli_json_data",
        "--old-password", "hunter2",
        "--new-password", "new-secret",
    };
    char *change_password_unauthorized_argv[] = {
        "engine_cli",
        "change-password",
        "--data-dir", ".scratch/golden_cli_json_data",
        "--old-password", "hunter2",
        "--new-password", "new-secret",
    };

    prepare_data_dir(data_dir, users_path, session_path, audit_path);

    assert(run_command(8, change_password_unauthorized_argv, output, sizeof(output)) == 0);
    assert_matches_golden(output, "../tests/golden/cli-json/change-password-unauthorized.json");

    assert(run_command(8, register_argv, output, sizeof(output)) == 0);
    assert(run_command(8, login_argv, output, sizeof(output)) == 0);
    assert(run_command(8, change_password_success_argv, output, sizeof(output)) == 0);
    assert_matches_golden(output, "../tests/golden/cli-json/change-password-success.json");

    cleanup_data_dir(users_path, session_path, audit_path);
}

int main(void)
{
    test_register_outputs();
    test_login_outputs();
    test_change_password_outputs();
    return 0;
}

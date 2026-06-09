#include "cli_test_support.h"
#include <string.h>

#include "util/file_io.h"

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

static void assert_matches_golden(const char *output, const char *golden_path)
{
    char expected[256];

    TEST_CHECK(util_file_io_read_text(golden_path, expected, sizeof(expected)) == UTIL_FILE_IO_STATUS_OK);
    TEST_CHECK(strcmp(output, expected) == 0);
}

static void prepare_data_dir(const char *data_dir, const char *users_path, const char *session_path, const char *audit_path)
{
    TEST_CHECK(util_file_io_ensure_directory(".scratch") == UTIL_FILE_IO_STATUS_OK);
    TEST_CHECK(util_file_io_ensure_directory(data_dir) == UTIL_FILE_IO_STATUS_OK);
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
        "--password-stdin",
    };

    prepare_data_dir(data_dir, users_path, session_path, audit_path);

    TEST_CHECK(test_cli_run_command(7, register_argv, "hunter2\n", output, sizeof(output)) == 0);
    assert_matches_golden(output, "../tests/golden/cli-json/register-success.json");
    TEST_CHECK(test_cli_run_command(7, register_argv, "hunter2\n", output, sizeof(output)) == 0);
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
        "--password-stdin",
    };
    char *login_success_argv[] = {
        "engine_cli",
        "login",
        "--data-dir", ".scratch/golden_cli_json_data",
        "--login-id", "alice",
        "--password-stdin",
    };
    char *login_unknown_user_argv[] = {
        "engine_cli",
        "login",
        "--data-dir", ".scratch/golden_cli_json_data",
        "--login-id", "nobody",
        "--password-stdin",
    };
    char *login_wrong_password_argv[] = {
        "engine_cli",
        "login",
        "--data-dir", ".scratch/golden_cli_json_data",
        "--login-id", "alice",
        "--password-stdin",
    };

    prepare_data_dir(data_dir, users_path, session_path, audit_path);

    TEST_CHECK(test_cli_run_command(7, login_unknown_user_argv, "hunter2\n", output, sizeof(output)) == 0);
    assert_matches_golden(output, "../tests/golden/cli-json/login-unknown-user.json");

    TEST_CHECK(test_cli_run_command(7, register_argv, "hunter2\n", output, sizeof(output)) == 0);
    TEST_CHECK(test_cli_run_command(7, login_success_argv, "hunter2\n", output, sizeof(output)) == 0);
    assert_matches_golden(output, "../tests/golden/cli-json/login-success.json");
    TEST_CHECK(test_cli_run_command(7, login_success_argv, "hunter2\n", output, sizeof(output)) == 0);
    assert_matches_golden(output, "../tests/golden/cli-json/login-already-authenticated.json");

    cleanup_data_dir(users_path, session_path, audit_path);
    prepare_data_dir(data_dir, users_path, session_path, audit_path);

    TEST_CHECK(test_cli_run_command(7, register_argv, "hunter2\n", output, sizeof(output)) == 0);
    TEST_CHECK(test_cli_run_command(7, login_wrong_password_argv, "wrong-password\n", output, sizeof(output)) == 0);
    assert_matches_golden(output, "../tests/golden/cli-json/login-wrong-password.json");
    TEST_CHECK(test_cli_run_command(7, login_wrong_password_argv, "wrong-password\n", output, sizeof(output)) == 0);
    TEST_CHECK(test_cli_run_command(7, login_wrong_password_argv, "wrong-password\n", output, sizeof(output)) == 0);
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
        "--password-stdin",
    };
    char *login_argv[] = {
        "engine_cli",
        "login",
        "--data-dir", ".scratch/golden_cli_json_data",
        "--login-id", "alice",
        "--password-stdin",
    };
    char *change_password_success_argv[] = {
        "engine_cli",
        "change-password",
        "--data-dir", ".scratch/golden_cli_json_data",
        "--old-password-stdin",
        "--new-password-stdin",
    };
    char *change_password_unauthorized_argv[] = {
        "engine_cli",
        "change-password",
        "--data-dir", ".scratch/golden_cli_json_data",
        "--old-password-stdin",
        "--new-password-stdin",
    };

    prepare_data_dir(data_dir, users_path, session_path, audit_path);

    TEST_CHECK(test_cli_run_command(6,
                                    change_password_unauthorized_argv,
                                    "hunter2\nnew-secret\n",
                                    output,
                                    sizeof(output)) == 0);
    assert_matches_golden(output, "../tests/golden/cli-json/change-password-unauthorized.json");

    TEST_CHECK(test_cli_run_command(7, register_argv, "hunter2\n", output, sizeof(output)) == 0);
    TEST_CHECK(test_cli_run_command(7, login_argv, "hunter2\n", output, sizeof(output)) == 0);
    TEST_CHECK(test_cli_run_command(6,
                                    change_password_success_argv,
                                    "hunter2\nnew-secret\n",
                                    output,
                                    sizeof(output)) == 0);
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

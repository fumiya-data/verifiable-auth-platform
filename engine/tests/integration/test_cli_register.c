#include "cli_test_support.h"
#include <string.h>

#include "auth/types.h"
#include "cli/exit_codes.h"
#include "util/file_io.h"

static void cleanup_path(const char *path)
{
    (void)remove(path);
}

static void fill_string(char *value, size_t value_size, char ch)
{
    memset(value, ch, value_size - 1u);
    value[value_size - 1u] = '\0';
}

static void test_register_success_and_duplicate(void)
{
    const char *data_dir = ".scratch/it_cli_register_data";
    const char *users_path = ".scratch/it_cli_register_data/users.tsv";
    const char *session_path = ".scratch/it_cli_register_data/session.txt";
    const char *audit_path = ".scratch/it_cli_register_data/audit.log";
    char output[512];
    char users_file[512];
    char *argv[] = {
        "engine_cli",
        "register",
        "--data-dir", ".scratch/it_cli_register_data",
        "--login-id", "alice",
        "--password-stdin",
    };

    TEST_CHECK(util_file_io_ensure_directory(".scratch") == UTIL_FILE_IO_STATUS_OK);
    cleanup_path(users_path);
    cleanup_path(session_path);
    cleanup_path(audit_path);
    TEST_CHECK(util_file_io_ensure_directory(data_dir) == UTIL_FILE_IO_STATUS_OK);

    TEST_CHECK(test_cli_run_command(7, argv, "hunter2\n", output, sizeof(output)) == 0);

    TEST_CHECK(strstr(output, "\"ok\":true") != nullptr);
    TEST_CHECK(strstr(output, "\"result\":\"success\"") != nullptr);
    TEST_CHECK(util_file_io_read_text(users_path, users_file, sizeof(users_file)) == UTIL_FILE_IO_STATUS_OK);
    TEST_CHECK(strstr(users_file, "alice") != nullptr);
    TEST_CHECK(test_cli_run_command(7, argv, "hunter2\n", output, sizeof(output)) == 0);
    TEST_CHECK(strstr(output, "\"ok\":false") != nullptr);
    TEST_CHECK(strstr(output, "\"result\":\"duplicate\"") != nullptr);

    cleanup_path(users_path);
    cleanup_path(session_path);
    cleanup_path(audit_path);
}

static void test_register_input_validation(void)
{
    const char *data_dir = ".scratch/it_cli_register_validation_data";
    const char *users_path = ".scratch/it_cli_register_validation_data/users.tsv";
    const char *session_path = ".scratch/it_cli_register_validation_data/session.txt";
    const char *audit_path = ".scratch/it_cli_register_validation_data/audit.log";
    char output[512];
    char too_long_login_id[AUTH_LOGIN_ID_MAX_LENGTH + 2u];
    char boundary_login_id[AUTH_LOGIN_ID_MAX_LENGTH + 1u];
    char too_long_password[AUTH_PASSWORD_MAX_LENGTH + 3u];
    char boundary_password_input[AUTH_PASSWORD_MAX_LENGTH + 2u];
    char *too_long_login_argv[] = {
        "engine_cli",
        "register",
        "--data-dir", ".scratch/it_cli_register_validation_data",
        "--login-id", too_long_login_id,
        "--password-stdin",
    };
    char *tab_login_argv[] = {
        "engine_cli",
        "register",
        "--data-dir", ".scratch/it_cli_register_validation_data",
        "--login-id", "bad\tid",
        "--password-stdin",
    };
    char *newline_login_argv[] = {
        "engine_cli",
        "register",
        "--data-dir", ".scratch/it_cli_register_validation_data",
        "--login-id", "bad\nid",
        "--password-stdin",
    };
    char *password_argv[] = {
        "engine_cli",
        "register",
        "--data-dir", ".scratch/it_cli_register_validation_data",
        "--login-id", "alice",
        "--password-stdin",
    };
    char *boundary_argv[] = {
        "engine_cli",
        "register",
        "--data-dir", ".scratch/it_cli_register_validation_data",
        "--login-id", boundary_login_id,
        "--password-stdin",
    };
    char *show_audit_argv[] = {
        "engine_cli",
        "show-audit",
        "--data-dir", ".scratch/it_cli_register_validation_data",
    };

    fill_string(too_long_login_id, sizeof(too_long_login_id), 'a');
    fill_string(boundary_login_id, sizeof(boundary_login_id), 'b');
    fill_string(too_long_password, sizeof(too_long_password), 'p');
    fill_string(boundary_password_input, sizeof(boundary_password_input), 'q');
    boundary_password_input[AUTH_PASSWORD_MAX_LENGTH] = '\n';
    boundary_password_input[AUTH_PASSWORD_MAX_LENGTH + 1u] = '\0';

    TEST_CHECK(util_file_io_ensure_directory(".scratch") == UTIL_FILE_IO_STATUS_OK);
    cleanup_path(users_path);
    cleanup_path(session_path);
    cleanup_path(audit_path);
    TEST_CHECK(util_file_io_ensure_directory(data_dir) == UTIL_FILE_IO_STATUS_OK);

    TEST_CHECK(test_cli_run_command(7,
                                    too_long_login_argv,
                                    "hunter2\n",
                                    output,
                                    sizeof(output)) == CLI_EXIT_CODE_USAGE_ERROR);
    TEST_CHECK(strstr(output, "\"result\":\"invalid_request\"") != nullptr);

    TEST_CHECK(test_cli_run_command(7,
                                    tab_login_argv,
                                    "hunter2\n",
                                    output,
                                    sizeof(output)) == CLI_EXIT_CODE_USAGE_ERROR);
    TEST_CHECK(strstr(output, "\"result\":\"invalid_request\"") != nullptr);

    TEST_CHECK(test_cli_run_command(7,
                                    newline_login_argv,
                                    "hunter2\n",
                                    output,
                                    sizeof(output)) == CLI_EXIT_CODE_USAGE_ERROR);
    TEST_CHECK(strstr(output, "\"result\":\"invalid_request\"") != nullptr);

    TEST_CHECK(test_cli_run_command(7,
                                    password_argv,
                                    "\n",
                                    output,
                                    sizeof(output)) == CLI_EXIT_CODE_USAGE_ERROR);
    TEST_CHECK(strstr(output, "\"result\":\"invalid_request\"") != nullptr);

    TEST_CHECK(test_cli_run_command(7,
                                    password_argv,
                                    "bad\tpassword\n",
                                    output,
                                    sizeof(output)) == CLI_EXIT_CODE_USAGE_ERROR);
    TEST_CHECK(strstr(output, "\"result\":\"invalid_request\"") != nullptr);

    TEST_CHECK(test_cli_run_command(7,
                                    password_argv,
                                    too_long_password,
                                    output,
                                    sizeof(output)) == CLI_EXIT_CODE_USAGE_ERROR);
    TEST_CHECK(strstr(output, "\"result\":\"invalid_request\"") != nullptr);

    TEST_CHECK(test_cli_run_command(4, show_audit_argv, "", output, sizeof(output)) == CLI_EXIT_CODE_SUCCESS);
    TEST_CHECK(strstr(output, "\"ok\":true") != nullptr);

    TEST_CHECK(test_cli_run_command(7,
                                    boundary_argv,
                                    boundary_password_input,
                                    output,
                                    sizeof(output)) == CLI_EXIT_CODE_SUCCESS);
    TEST_CHECK(strstr(output, "\"result\":\"success\"") != nullptr);

    cleanup_path(users_path);
    cleanup_path(session_path);
    cleanup_path(audit_path);
}

int main(void)
{
    test_register_success_and_duplicate();
    test_register_input_validation();
    return 0;
}

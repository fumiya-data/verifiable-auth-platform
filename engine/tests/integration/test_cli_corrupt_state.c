#include "cli_test_support.h"
#include <string.h>

#include "util/file_io.h"

static void cleanup_path(const char *path)
{
    (void)remove(path);
}

int main(void)
{
    const char *data_dir = ".scratch/it_cli_corrupt_state_data";
    const char *users_path = ".scratch/it_cli_corrupt_state_data/users.tsv";
    const char *session_path = ".scratch/it_cli_corrupt_state_data/session.txt";
    const char *audit_path = ".scratch/it_cli_corrupt_state_data/audit.log";
    char output[256];
    char *argv[] = {
        "engine_cli",
        "change-password",
        "--data-dir", ".scratch/it_cli_corrupt_state_data",
        "--old-password-stdin",
        "--new-password-stdin",
    };

    TEST_CHECK(util_file_io_ensure_directory(".scratch") == UTIL_FILE_IO_STATUS_OK);
    cleanup_path(users_path);
    cleanup_path(session_path);
    cleanup_path(audit_path);
    TEST_CHECK(util_file_io_ensure_directory(data_dir) == UTIL_FILE_IO_STATUS_OK);
    TEST_CHECK(util_file_io_write_text(session_path, "ghost") == UTIL_FILE_IO_STATUS_OK);

    TEST_CHECK(test_cli_run_command(6, argv, "", output, sizeof(output)) == 1);
    TEST_CHECK(strstr(output, "\"ok\":false") != nullptr);
    TEST_CHECK(strstr(output, "\"result\":\"system_error\"") != nullptr);
    TEST_CHECK(strstr(output, "\"message\":\"failed to load state\"") != nullptr);

    cleanup_path(users_path);
    cleanup_path(session_path);
    cleanup_path(audit_path);
    return 0;
}

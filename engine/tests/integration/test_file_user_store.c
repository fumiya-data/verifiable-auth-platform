#include "test_support.h"
#include <stdio.h>
#include <string.h>

#include "auth/register.h"
#include "auth/state.h"
#include "storage/user_store.h"
#include "util/file_io.h"

static void cleanup_file(const char *path)
{
    (void)remove(path);
}

int main(void)
{
    const char *path = ".scratch/it_user_store.tsv";
    auth_state_t saved_state;
    auth_state_t loaded_state;
    char duplicate_rows[1024];

    TEST_CHECK(util_file_io_ensure_directory(".scratch") == UTIL_FILE_IO_STATUS_OK);
    cleanup_file(path);

    auth_state_init(&saved_state);
    TEST_CHECK(auth_register(&saved_state, "alice", "hunter2") == AUTH_REGISTER_RESULT_SUCCESS);
    TEST_CHECK(auth_register(&saved_state, "bob", "correct horse") == AUTH_REGISTER_RESULT_SUCCESS);
    TEST_CHECK(storage_user_store_save(path, &saved_state) == STORAGE_USER_STORE_STATUS_OK);
    TEST_CHECK(util_file_io_exists(path));

    auth_state_init(&loaded_state);
    TEST_CHECK(storage_user_store_load(path, &loaded_state) == STORAGE_USER_STORE_STATUS_OK);
    TEST_CHECK(loaded_state.user_count == saved_state.user_count);
    TEST_CHECK(strcmp(loaded_state.users[0].login_id, "alice") == 0);
    TEST_CHECK(strcmp(loaded_state.users[1].login_id, "bob") == 0);
    TEST_CHECK(strcmp(loaded_state.users[0].password_hash, saved_state.users[0].password_hash) == 0);
    TEST_CHECK(strcmp(loaded_state.users[1].salt, saved_state.users[1].salt) == 0);
    TEST_CHECK(snprintf(duplicate_rows,
                    sizeof(duplicate_rows),
                    "%s\t%s\t%s\t%u\tactive\n"
                    "%s\t%s\t%s\t%u\tactive\n",
                    saved_state.users[0].login_id,
                    saved_state.users[0].salt,
                    saved_state.users[0].password_hash,
                    saved_state.users[0].failed_attempts,
                    saved_state.users[0].login_id,
                    saved_state.users[0].salt,
                    saved_state.users[0].password_hash,
                    saved_state.users[0].failed_attempts) > 0);
    TEST_CHECK(util_file_io_write_text(path, duplicate_rows) == UTIL_FILE_IO_STATUS_OK);
    TEST_CHECK(storage_user_store_load(path, &loaded_state) == STORAGE_USER_STORE_STATUS_PARSE_ERROR);

    cleanup_file(path);
    return 0;
}

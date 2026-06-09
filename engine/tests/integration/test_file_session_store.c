#include "test_support.h"
#include <stdio.h>
#include <string.h>

#include "auth/register.h"
#include "auth/state.h"
#include "storage/session_store.h"
#include "util/file_io.h"

static void cleanup_file(const char *path)
{
    (void)remove(path);
}

int main(void)
{
    const char *path = ".scratch/it_session_store.txt";
    auth_state_t saved_state;
    auth_state_t loaded_state;

    TEST_CHECK(util_file_io_ensure_directory(".scratch") == UTIL_FILE_IO_STATUS_OK);
    cleanup_file(path);

    auth_state_init(&saved_state);
    TEST_CHECK(auth_register(&saved_state, "alice", "hunter2") == AUTH_REGISTER_RESULT_SUCCESS);
    auth_state_set_authenticated_user(&saved_state, "alice");
    TEST_CHECK(storage_session_store_save(path, &saved_state) == STORAGE_SESSION_STORE_STATUS_OK);

    loaded_state = saved_state;
    auth_state_clear_session(&loaded_state);
    TEST_CHECK(storage_session_store_load(path, &loaded_state) == STORAGE_SESSION_STORE_STATUS_OK);
    TEST_CHECK(loaded_state.authenticated);
    TEST_CHECK(strcmp(loaded_state.authenticated_login_id, "alice") == 0);

    auth_state_clear_session(&saved_state);
    TEST_CHECK(storage_session_store_save(path, &saved_state) == STORAGE_SESSION_STORE_STATUS_OK);
    loaded_state = saved_state;
    auth_state_set_authenticated_user(&loaded_state, "alice");
    TEST_CHECK(storage_session_store_load(path, &loaded_state) == STORAGE_SESSION_STORE_STATUS_OK);
    TEST_CHECK(!loaded_state.authenticated);

    TEST_CHECK(util_file_io_write_text(path, "unknown-user") == UTIL_FILE_IO_STATUS_OK);
    loaded_state = saved_state;
    TEST_CHECK(storage_session_store_load(path, &loaded_state) == STORAGE_SESSION_STORE_STATUS_PARSE_ERROR);

    cleanup_file(path);
    return 0;
}

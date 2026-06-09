#include "test_support.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "crypto/hash_adapter.h"

static void expect_hash(const char *password,
                        const char *salt,
                        uint32_t iterations,
                        const char *expected_hash)
{
    char actual_hash[AUTH_HASH_ENCODED_LENGTH];

    TEST_CHECK(auth_hash_password_with_iterations((const uint8_t *)password,
                                              strlen(password),
                                              (const uint8_t *)salt,
                                              strlen(salt),
                                              iterations,
                                              actual_hash,
                                              sizeof(actual_hash)) == AUTH_HASH_STATUS_OK);
    TEST_CHECK(strcmp(actual_hash, expected_hash) == 0);
}

static void test_known_vectors(void)
{
    expect_hash("password", "salt", 1u,
                "120fb6cffcf8b32c43e7225256c4f837a86548c92ccc35480805987cb70be17b");
    expect_hash("password", "salt", 2u,
                "ae4d0c95af6b46d32d0adff928f06dd02a303f8ef3c251dfd6e2d85a95474c43");
    expect_hash("password", "salt", 4096u,
                "c5e478d59288c841aa530db6845c4c8d962893a001ce4e11a4963873aa98134a");
}

static void test_default_hash_matches_expected_iteration_policy(void)
{
    char actual_hash[AUTH_HASH_ENCODED_LENGTH];

    TEST_CHECK(auth_hash_password((const uint8_t *)"hunter2", strlen("hunter2"),
                              (const uint8_t *)"unique-salt", strlen("unique-salt"),
                              actual_hash, sizeof(actual_hash)) == AUTH_HASH_STATUS_OK);
    TEST_CHECK(strcmp(actual_hash,
                  "e4f9aee85089bd0018081357a186f122a11c34264d33d3504e272a3ed9cf7a36") == 0);
}

static void test_verify_password(void)
{
    const char *expected_hash =
        "e4f9aee85089bd0018081357a186f122a11c34264d33d3504e272a3ed9cf7a36";

    TEST_CHECK(auth_hash_verify_password((const uint8_t *)"hunter2", strlen("hunter2"),
                                     (const uint8_t *)"unique-salt", strlen("unique-salt"),
                                     expected_hash));
    TEST_CHECK(!auth_hash_verify_password((const uint8_t *)"wrong-password", strlen("wrong-password"),
                                      (const uint8_t *)"unique-salt", strlen("unique-salt"),
                                      expected_hash));
    TEST_CHECK(!auth_hash_verify_password((const uint8_t *)"hunter2", strlen("hunter2"),
                                      (const uint8_t *)"other-salt", strlen("other-salt"),
                                      expected_hash));
    TEST_CHECK(!auth_hash_verify_password((const uint8_t *)"hunter2", strlen("hunter2"),
                                      (const uint8_t *)"unique-salt", strlen("unique-salt"),
                                      "short"));
}

static void test_invalid_arguments(void)
{
    char actual_hash[AUTH_HASH_ENCODED_LENGTH];

    TEST_CHECK(auth_hash_password_with_iterations(nullptr, 1u,
                                              (const uint8_t *)"salt", strlen("salt"),
                                              1u,
                                              actual_hash,
                                              sizeof(actual_hash)) == AUTH_HASH_STATUS_INVALID_ARGUMENT);
    TEST_CHECK(auth_hash_password_with_iterations((const uint8_t *)"password", strlen("password"),
                                              nullptr, 1u,
                                              1u,
                                              actual_hash,
                                              sizeof(actual_hash)) == AUTH_HASH_STATUS_INVALID_ARGUMENT);
    TEST_CHECK(auth_hash_password_with_iterations((const uint8_t *)"password", strlen("password"),
                                              (const uint8_t *)"salt", strlen("salt"),
                                              0u,
                                              actual_hash,
                                              sizeof(actual_hash)) == AUTH_HASH_STATUS_INVALID_ARGUMENT);
    TEST_CHECK(auth_hash_password((const uint8_t *)"password", strlen("password"),
                              (const uint8_t *)"salt", strlen("salt"),
                              actual_hash,
                              AUTH_HASH_ENCODED_LENGTH - 1u) == AUTH_HASH_STATUS_OUTPUT_TOO_SMALL);
    TEST_CHECK(strcmp(auth_hash_status_string(AUTH_HASH_STATUS_OK), "ok") == 0);
    TEST_CHECK(strcmp(auth_hash_status_string(AUTH_HASH_STATUS_INVALID_ARGUMENT),
                  "invalid_argument") == 0);
}

int main(void)
{
    test_known_vectors();
    test_default_hash_matches_expected_iteration_policy();
    test_verify_password();
    test_invalid_arguments();

    puts("test_hash_adapter: ok");
    return 0;
}

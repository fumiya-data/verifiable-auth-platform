#include "test_support.h"
#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "crypto/salt_adapter.h"

static bool is_lower_hex_string(const char *value)
{
    for (size_t index = 0; index < AUTH_SALT_ENCODED_LENGTH - 1u; ++index) {
        if (!isxdigit((unsigned char)value[index]) || isupper((unsigned char)value[index])) {
            return false;
        }
    }

    return true;
}

static void test_generate_and_validate_salt(void)
{
    char salt[AUTH_SALT_ENCODED_LENGTH];

    TEST_CHECK(auth_salt_generate(salt, sizeof(salt)) == AUTH_SALT_STATUS_OK);
    TEST_CHECK(strlen(salt) == AUTH_SALT_ENCODED_LENGTH - 1u);
    TEST_CHECK(is_lower_hex_string(salt));
    TEST_CHECK(auth_salt_is_valid(salt));
}

static void test_fill_bytes(void)
{
    uint8_t salt[AUTH_SALT_BYTES];
    bool has_non_zero_byte = false;

    TEST_CHECK(auth_salt_fill_bytes(salt, sizeof(salt)) == AUTH_SALT_STATUS_OK);

    for (size_t index = 0; index < sizeof(salt); ++index) {
        if (salt[index] != 0u) {
            has_non_zero_byte = true;
            break;
        }
    }

    TEST_CHECK(has_non_zero_byte);
}

static void test_invalid_arguments(void)
{
    char salt[AUTH_SALT_ENCODED_LENGTH];
    uint8_t raw_salt[AUTH_SALT_BYTES];

    TEST_CHECK(auth_salt_fill_bytes(nullptr, sizeof(raw_salt)) == AUTH_SALT_STATUS_INVALID_ARGUMENT);
    TEST_CHECK(auth_salt_fill_bytes(raw_salt, AUTH_SALT_BYTES - 1u) ==
           AUTH_SALT_STATUS_OUTPUT_TOO_SMALL);
    TEST_CHECK(auth_salt_generate(nullptr, sizeof(salt)) == AUTH_SALT_STATUS_INVALID_ARGUMENT);
    TEST_CHECK(auth_salt_generate(salt, AUTH_SALT_ENCODED_LENGTH - 1u) ==
           AUTH_SALT_STATUS_OUTPUT_TOO_SMALL);
    TEST_CHECK(!auth_salt_is_valid(nullptr));
    TEST_CHECK(!auth_salt_is_valid("too-short"));
    TEST_CHECK(!auth_salt_is_valid("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz"));
    TEST_CHECK(strcmp(auth_salt_status_string(AUTH_SALT_STATUS_OK), "ok") == 0);
    TEST_CHECK(strcmp(auth_salt_status_string(AUTH_SALT_STATUS_RANDOM_SOURCE_FAILURE),
                  "random_source_failure") == 0);
}

int main(void)
{
    test_generate_and_validate_salt();
    test_fill_bytes();
    test_invalid_arguments();

    puts("test_salt_adapter: ok");
    return 0;
}

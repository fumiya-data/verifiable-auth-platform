cmake_minimum_required(VERSION 3.25)

project(verifiable_auth_engine LANGUAGES C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

if (WIN32)
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
endif()

function(engine_apply_warnings target_name)
    if (MSVC)
        target_compile_options(${target_name} PRIVATE /W4 /WX)
    else()
        target_compile_options(${target_name} PRIVATE -Wall -Wextra -Wpedantic -Werror)
    endif()
endfunction()

function(engine_add_test test_name)
    add_test(NAME ${test_name} COMMAND ${test_name})
    set_tests_properties(${test_name} PROPERTIES
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
endfunction()

add_library(engine_crypto STATIC
    src/crypto/hash_adapter.c
    src/crypto/salt_adapter.c
    src/crypto/sha256.c
)

target_include_directories(engine_crypto
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/crypto
)

if (WIN32)
    target_link_libraries(engine_crypto PUBLIC bcrypt)
endif()

add_library(engine_auth_core STATIC
    src/core/change_password.c
    src/core/login.c
    src/core/logout.c
    src/core/register.c
    src/core/state.c
    src/core/validation.c
)

target_include_directories(engine_auth_core
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(engine_auth_core PUBLIC engine_crypto)

add_library(engine_util STATIC
    src/util/file_io.c
    src/util/memory.c
    src/util/parse.c
    src/util/string_view.c
)

target_include_directories(engine_util
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_library(engine_storage STATIC
    src/storage/file_audit_log.c
    src/storage/file_session_store.c
    src/storage/file_user_store.c
)

target_include_directories(engine_storage
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(engine_storage PUBLIC engine_auth_core engine_util)

add_library(engine_cli_lib STATIC
    src/app/service_main.c
    src/cli/command_runner.c
    src/cli/exit_codes.c
    src/cli/json_output.c
)

target_include_directories(engine_cli_lib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(engine_cli_lib PUBLIC engine_storage)

add_executable(engine_cli
    src/app/cli_main.c
)

target_link_libraries(engine_cli PRIVATE engine_cli_lib)

engine_apply_warnings(engine_crypto)
engine_apply_warnings(engine_auth_core)
engine_apply_warnings(engine_util)
engine_apply_warnings(engine_storage)
engine_apply_warnings(engine_cli_lib)
engine_apply_warnings(engine_cli)

add_executable(test_hash_adapter tests/unit/test_hash_adapter.c)
target_link_libraries(test_hash_adapter PRIVATE engine_crypto)
engine_apply_warnings(test_hash_adapter)

add_executable(test_salt_adapter tests/unit/test_salt_adapter.c)
target_link_libraries(test_salt_adapter PRIVATE engine_crypto)
engine_apply_warnings(test_salt_adapter)

add_executable(test_validation tests/unit/test_validation.c)
target_link_libraries(test_validation PRIVATE engine_auth_core)
engine_apply_warnings(test_validation)

add_executable(test_register tests/unit/test_register.c)
target_link_libraries(test_register PRIVATE engine_auth_core)
engine_apply_warnings(test_register)

add_executable(test_login tests/unit/test_login.c)
target_link_libraries(test_login PRIVATE engine_auth_core)
engine_apply_warnings(test_login)

add_executable(test_change_password tests/unit/test_change_password.c)
target_link_libraries(test_change_password PRIVATE engine_auth_core)
engine_apply_warnings(test_change_password)

add_executable(test_logout tests/unit/test_logout.c)
target_link_libraries(test_logout PRIVATE engine_auth_core)
engine_apply_warnings(test_logout)

add_executable(test_file_user_store tests/integration/test_file_user_store.c)
target_link_libraries(test_file_user_store PRIVATE engine_storage)
engine_apply_warnings(test_file_user_store)

add_executable(test_file_session_store tests/integration/test_file_session_store.c)
target_link_libraries(test_file_session_store PRIVATE engine_storage)
engine_apply_warnings(test_file_session_store)

add_executable(test_file_audit_log tests/integration/test_file_audit_log.c)
target_link_libraries(test_file_audit_log PRIVATE engine_storage)
engine_apply_warnings(test_file_audit_log)

add_executable(test_cli_register tests/integration/test_cli_register.c)
target_link_libraries(test_cli_register PRIVATE engine_cli_lib)
engine_apply_warnings(test_cli_register)

add_executable(test_cli_login tests/integration/test_cli_login.c)
target_link_libraries(test_cli_login PRIVATE engine_cli_lib)
engine_apply_warnings(test_cli_login)

add_executable(test_cli_change_password tests/integration/test_cli_change_password.c)
target_link_libraries(test_cli_change_password PRIVATE engine_cli_lib)
engine_apply_warnings(test_cli_change_password)

add_executable(test_cli_show_audit tests/integration/test_cli_show_audit.c)
target_link_libraries(test_cli_show_audit PRIVATE engine_cli_lib)
engine_apply_warnings(test_cli_show_audit)

add_executable(test_cli_show_metrics tests/integration/test_cli_show_metrics.c)
target_link_libraries(test_cli_show_metrics PRIVATE engine_cli_lib)
engine_apply_warnings(test_cli_show_metrics)

add_executable(test_cli_golden_json tests/integration/test_cli_golden_json.c)
target_link_libraries(test_cli_golden_json PRIVATE engine_cli_lib engine_util)
engine_apply_warnings(test_cli_golden_json)

add_executable(test_cli_corrupt_state tests/integration/test_cli_corrupt_state.c)
target_link_libraries(test_cli_corrupt_state PRIVATE engine_cli_lib engine_util)
engine_apply_warnings(test_cli_corrupt_state)

enable_testing()

engine_add_test(test_hash_adapter)
engine_add_test(test_salt_adapter)
engine_add_test(test_validation)
engine_add_test(test_register)
engine_add_test(test_login)
engine_add_test(test_change_password)
engine_add_test(test_logout)
engine_add_test(test_file_user_store)
engine_add_test(test_file_session_store)
engine_add_test(test_file_audit_log)
engine_add_test(test_cli_register)
engine_add_test(test_cli_login)
engine_add_test(test_cli_change_password)
engine_add_test(test_cli_show_audit)
engine_add_test(test_cli_show_metrics)
engine_add_test(test_cli_golden_json)
engine_add_test(test_cli_corrupt_state)

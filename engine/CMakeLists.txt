cmake_minimum_required(VERSION 3.25)

project(verifiable_auth_engine LANGUAGES C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

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

if (MSVC)
    target_compile_options(engine_crypto PRIVATE /W4 /WX)
else()
    target_compile_options(engine_crypto PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()

add_executable(test_hash_adapter
    tests/unit/test_hash_adapter.c
)

target_link_libraries(test_hash_adapter PRIVATE engine_crypto)

add_executable(test_salt_adapter
    tests/unit/test_salt_adapter.c
)

target_link_libraries(test_salt_adapter PRIVATE engine_crypto)

if (MSVC)
    target_compile_options(test_hash_adapter PRIVATE /W4 /WX)
    target_compile_options(test_salt_adapter PRIVATE /W4 /WX)
else()
    target_compile_options(test_hash_adapter PRIVATE -Wall -Wextra -Wpedantic -Werror)
    target_compile_options(test_salt_adapter PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()

enable_testing()
add_test(NAME test_hash_adapter COMMAND test_hash_adapter)
add_test(NAME test_salt_adapter COMMAND test_salt_adapter)

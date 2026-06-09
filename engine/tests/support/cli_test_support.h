#ifndef VERIFIABLE_AUTH_PLATFORM_ENGINE_CLI_TEST_SUPPORT_H
#define VERIFIABLE_AUTH_PLATFORM_ENGINE_CLI_TEST_SUPPORT_H

#include <stdio.h>

#include "cli/command_runner.h"
#include "test_support.h"

static void test_cli_read_stream(FILE *stream, char *buffer, size_t buffer_size)
{
    const size_t bytes_read = fread(buffer, 1u, buffer_size - 1u, stream);
    buffer[bytes_read] = '\0';
}

static int test_cli_run_command(int argc,
                                char **argv,
                                const char *input,
                                char *output,
                                size_t output_size)
{
    FILE *stdin_capture = tmpfile();
    FILE *stdout_capture = tmpfile();
    FILE *stderr_capture = tmpfile();
    int exit_code = 0;

    TEST_CHECK(stdin_capture != nullptr);
    TEST_CHECK(stdout_capture != nullptr);
    TEST_CHECK(stderr_capture != nullptr);

    if (input != nullptr) {
        TEST_CHECK(fputs(input, stdin_capture) >= 0);
    }
    rewind(stdin_capture);

    exit_code = cli_command_runner_run_with_io(argc,
                                               argv,
                                               stdin_capture,
                                               stdout_capture,
                                               stderr_capture);

    rewind(stdout_capture);
    test_cli_read_stream(stdout_capture, output, output_size);
    fclose(stdin_capture);
    fclose(stdout_capture);
    fclose(stderr_capture);
    return exit_code;
}

#endif

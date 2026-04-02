#ifndef VERIFIABLE_AUTH_PLATFORM_ENGINE_CLI_COMMAND_RUNNER_H
#define VERIFIABLE_AUTH_PLATFORM_ENGINE_CLI_COMMAND_RUNNER_H

#include <stdio.h>

/**
 * @brief Execute the engine CLI using the process standard streams.
 *
 * @param argc Argument count supplied to `main`.
 * @param argv Argument vector supplied to `main`.
 * @return Process exit code from the CLI command runner.
 */
int cli_command_runner_run(int argc, char **argv);

/**
 * @brief Execute the engine CLI against caller-supplied output streams.
 *
 * This entry point is intended for tests and embedding layers that need to
 * capture the exact serialized JSON contract.
 *
 * @param argc Argument count supplied by the caller.
 * @param argv Argument vector supplied by the caller.
 * @param output_stream Stream that receives JSON responses.
 * @param error_stream Reserved error stream handle for future diagnostics.
 * @return Process exit code from the CLI command runner.
 */
int cli_command_runner_run_with_streams(int argc,
                                        char **argv,
                                        FILE *output_stream,
                                        FILE *error_stream);

#endif

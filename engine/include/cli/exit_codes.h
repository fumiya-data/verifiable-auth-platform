#ifndef VERIFIABLE_AUTH_PLATFORM_ENGINE_CLI_EXIT_CODES_H
#define VERIFIABLE_AUTH_PLATFORM_ENGINE_CLI_EXIT_CODES_H

/**
 * @brief Stable process exit codes exposed by the engine CLI.
 */
typedef enum cli_exit_code {
    /** The command completed successfully, even if `ok` is false in JSON. */
    CLI_EXIT_CODE_SUCCESS = 0,
    /** The command could not complete because of a runtime failure. */
    CLI_EXIT_CODE_RUNTIME_ERROR = 1,
    /** The command line itself was invalid. */
    CLI_EXIT_CODE_USAGE_ERROR = 2,
} cli_exit_code_t;

#endif

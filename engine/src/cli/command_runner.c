#include "cli/command_runner.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "auth/change_password.h"
#include "auth/login.h"
#include "auth/logout.h"
#include "auth/register.h"
#include "auth/state.h"
#include "auth/validation.h"
#include "cli/exit_codes.h"
#include "cli/json_output.h"
#include "storage/audit_log.h"
#include "storage/session_store.h"
#include "storage/user_store.h"
#include "util/file_io.h"

#define CLI_PATH_BUFFER_LENGTH 512u

typedef struct cli_command_args {
    const char *command;
    const char *data_dir;
    const char *login_id;
    const char *password;
    const char *old_password;
    const char *new_password;
    bool password_from_stdin;
    bool old_password_from_stdin;
    bool new_password_from_stdin;
} cli_command_args_t;

typedef struct cli_command_paths {
    char users_path[CLI_PATH_BUFFER_LENGTH];
    char session_path[CLI_PATH_BUFFER_LENGTH];
    char audit_path[CLI_PATH_BUFFER_LENGTH];
} cli_command_paths_t;

typedef struct cli_secret_buffers {
    char password[AUTH_PASSWORD_MAX_LENGTH + 2u];
    char old_password[AUTH_PASSWORD_MAX_LENGTH + 2u];
    char new_password[AUTH_PASSWORD_MAX_LENGTH + 2u];
} cli_secret_buffers_t;

static bool cli_string_equals(const char *left, const char *right)
{
    return strcmp(left, right) == 0;
}

static bool cli_parse_arguments(int argc,
                                char **argv,
                                cli_command_args_t *args,
                                const char **error_message)
{
    memset(args, 0, sizeof(*args));
    args->data_dir = ".engine-data";

    for (int index = 1; index < argc; ++index) {
        const char *argument = argv[index];

        if (strncmp(argument, "--", 2u) == 0) {
            if (cli_string_equals(argument, "--data-dir")) {
                if (index + 1 >= argc) {
                    *error_message = "missing option value";
                    return false;
                }
                args->data_dir = argv[++index];
            } else if (cli_string_equals(argument, "--login-id")) {
                if (index + 1 >= argc) {
                    *error_message = "missing option value";
                    return false;
                }
                args->login_id = argv[++index];
            } else if (cli_string_equals(argument, "--password")) {
                *error_message = "password argv transport is not supported; use --password-stdin";
                return false;
            } else if (cli_string_equals(argument, "--old-password")) {
                *error_message = "password argv transport is not supported; use --old-password-stdin";
                return false;
            } else if (cli_string_equals(argument, "--new-password")) {
                *error_message = "password argv transport is not supported; use --new-password-stdin";
                return false;
            } else if (cli_string_equals(argument, "--password-stdin")) {
                args->password_from_stdin = true;
            } else if (cli_string_equals(argument, "--old-password-stdin")) {
                args->old_password_from_stdin = true;
            } else if (cli_string_equals(argument, "--new-password-stdin")) {
                args->new_password_from_stdin = true;
            } else {
                *error_message = "unknown option";
                return false;
            }
        } else if (args->command == nullptr) {
            args->command = argument;
        } else {
            *error_message = "unexpected positional argument";
            return false;
        }
    }

    if (args->command == nullptr) {
        *error_message = "missing command";
        return false;
    }

    return true;
}

static bool cli_build_paths(const cli_command_args_t *args, cli_command_paths_t *paths)
{
    const int users_length =
        snprintf(paths->users_path, sizeof(paths->users_path), "%s/users.tsv", args->data_dir);
    const int session_length =
        snprintf(paths->session_path, sizeof(paths->session_path), "%s/session.txt", args->data_dir);
    const int audit_length =
        snprintf(paths->audit_path, sizeof(paths->audit_path), "%s/audit.log", args->data_dir);

    return users_length >= 0 && (size_t)users_length < sizeof(paths->users_path) &&
           session_length >= 0 && (size_t)session_length < sizeof(paths->session_path) &&
           audit_length >= 0 && (size_t)audit_length < sizeof(paths->audit_path);
}

static bool cli_ensure_required(const char *value)
{
    return value != nullptr;
}

static bool cli_string_has_control_or_delimiter(const char *value)
{
    for (size_t index = 0u; value[index] != '\0'; ++index) {
        const unsigned char ch = (unsigned char)value[index];

        if (ch < 0x20u || ch == 0x7fu || ch == '\t') {
            return true;
        }
    }

    return false;
}

static bool cli_validate_login_id(const char *login_id)
{
    return auth_validate_login_id(login_id) == AUTH_VALIDATION_RESULT_OK &&
           !cli_string_has_control_or_delimiter(login_id);
}

static bool cli_validate_password(const char *password)
{
    return auth_validate_password(password) == AUTH_VALIDATION_RESULT_OK &&
           !cli_string_has_control_or_delimiter(password);
}

static bool cli_read_secret_line(FILE *input_stream, char *buffer, size_t buffer_size)
{
    size_t length = 0u;
    bool has_line_ending = false;

    if (input_stream == nullptr || buffer == nullptr || buffer_size == 0u) {
        return false;
    }

    if (fgets(buffer, (int)buffer_size, input_stream) == nullptr) {
        return false;
    }

    length = strlen(buffer);
    has_line_ending = length > 0u && buffer[length - 1u] == '\n';
    if (!has_line_ending && length == buffer_size - 1u) {
        return false;
    }

    while (length > 0u && (buffer[length - 1u] == '\n' || buffer[length - 1u] == '\r')) {
        buffer[length - 1u] = '\0';
        --length;
    }

    return true;
}

static bool cli_load_stdin_secret(FILE *input_stream,
                                  bool from_stdin,
                                  const char **target,
                                  char *buffer,
                                  size_t buffer_size)
{
    if (!from_stdin) {
        return false;
    }

    if (!cli_read_secret_line(input_stream, buffer, buffer_size)) {
        return false;
    }

    *target = buffer;
    return true;
}

static bool cli_ensure_data_dir(const cli_command_args_t *args)
{
    return util_file_io_ensure_directory(args->data_dir) == UTIL_FILE_IO_STATUS_OK;
}

static bool cli_load_state(const cli_command_paths_t *paths, auth_state_t *state)
{
    /* Persisted users and the persisted session must deserialize into one
     * coherent in-memory state before any command can proceed. */
    return storage_user_store_load(paths->users_path, state) == STORAGE_USER_STORE_STATUS_OK &&
           storage_session_store_load(paths->session_path, state) == STORAGE_SESSION_STORE_STATUS_OK;
}

static bool cli_save_state(const cli_command_paths_t *paths, const auth_state_t *state)
{
    return storage_user_store_save(paths->users_path, state) == STORAGE_USER_STORE_STATUS_OK &&
           storage_session_store_save(paths->session_path, state) == STORAGE_SESSION_STORE_STATUS_OK;
}

static const char *cli_register_result_string(auth_register_result_t result)
{
    switch (result) {
    case AUTH_REGISTER_RESULT_SUCCESS:
        return "success";
    case AUTH_REGISTER_RESULT_DUPLICATE:
        return "duplicate";
    default:
        return "system_error";
    }
}

static const char *cli_login_result_string(auth_login_result_t result)
{
    switch (result) {
    case AUTH_LOGIN_RESULT_SUCCESS:
        return "success";
    case AUTH_LOGIN_RESULT_UNKNOWN_USER:
        return "unknown_user";
    case AUTH_LOGIN_RESULT_LOCKED_OUT:
        return "locked_out";
    case AUTH_LOGIN_RESULT_WRONG_PASSWORD:
        return "wrong_password";
    case AUTH_LOGIN_RESULT_ALREADY_AUTHENTICATED:
        return "already_authenticated";
    default:
        return "system_error";
    }
}

static const char *cli_change_password_result_string(auth_change_password_result_t result)
{
    switch (result) {
    case AUTH_CHANGE_PASSWORD_RESULT_SUCCESS:
        return "success";
    case AUTH_CHANGE_PASSWORD_RESULT_UNAUTHORIZED:
        return "unauthorized";
    case AUTH_CHANGE_PASSWORD_RESULT_WRONG_PASSWORD:
        return "wrong_password";
    case AUTH_CHANGE_PASSWORD_RESULT_SYSTEM_ERROR:
        return "system_error";
    default:
        return "system_error";
    }
}

static storage_audit_event_type_t cli_login_audit_event_type(bool was_locked,
                                                             auth_login_result_t result)
{
    /* A new threshold-crossing lockout is the only login failure that changes
     * the audit event type from LoginFailure to Lock. */
    if (result == AUTH_LOGIN_RESULT_SUCCESS) {
        return STORAGE_AUDIT_EVENT_TYPE_LOGIN_SUCCESS;
    }

    if (!was_locked && result == AUTH_LOGIN_RESULT_LOCKED_OUT) {
        return STORAGE_AUDIT_EVENT_TYPE_LOCK;
    }

    return STORAGE_AUDIT_EVENT_TYPE_LOGIN_FAILURE;
}

static void cli_write_show_audit(FILE *output_stream, const storage_audit_log_t *log)
{
    cli_json_write_response_begin(output_stream, true, "success");
    fputs("{\"events\":[", output_stream);

    for (size_t index = 0; index < log->event_count; ++index) {
        const storage_audit_event_t *event = &log->events[index];

        if (index > 0u) {
            fputc(',', output_stream);
        }

        fputs("{\"timestamp\":", output_stream);
        cli_json_write_string(output_stream, event->timestamp);
        fputs(",\"event_type\":", output_stream);
        cli_json_write_string(output_stream, storage_audit_event_type_string(event->event_type));
        fputs(",\"login_id\":", output_stream);
        cli_json_write_string(output_stream, event->login_id);
        fputs(",\"result\":", output_stream);
        cli_json_write_string(output_stream, event->result);
        fputc('}', output_stream);
    }

    fputs("]}", output_stream);
    cli_json_write_response_end(output_stream, nullptr);
}

static void cli_write_show_metrics(FILE *output_stream, const storage_metrics_t *metrics)
{
    cli_json_write_response_begin(output_stream, true, "success");
    fprintf(output_stream,
            "{\"login_success_count\":%u,\"login_failure_count\":%u,\"lockout_count\":%u}",
            metrics->login_success_count,
            metrics->login_failure_count,
            metrics->lockout_count);
    cli_json_write_response_end(output_stream, nullptr);
}

int cli_command_runner_run_with_io(int argc,
                                   char **argv,
                                   FILE *input_stream,
                                   FILE *output_stream,
                                   FILE *error_stream)
{
    cli_command_args_t args;
    cli_command_paths_t paths;
    cli_secret_buffers_t secrets;
    auth_state_t state;
    const char *error_message = nullptr;

    (void)error_stream;

    if (!cli_parse_arguments(argc, argv, &args, &error_message)) {
        cli_json_write_null_response(output_stream, false, "invalid_request", error_message);
        return CLI_EXIT_CODE_USAGE_ERROR;
    }

    memset(&secrets, 0, sizeof(secrets));

    if (!cli_build_paths(&args, &paths)) {
        cli_json_write_null_response(output_stream, false, "system_error", "path construction failed");
        return CLI_EXIT_CODE_RUNTIME_ERROR;
    }

    if (!cli_string_equals(args.command, "show-audit") &&
        !cli_string_equals(args.command, "show-metrics") &&
        !cli_ensure_data_dir(&args)) {
        cli_json_write_null_response(output_stream, false, "system_error", "data directory setup failed");
        return CLI_EXIT_CODE_RUNTIME_ERROR;
    }

    if (cli_string_equals(args.command, "show-audit")) {
        storage_audit_log_t log;

        if (storage_audit_log_load(paths.audit_path, &log) != STORAGE_AUDIT_LOG_STATUS_OK) {
            cli_json_write_null_response(output_stream, false, "system_error", "failed to load audit log");
            return CLI_EXIT_CODE_RUNTIME_ERROR;
        }

        cli_write_show_audit(output_stream, &log);
        return CLI_EXIT_CODE_SUCCESS;
    }

    if (cli_string_equals(args.command, "show-metrics")) {
        storage_audit_log_t log;
        storage_metrics_t metrics;

        if (storage_audit_log_load(paths.audit_path, &log) != STORAGE_AUDIT_LOG_STATUS_OK) {
            cli_json_write_null_response(output_stream, false, "system_error", "failed to load audit log");
            return CLI_EXIT_CODE_RUNTIME_ERROR;
        }

        storage_audit_log_compute_metrics(&log, &metrics);
        cli_write_show_metrics(output_stream, &metrics);
        return CLI_EXIT_CODE_SUCCESS;
    }

    if (!cli_load_state(&paths, &state)) {
        cli_json_write_null_response(output_stream, false, "system_error", "failed to load state");
        return CLI_EXIT_CODE_RUNTIME_ERROR;
    }

    if (cli_string_equals(args.command, "register")) {
        auth_register_result_t result;
        const char *result_string = nullptr;
        bool ok = false;

        if (!cli_load_stdin_secret(input_stream,
                                   args.password_from_stdin,
                                   &args.password,
                                   secrets.password,
                                   sizeof(secrets.password))) {
            cli_json_write_null_response(output_stream, false, "invalid_request", "missing stdin password");
            return CLI_EXIT_CODE_USAGE_ERROR;
        }

        if (!cli_ensure_required(args.login_id) || !cli_ensure_required(args.password)) {
            cli_json_write_null_response(output_stream, false, "invalid_request", "missing register arguments");
            return CLI_EXIT_CODE_USAGE_ERROR;
        }

        if (!cli_validate_login_id(args.login_id) || !cli_validate_password(args.password)) {
            cli_json_write_null_response(output_stream, false, "invalid_request", "invalid register arguments");
            return CLI_EXIT_CODE_USAGE_ERROR;
        }

        result = auth_register(&state, args.login_id, args.password);
        result_string = cli_register_result_string(result);
        ok = result == AUTH_REGISTER_RESULT_SUCCESS;

        if (ok && !cli_save_state(&paths, &state)) {
            cli_json_write_null_response(output_stream, false, "system_error", "failed to persist state");
            return CLI_EXIT_CODE_RUNTIME_ERROR;
        }

        if (storage_audit_log_append(paths.audit_path,
                                     STORAGE_AUDIT_EVENT_TYPE_REGISTER,
                                     args.login_id,
                                     result_string) != STORAGE_AUDIT_LOG_STATUS_OK) {
            cli_json_write_null_response(output_stream, false, "system_error", "failed to append audit event");
            return CLI_EXIT_CODE_RUNTIME_ERROR;
        }

        cli_json_write_null_response(output_stream,
                                     ok,
                                     result_string,
                                     ok ? nullptr : "registration failed");
        /* Domain-level failures remain successful CLI executions because the
         * JSON contract carries the actual auth outcome. */
        return CLI_EXIT_CODE_SUCCESS;
    }

    if (cli_string_equals(args.command, "login")) {
        if (!cli_load_stdin_secret(input_stream,
                                   args.password_from_stdin,
                                   &args.password,
                                   secrets.password,
                                   sizeof(secrets.password))) {
            cli_json_write_null_response(output_stream, false, "invalid_request", "missing stdin password");
            return CLI_EXIT_CODE_USAGE_ERROR;
        }

        if (!cli_ensure_required(args.login_id) || !cli_ensure_required(args.password)) {
            cli_json_write_null_response(output_stream, false, "invalid_request", "missing login arguments");
            return CLI_EXIT_CODE_USAGE_ERROR;
        }

        if (!cli_validate_login_id(args.login_id) || !cli_validate_password(args.password)) {
            cli_json_write_null_response(output_stream, false, "invalid_request", "invalid login arguments");
            return CLI_EXIT_CODE_USAGE_ERROR;
        }

        {
            const auth_user_t *existing_user = auth_state_find_user(&state, args.login_id);
            const bool was_locked = existing_user != nullptr &&
                                    existing_user->lock_state == AUTH_LOCK_STATE_LOCKED;
            const auth_login_result_t result = auth_login(&state, args.login_id, args.password);
            const char *result_string = cli_login_result_string(result);
            const bool ok = result == AUTH_LOGIN_RESULT_SUCCESS;
            const bool state_changed = ok ||
                                       result == AUTH_LOGIN_RESULT_WRONG_PASSWORD ||
                                       (!was_locked && result == AUTH_LOGIN_RESULT_LOCKED_OUT);

            if (state_changed && !cli_save_state(&paths, &state)) {
                cli_json_write_null_response(output_stream, false, "system_error", "failed to persist state");
                return CLI_EXIT_CODE_RUNTIME_ERROR;
            }

            if (storage_audit_log_append(paths.audit_path,
                                         cli_login_audit_event_type(was_locked, result),
                                         args.login_id,
                                         result_string) != STORAGE_AUDIT_LOG_STATUS_OK) {
                cli_json_write_null_response(output_stream, false, "system_error", "failed to append audit event");
                return CLI_EXIT_CODE_RUNTIME_ERROR;
            }

            cli_json_write_null_response(output_stream, ok, result_string, ok ? nullptr : "login failed");
            return CLI_EXIT_CODE_SUCCESS;
        }
    }

    if (cli_string_equals(args.command, "change-password")) {
        if (!cli_load_stdin_secret(input_stream,
                                   args.old_password_from_stdin,
                                   &args.old_password,
                                   secrets.old_password,
                                   sizeof(secrets.old_password)) ||
            !cli_load_stdin_secret(input_stream,
                                   args.new_password_from_stdin,
                                   &args.new_password,
                                   secrets.new_password,
                                   sizeof(secrets.new_password))) {
            cli_json_write_null_response(output_stream, false, "invalid_request", "missing stdin password");
            return CLI_EXIT_CODE_USAGE_ERROR;
        }

        if (!cli_ensure_required(args.old_password) || !cli_ensure_required(args.new_password)) {
            cli_json_write_null_response(output_stream, false, "invalid_request", "missing password arguments");
            return CLI_EXIT_CODE_USAGE_ERROR;
        }

        if (!cli_validate_password(args.old_password) || !cli_validate_password(args.new_password)) {
            cli_json_write_null_response(output_stream, false, "invalid_request", "invalid password arguments");
            return CLI_EXIT_CODE_USAGE_ERROR;
        }

        {
            const auth_change_password_result_t result =
                auth_change_password(&state, args.old_password, args.new_password);
            const char *result_string = cli_change_password_result_string(result);
            const bool ok = result == AUTH_CHANGE_PASSWORD_RESULT_SUCCESS;
            const char *login_id = state.authenticated ? state.authenticated_login_id : "";

            if (ok && !cli_save_state(&paths, &state)) {
                cli_json_write_null_response(output_stream, false, "system_error", "failed to persist state");
                return CLI_EXIT_CODE_RUNTIME_ERROR;
            }

            if (storage_audit_log_append(paths.audit_path,
                                         STORAGE_AUDIT_EVENT_TYPE_PASSWORD_CHANGE,
                                         login_id,
                                         result_string) != STORAGE_AUDIT_LOG_STATUS_OK) {
                cli_json_write_null_response(output_stream, false, "system_error", "failed to append audit event");
                return CLI_EXIT_CODE_RUNTIME_ERROR;
            }

            cli_json_write_null_response(output_stream,
                                         ok,
                                         result_string,
                                         ok ? nullptr : "password change failed");
            return CLI_EXIT_CODE_SUCCESS;
        }
    }

    if (cli_string_equals(args.command, "logout")) {
        char audit_login_id[AUTH_LOGIN_ID_MAX_LENGTH + 1u];

        memset(audit_login_id, 0, sizeof(audit_login_id));
        if (state.authenticated) {
            memcpy(audit_login_id, state.authenticated_login_id, sizeof(audit_login_id));
        }

        (void)auth_logout(&state);
        if (!cli_save_state(&paths, &state)) {
            cli_json_write_null_response(output_stream, false, "system_error", "failed to persist state");
            return CLI_EXIT_CODE_RUNTIME_ERROR;
        }

        if (storage_audit_log_append(paths.audit_path,
                                     STORAGE_AUDIT_EVENT_TYPE_LOGOUT,
                                     audit_login_id,
                                     "success") != STORAGE_AUDIT_LOG_STATUS_OK) {
            cli_json_write_null_response(output_stream, false, "system_error", "failed to append audit event");
            return CLI_EXIT_CODE_RUNTIME_ERROR;
        }

        cli_json_write_null_response(output_stream, true, "success", nullptr);
        return CLI_EXIT_CODE_SUCCESS;
    }

    cli_json_write_null_response(output_stream, false, "invalid_request", "unknown command");
    return CLI_EXIT_CODE_USAGE_ERROR;
}

int cli_command_runner_run_with_streams(int argc,
                                        char **argv,
                                        FILE *output_stream,
                                        FILE *error_stream)
{
    return cli_command_runner_run_with_io(argc, argv, stdin, output_stream, error_stream);
}

int cli_command_runner_run(int argc, char **argv)
{
    return cli_command_runner_run_with_io(argc, argv, stdin, stdout, stderr);
}

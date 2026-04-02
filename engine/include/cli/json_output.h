#ifndef VERIFIABLE_AUTH_PLATFORM_ENGINE_CLI_JSON_OUTPUT_H
#define VERIFIABLE_AUTH_PLATFORM_ENGINE_CLI_JSON_OUTPUT_H

#include <stdbool.h>
#include <stdio.h>

/**
 * @brief Write one JSON string value with minimal escaping.
 *
 * @param stream Output stream receiving JSON text.
 * @param value UTF-8 string value to serialize.
 */
void cli_json_write_string(FILE *stream, const char *value);

/**
 * @brief Write the stable response prefix shared by all CLI commands.
 *
 * The caller remains responsible for writing the `data` payload and closing
 * the response with `cli_json_write_response_end`.
 *
 * @param stream Output stream receiving JSON text.
 * @param ok Stable `ok` field value for the response.
 * @param result Stable machine-readable result code.
 */
void cli_json_write_response_begin(FILE *stream, bool ok, const char *result);

/**
 * @brief Finish a CLI JSON response and write the `error` field.
 *
 * @param stream Output stream receiving JSON text.
 * @param error_message Error message for the response, or nullptr for `null`.
 */
void cli_json_write_response_end(FILE *stream, const char *error_message);

/**
 * @brief Write a full CLI response whose `data` field is `null`.
 *
 * @param stream Output stream receiving JSON text.
 * @param ok Stable `ok` field value for the response.
 * @param result Stable machine-readable result code.
 * @param error_message Error message for the response, or nullptr for `null`.
 */
void cli_json_write_null_response(FILE *stream,
                                  bool ok,
                                  const char *result,
                                  const char *error_message);

#endif

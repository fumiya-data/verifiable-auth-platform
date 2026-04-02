#include "cli/json_output.h"

void cli_json_write_string(FILE *stream, const char *value)
{
    fputc('"', stream);

    for (size_t index = 0; value[index] != '\0'; ++index) {
        switch (value[index]) {
        case '\\':
            fputs("\\\\", stream);
            break;
        case '"':
            fputs("\\\"", stream);
            break;
        case '\n':
            fputs("\\n", stream);
            break;
        case '\r':
            fputs("\\r", stream);
            break;
        case '\t':
            fputs("\\t", stream);
            break;
        default:
            fputc(value[index], stream);
            break;
        }
    }

    fputc('"', stream);
}

void cli_json_write_response_begin(FILE *stream, bool ok, const char *result)
{
    fputs("{\"ok\":", stream);
    fputs(ok ? "true" : "false", stream);
    fputs(",\"result\":", stream);
    cli_json_write_string(stream, result);
    fputs(",\"data\":", stream);
}

void cli_json_write_response_end(FILE *stream, const char *error_message)
{
    fputs(",\"error\":", stream);
    if (error_message == nullptr) {
        fputs("null", stream);
    } else {
        fputs("{\"message\":", stream);
        cli_json_write_string(stream, error_message);
        fputc('}', stream);
    }

    fputs("}\n", stream);
}

void cli_json_write_null_response(FILE *stream,
                                  bool ok,
                                  const char *result,
                                  const char *error_message)
{
    cli_json_write_response_begin(stream, ok, result);
    fputs("null", stream);
    cli_json_write_response_end(stream, error_message);
}

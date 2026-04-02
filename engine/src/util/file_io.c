#include "util/file_io.h"

#include <errno.h>
#include <stdio.h>
#include <string.h>

#if defined(_WIN32)
#include <direct.h>
#else
#include <sys/stat.h>
#include <sys/types.h>
#endif

bool util_file_io_exists(const char *path)
{
    FILE *stream = fopen(path, "rb");

    if (stream == nullptr) {
        return false;
    }

    fclose(stream);
    return true;
}

util_file_io_status_t util_file_io_ensure_directory(const char *path)
{
    if (path == nullptr) {
        return UTIL_FILE_IO_STATUS_IO_ERROR;
    }

#if defined(_WIN32)
    if (_mkdir(path) == 0 || errno == EEXIST) {
        return UTIL_FILE_IO_STATUS_OK;
    }
#else
    if (mkdir(path, 0777) == 0 || errno == EEXIST) {
        return UTIL_FILE_IO_STATUS_OK;
    }
#endif

    return UTIL_FILE_IO_STATUS_IO_ERROR;
}

util_file_io_status_t util_file_io_read_text(const char *path,
                                             char *output,
                                             size_t output_size)
{
    FILE *stream = nullptr;
    size_t total_read = 0u;

    if (path == nullptr || output == nullptr || output_size == 0u) {
        return UTIL_FILE_IO_STATUS_IO_ERROR;
    }

    stream = fopen(path, "rb");
    if (stream == nullptr) {
        return errno == ENOENT ? UTIL_FILE_IO_STATUS_NOT_FOUND
                               : UTIL_FILE_IO_STATUS_IO_ERROR;
    }

    while (!feof(stream)) {
        const size_t available = output_size - total_read - 1u;
        const size_t chunk = fread(output + total_read, 1u, available, stream);
        total_read += chunk;

        if (available == 0u && !feof(stream)) {
            fclose(stream);
            return UTIL_FILE_IO_STATUS_BUFFER_TOO_SMALL;
        }

        if (chunk == 0u) {
            break;
        }
    }

    if (ferror(stream) != 0) {
        fclose(stream);
        return UTIL_FILE_IO_STATUS_IO_ERROR;
    }

    output[total_read] = '\0';
    fclose(stream);
    return UTIL_FILE_IO_STATUS_OK;
}

static util_file_io_status_t util_file_io_write_mode(const char *path,
                                                     const char *text,
                                                     const char *mode)
{
    FILE *stream = fopen(path, mode);
    const size_t text_length = strlen(text);

    if (stream == nullptr) {
        return UTIL_FILE_IO_STATUS_IO_ERROR;
    }

    if (text_length > 0u && fwrite(text, 1u, text_length, stream) != text_length) {
        fclose(stream);
        return UTIL_FILE_IO_STATUS_IO_ERROR;
    }

    if (fclose(stream) != 0) {
        return UTIL_FILE_IO_STATUS_IO_ERROR;
    }

    return UTIL_FILE_IO_STATUS_OK;
}

util_file_io_status_t util_file_io_write_text(const char *path, const char *text)
{
    if (path == nullptr || text == nullptr) {
        return UTIL_FILE_IO_STATUS_IO_ERROR;
    }

    return util_file_io_write_mode(path, text, "wb");
}

util_file_io_status_t util_file_io_append_text(const char *path, const char *text)
{
    if (path == nullptr || text == nullptr) {
        return UTIL_FILE_IO_STATUS_IO_ERROR;
    }

    return util_file_io_write_mode(path, text, "ab");
}

const char *util_file_io_status_string(util_file_io_status_t status)
{
    switch (status) {
    case UTIL_FILE_IO_STATUS_OK:
        return "ok";
    case UTIL_FILE_IO_STATUS_NOT_FOUND:
        return "not_found";
    case UTIL_FILE_IO_STATUS_BUFFER_TOO_SMALL:
        return "buffer_too_small";
    case UTIL_FILE_IO_STATUS_IO_ERROR:
        return "io_error";
    default:
        return "unknown_file_io_status";
    }
}

#ifndef VERIFIABLE_AUTH_PLATFORM_ENGINE_UTIL_FILE_IO_H
#define VERIFIABLE_AUTH_PLATFORM_ENGINE_UTIL_FILE_IO_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Stable status codes returned by lightweight file helpers.
 */
typedef enum util_file_io_status {
    /** The requested operation completed successfully. */
    UTIL_FILE_IO_STATUS_OK = 0,
    /** The requested file did not exist. */
    UTIL_FILE_IO_STATUS_NOT_FOUND,
    /** The caller-provided destination buffer was too small. */
    UTIL_FILE_IO_STATUS_BUFFER_TOO_SMALL,
    /** The underlying file or directory operation failed. */
    UTIL_FILE_IO_STATUS_IO_ERROR,
} util_file_io_status_t;

/**
 * @brief Return whether a file exists and can be opened for reading.
 *
 * @param path File path to probe.
 * @return true when the file exists and can be opened.
 */
bool util_file_io_exists(const char *path);

/**
 * @brief Ensure that one directory exists.
 *
 * @param path Directory path to create if missing.
 * @return Status describing success or directory creation failure.
 */
util_file_io_status_t util_file_io_ensure_directory(const char *path);

/**
 * @brief Read a text file into a caller-provided buffer.
 *
 * The resulting buffer is always null-terminated on success.
 *
 * @param path File path to read.
 * @param output Destination buffer.
 * @param output_size Size of @p output in bytes.
 * @return Status describing success, missing file, or I/O failure.
 */
util_file_io_status_t util_file_io_read_text(const char *path,
                                             char *output,
                                             size_t output_size);

/**
 * @brief Overwrite a text file with the supplied text.
 *
 * @param path Destination file path.
 * @param text Text to write.
 * @return Status describing success or I/O failure.
 */
util_file_io_status_t util_file_io_write_text(const char *path, const char *text);

/**
 * @brief Append text to the end of a file.
 *
 * @param path Destination file path.
 * @param text Text to append.
 * @return Status describing success or I/O failure.
 */
util_file_io_status_t util_file_io_append_text(const char *path, const char *text);

/**
 * @brief Convert a file helper status code to a stable string.
 *
 * @param status File helper status code.
 * @return Stable string literal for diagnostics and JSON serialization.
 */
const char *util_file_io_status_string(util_file_io_status_t status);

#endif

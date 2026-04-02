#ifndef VERIFIABLE_AUTH_PLATFORM_ENGINE_UTIL_MEMORY_H
#define VERIFIABLE_AUTH_PLATFORM_ENGINE_UTIL_MEMORY_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Best-effort secure zeroing helper for sensitive buffers.
 *
 * @param buffer Buffer to overwrite.
 * @param length Number of bytes to clear.
 */
void util_memory_secure_zero(void *buffer, size_t length);

/**
 * @brief Copy a null-terminated C string into a fixed-size destination.
 *
 * @param destination Destination buffer.
 * @param destination_size Size of @p destination in bytes.
 * @param source Source C string.
 * @return true when the destination buffer was large enough.
 */
bool util_memory_copy_cstr(char *destination, size_t destination_size, const char *source);

#endif

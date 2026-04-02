#include "util/memory.h"

#include <string.h>

void util_memory_secure_zero(void *buffer, size_t length)
{
    volatile unsigned char *cursor = buffer;

    while (length > 0u) {
        *cursor = 0u;
        ++cursor;
        --length;
    }
}

bool util_memory_copy_cstr(char *destination, size_t destination_size, const char *source)
{
    const size_t source_length = strlen(source);

    if (destination == nullptr || source == nullptr || source_length >= destination_size) {
        return false;
    }

    memcpy(destination, source, source_length + 1u);
    return true;
}

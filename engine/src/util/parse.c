#include "util/parse.h"

#include <ctype.h>

bool util_parse_u32(util_string_view_t view, uint32_t *output)
{
    uint32_t value = 0u;

    if (output == nullptr || view.length == 0u) {
        return false;
    }

    for (size_t index = 0; index < view.length; ++index) {
        const unsigned char current = (unsigned char)view.data[index];

        if (!isdigit(current)) {
            return false;
        }

        value = (value * 10u) + (uint32_t)(current - (unsigned char)'0');
    }

    *output = value;
    return true;
}

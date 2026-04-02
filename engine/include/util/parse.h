#ifndef VERIFIABLE_AUTH_PLATFORM_ENGINE_UTIL_PARSE_H
#define VERIFIABLE_AUTH_PLATFORM_ENGINE_UTIL_PARSE_H

#include <stdbool.h>
#include <stdint.h>

#include "util/string_view.h"

/**
 * @brief Parse one unsigned 32-bit integer from a string view.
 *
 * @param view Source decimal text.
 * @param output Parsed numeric value.
 * @return true when parsing succeeded without overflow or trailing junk.
 */
bool util_parse_u32(util_string_view_t view, uint32_t *output);

#endif

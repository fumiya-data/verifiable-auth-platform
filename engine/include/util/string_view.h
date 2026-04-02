#ifndef VERIFIABLE_AUTH_PLATFORM_ENGINE_UTIL_STRING_VIEW_H
#define VERIFIABLE_AUTH_PLATFORM_ENGINE_UTIL_STRING_VIEW_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Non-owning view over a contiguous character range.
 */
typedef struct util_string_view {
    /** Pointer to the first character in the view. */
    const char *data;
    /** Number of characters in the view. */
    size_t length;
} util_string_view_t;

/**
 * @brief Create a view over a null-terminated C string.
 *
 * @param text Source C string.
 * @return View spanning the full string.
 */
util_string_view_t util_string_view_from_cstr(const char *text);

/**
 * @brief Remove trailing CR and LF characters from a view.
 *
 * @param view Input view that may end with line terminators.
 * @return Trimmed view without trailing CR or LF characters.
 */
util_string_view_t util_string_view_trim_line_endings(util_string_view_t view);

/**
 * @brief Compare two string views for exact byte equality.
 *
 * @param left Left-hand view.
 * @param right Right-hand view.
 * @return true when both views contain the same bytes.
 */
bool util_string_view_equal(util_string_view_t left, util_string_view_t right);

/**
 * @brief Compare a string view with a null-terminated C string.
 *
 * @param left Left-hand view.
 * @param right Right-hand C string.
 * @return true when both strings contain the same bytes.
 */
bool util_string_view_equal_cstr(util_string_view_t left, const char *right);

/**
 * @brief Split a view at the first delimiter occurrence.
 *
 * @param view Input view to split.
 * @param delimiter Delimiter character to search for.
 * @param left Output view before the delimiter.
 * @param right Output view after the delimiter.
 * @return true when the delimiter was found and both outputs were assigned.
 */
bool util_string_view_split_once(util_string_view_t view,
                                 char delimiter,
                                 util_string_view_t *left,
                                 util_string_view_t *right);

/**
 * @brief Copy a string view into a null-terminated destination buffer.
 *
 * @param view Source view to copy.
 * @param output Destination buffer.
 * @param output_size Size of @p output in bytes.
 * @return true when the destination buffer was large enough.
 */
bool util_string_view_copy(util_string_view_t view, char *output, size_t output_size);

#endif

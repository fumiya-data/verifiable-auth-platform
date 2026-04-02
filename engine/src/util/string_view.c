#include "util/string_view.h"

#include <string.h>

util_string_view_t util_string_view_from_cstr(const char *text)
{
    util_string_view_t view = {0};

    if (text == nullptr) {
        return view;
    }

    view.data = text;
    view.length = strlen(text);
    return view;
}

util_string_view_t util_string_view_trim_line_endings(util_string_view_t view)
{
    while (view.length > 0u) {
        const char current = view.data[view.length - 1u];
        if (current != '\n' && current != '\r') {
            break;
        }

        view.length -= 1u;
    }

    return view;
}

bool util_string_view_equal(util_string_view_t left, util_string_view_t right)
{
    if (left.length != right.length) {
        return false;
    }

    if (left.length == 0u) {
        return true;
    }

    return memcmp(left.data, right.data, left.length) == 0;
}

bool util_string_view_equal_cstr(util_string_view_t left, const char *right)
{
    return util_string_view_equal(left, util_string_view_from_cstr(right));
}

bool util_string_view_split_once(util_string_view_t view,
                                 char delimiter,
                                 util_string_view_t *left,
                                 util_string_view_t *right)
{
    for (size_t index = 0; index < view.length; ++index) {
        if (view.data[index] == delimiter) {
            if (left != nullptr) {
                left->data = view.data;
                left->length = index;
            }

            if (right != nullptr) {
                right->data = view.data + index + 1u;
                right->length = view.length - index - 1u;
            }

            return true;
        }
    }

    return false;
}

bool util_string_view_copy(util_string_view_t view, char *output, size_t output_size)
{
    if (output == nullptr || output_size == 0u || view.length >= output_size) {
        return false;
    }

    if (view.length > 0u) {
        memcpy(output, view.data, view.length);
    }

    output[view.length] = '\0';
    return true;
}

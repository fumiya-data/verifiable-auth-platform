#ifndef VERIFIABLE_AUTH_PLATFORM_ENGINE_TEST_SUPPORT_H
#define VERIFIABLE_AUTH_PLATFORM_ENGINE_TEST_SUPPORT_H

#include <stdio.h>
#include <stdlib.h>

#define TEST_CHECK(condition)                                                                    \
    do {                                                                                         \
        if (!(condition)) {                                                                      \
            fprintf(stderr, "%s:%d: TEST_CHECK failed: %s\n", __FILE__, __LINE__, #condition);  \
            exit(EXIT_FAILURE);                                                                  \
        }                                                                                        \
    } while (0)

#endif

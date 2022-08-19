#include "../utility.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>

// FIXME Multiple calls to snprintf might not be optimal.
const char* CHIPC_CreateFormattedString(const char* fmt, ...) {
    va_list varargs;
    va_start(varargs, fmt);

    uint64_t amount_needed = vsnprintf(NULL, 0, fmt, varargs);
    const char* str = malloc(sizeof *str * (amount_needed + 1));
    if (!str)
        return NULL;

    uint64_t amount_written = vsnprintf(str, amount_needed + 1, fmt, varargs);

    // This should be impossible, but should be checked for anyway.
    if (amount_written > amount_needed)
        return NULL;

    va_end(varargs);
    return str;
}

// FIXME Error-prone if used on a string that isn't allocated with malloc.
void CHIPC_DestroyFormattedString(const char* str) {
    if (str)
        free(str);
}
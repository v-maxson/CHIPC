#ifndef CHIPC_UTILITY_H
#define CHIPC_UTILITY_H

#include <stdint.h>
#include <stdbool.h>

/**
 * Get the size of a file in bytes.
 * @param file_path The path to the file.
 * @param result A optional pointer to a bool which will be set to true if the operation succeeded, or false otherwise.
 * @return The size of the file in bytes.
 */
uint64_t CHIPC_GetFileSize(const char* file_path, bool* result);

/**
 * Formats the given format string.
 * @param fmt The format string.
 * @return The formatted string, or NULL if allocation failed. Warning: This string must be destroyed with CHIPC_DestroyFormattedString().
 */
const char* CHIPC_FormatString(const char* fmt, ...);

/**
 * Destroys a formatted string.
 * @param str The formatted string.
 */
void CHIPC_DestroyFormattedString(const char* str);

#endif //CHIPC_UTILITY_H

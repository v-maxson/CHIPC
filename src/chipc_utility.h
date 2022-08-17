#ifndef CHIPC_CHIPC_UTILITY_H
#define CHIPC_CHIPC_UTILITY_H

#include <stdint.h>
#include <stdbool.h>

/**
 * Get the size of a file in bytes.
 * @param file_path The path to the file.
 * @param result A optional pointer to a bool which will be set to true if the operation succeeded, or false otherwise.
 * @return The size of the file in bytes.
 */
uint64_t CHIPC_GetFileSize(const char* file_path, bool* result);

#endif //CHIPC_CHIPC_UTILITY_H

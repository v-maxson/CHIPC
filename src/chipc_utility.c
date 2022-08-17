#include "chipc_utility.h"

// Disclaimer: This implementation requires a POSIX Compliant system to compile.
// This works on most popular systems (Linux, Windows, Mac), but not all.
#include <sys/stat.h>

uint64_t CHIPC_GetFileSize(const char *file_path, bool *result) {
    struct stat file_stat;
    if (stat(file_path, &file_stat) < 0) {
        if (result) *result = false;
        return 0;
    }

    if (result) *result = true;
    return file_stat.st_size;
}

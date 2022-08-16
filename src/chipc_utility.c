#include "chipc_utility.h"

#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

uint64_t CHIPC_GetFileSize(const char *file_path, bool *result) {
    OFSTRUCT of;
    HFILE file = OpenFile(file_path, &of, 0);
    if (!file) {
        if (result) *result = false;
        return 0;
    }

    DWORD size = GetFileSize((HANDLE)file, NULL);
    CloseHandle((HANDLE)file);

    if (result) *result = true;
    return size;
}

#else
// TODO: CHIPC_GetFileSize Linux/POSIX implementation.

uint64_t CHIPC_GetFileSize(const char *file_path, bool *result) {
    if (result) *result = false;
    return 0;
}
#endif

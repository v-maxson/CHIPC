#include "utility/utility.h"
#include <stdio.h>

int main(void) {
    printf("%llu", CHIPC_GetFileSize("CHIPC_FileSizeTest.exe", NULL));
}
#include "utility/utility.h"
#include <stdio.h>

int main(void) {
    const char* str = CHIPC_CreateFormattedString("Hello, %s!\n", "World");
    puts(str);
    CHIPC_DestroyFormattedString(str);
}
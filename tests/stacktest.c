#include <stack.h>
#include <stdio.h>

int main(void) {
    CHIPC_Stack stack = CHIPC_CreateStack();
    CHIPC_PushStack(&stack, 100);

    printf("%d", CHIPC_PeekStack(&stack, NULL));
}
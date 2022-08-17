#include <stack.h>
#include <stdio.h>

int main(void) {
    CHIPC_Stack stack = CHIPC_CreateStack(16);
    CHIPC_StackPush(&stack, 150);
    CHIPC_StackPush(&stack, 190);

    printf("1: %d\n", CHIPC_StackPop(&stack, NULL));
    printf("2: %d\n", CHIPC_StackPop(&stack, NULL));
    printf("3: %d\n", CHIPC_StackPop(&stack, NULL));

    CHIPC_DestroyStack(&stack);
}
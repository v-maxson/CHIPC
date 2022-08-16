#include "stack.h"

CHIPC_Stack CHIPC_CreateStack() {
    return (CHIPC_Stack) { .arr = {0}, .stack_pointer = -1 };
}

inline int64_t CHIPC_GetStackSize(CHIPC_Stack *stack) {
    return stack->stack_pointer + 1;
}

bool CHIPC_PushStack(CHIPC_Stack *stack, CHIPC_STACKTYPE value) {
    // Add the item to the current stack level and iterate the stack pointer.
    if (CHIPC_GetStackSize(stack) < CHIPC_STACKSIZE) {
        stack->arr[stack->stack_pointer++] = value;
        return true;
    } else
        return false;
}

CHIPC_STACKTYPE CHIPC_PopStack(CHIPC_Stack *stack, bool *result) {
    // Pop the value off of the stack (if one exists).
    if (stack->stack_pointer > -1) {
        if (result) *result = true;
        return stack->arr[--stack->stack_pointer];
    } else {
        if (result) *result = false;
        return 0;
    }
}

CHIPC_STACKTYPE CHIPC_PeekStack(const CHIPC_Stack *stack, bool *result) {
    // Peek the value on top of the stack (if one exists).
    if (stack->stack_pointer > -1) {
        if (result) *result = true;
        return stack->arr[stack->stack_pointer];
    } else {
        if (result) *result = false;
        return 0;
    }
}

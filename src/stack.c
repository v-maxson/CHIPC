#include "stack.h"
#include <stdlib.h>

#define CHIPC_DEFAULT 0

CHIPC_Stack CHIPC_CreateStack(int64_t capacity) {
    CHIPC_Stack stack = {
        .capacity = capacity,
        .top = -1,
        .array = malloc(capacity * sizeof(CHIPC_Stack_t))
    };

    return stack;
}

void CHIPC_DestroyStack(CHIPC_Stack *stack) {
    free(stack->array);
}

bool CHIPC_StackIsFull(const CHIPC_Stack *stack) {
    return stack->top == stack->capacity - 1;
}

bool CHIPC_StackIsEmpty(const CHIPC_Stack *stack) {
    return stack->top == -1;
}

int64_t CHIPC_StackCapacity(const CHIPC_Stack *stack) {
    return stack->capacity;
}

int64_t CHIPC_StackCurrentSize(const CHIPC_Stack *stack) {
    return stack->top + 1;
}

bool CHIPC_StackPush(CHIPC_Stack *stack, CHIPC_Stack_t value) {
    if (CHIPC_StackIsFull(stack))
        return false;

    stack->array[++stack->top] = value;
    return true;
}

CHIPC_Stack_t CHIPC_StackPop(CHIPC_Stack *stack, bool *result) {
    if (CHIPC_StackIsEmpty(stack)) {
        if (result) *result = false;
        return CHIPC_DEFAULT;
    }

    if (result) *result = true;
    return stack->array[stack->top--];
}

CHIPC_Stack_t CHIPC_StackPeek(CHIPC_Stack *stack, bool *result) {
    if (CHIPC_StackIsEmpty(stack)) {
        if (result) *result = false;
        return CHIPC_DEFAULT;
    }

    if (result) *result = true;
    return stack->array[stack->top];
}

#ifndef CHIPC_STACK_H
#define CHIPC_STACK_H

#include <stdint.h>
#include <stdbool.h>

#define CHIPC_STACKSIZE 16
#define CHIPC_STACKTYPE uint16_t

typedef struct CHIPC_Stack {
    CHIPC_STACKTYPE arr[CHIPC_STACKSIZE];
    int64_t stack_pointer;
} CHIPC_Stack;

CHIPC_Stack CHIPC_CreateStack();

/**
 * Retrieve the size of the stack.
 * @param stack The stack to perform this operation on.
 * @return The size of the stack.
 */
inline int64_t CHIPC_GetStackSize(CHIPC_Stack* stack);

/**
 * Pushes an item onto the stack.
 * @return A bool indicating failure.
 */
bool CHIPC_PushStack(CHIPC_Stack* stack, CHIPC_STACKTYPE value);

/**
 * Pops an item off of the stack.
 * @param stack The stack to perform this operation on.
 * @param result A pointer to a uint8_t to pipe the result into. Optional.
 * @return The popped value. If `result` indicates failure, this value will be 0.
 */
CHIPC_STACKTYPE CHIPC_PopStack(CHIPC_Stack* stack, bool* result);

/**
 * Peeks the top most item of the stack.
 * @param stack The stack to perform this operation on.
 * @param result A pointer to a uint8_t to pipe the result into. Optional.
 * @return The peeked value. If `result` indicates failure, this value will be 0.
 */
CHIPC_STACKTYPE CHIPC_PeekStack(const CHIPC_Stack* stack, bool* result);

#endif //CHIPC_STACK_H

#ifndef CHIPC_STACK_H
#define CHIPC_STACK_H

#include <stdint.h>
#include <stdbool.h>

typedef uint16_t CHIPC_Stack_t;

/**
 * A simple Stack data structure for storing data in a
 * first in, first out manner.
 */
typedef struct CHIPC_Stack {
    int64_t top;
    int64_t capacity;

    CHIPC_Stack_t* array;
} CHIPC_Stack;

/**
 * Creates a Stack structure with the given capacity with each element being the given size.
 * @param capacity The amount of elements to store.
 * @param size_of_element The size of each element being stored.
 * @return The created CHIPC_Stack.
 */
CHIPC_Stack CHIPC_CreateStack(int64_t capacity);

/**
 * Destroys a CHIPC_Stack.
 * @param stack The CHIPC_Stack to destroy.
 */
void CHIPC_DestroyStack(CHIPC_Stack* stack);

/**
 * Determines if the provided CHIPC_Stack is full.
 * @param stack The CHIPC_Stack to check.
 * @return True if the provided CHIPC_Stack is full.
 */
bool CHIPC_StackIsFull(const CHIPC_Stack* stack);

/**
 * Determines if the provided CHIPC_Stack is empty.
 * @param stack The CHIPC_Stack to check.
 * @return True if the provided CHIPC_Stack is empty.
 */
bool CHIPC_StackIsEmpty(const CHIPC_Stack* stack);

/**
 * Retrieves the full capacity of the provided CHIPC_Stack.
 * @param stack The CHIPC_Stack to check.
 * @return The capacity of the provided CHIPC_Stack.
 */
int64_t CHIPC_StackCapacity(const CHIPC_Stack* stack);

/**
 * Retrieves the amount of elements currently in use by the provided CHIPC_Stack.
 * @param stack The CHIPC_Stack to check.
 * @return The amount of elements currently in use by the provided CHIPC_Stack.
 */
int64_t CHIPC_StackCurrentSize(const CHIPC_Stack* stack);

/**
 * Push a value onto the provided CHIPC_Stack.
 * @param stack The CHIPC_Stack to push the value onto.
 * @param value The value to push onto the CHIPC_Stack.
 * @return True if the operation succeeded.
 */
bool CHIPC_StackPush(CHIPC_Stack* stack, CHIPC_Stack_t value);

/**
 * Pop the topmost value off of the provided CHIPC_Stack.
 * @param stack The CHIPC_Stack to pop the value off of.
 * @param result A optional pointer to a bool which will be set to true if the operation succeeded, or false otherwise.
 * @return The value that was popped off of the stack.
 */
CHIPC_Stack_t CHIPC_StackPop(CHIPC_Stack* stack, bool* result);

/**
 * Peeks the value at the top of the provided CHIPC_Stack.
 * @param stack The CHIPC_Stack to peek.
 * @param result A optional pointer to a bool which will be set to true if the operation succeeded, or false otherwise.
 * @return The value currently at the top of the provided CHIPC_Stack.
 */
CHIPC_Stack_t CHIPC_StackPeek(CHIPC_Stack* stack, bool* result);

#endif //CHIPC_STACK_H

#include "instruction.h"

#include <stdio.h>

CHIPC_Instruction CHIPC_CreateInstruction(uint16_t value) {
    return (CHIPC_Instruction) { .full = value };
}

CHIPC_Instruction CHIPC_CreateInstructionFromPair(uint8_t high, uint8_t low) {
    return (CHIPC_Instruction) { .jj = high, .kk = low };
}

const char* CHIPC_GetInstructionString(CHIPC_Instruction* instruction) {
    char string[107] = { 0 };

    sprintf(
        &string, 
        "{ Full: %#06X, Op: %#03X, X: %#03X, Y: %#03X, N: %#03X, KK: %#04X, NNN: %#05X }",
        instruction->full, instruction->op, 
        instruction->x, instruction->y, instruction->n, 
        instruction->kk, instruction->nnn);

    return string;
}

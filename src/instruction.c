#include "instruction.h"

#include <stdio.h>

CHIPC_Instruction CHIPC_CreateInstruction(uint16_t value) {
    return (CHIPC_Instruction) { .full = value };
}

CHIPC_Instruction CHIPC_CreateInstructionFromPair(uint8_t high, uint8_t low) {
    return (CHIPC_Instruction) { .jj = high, .kk = low };
}

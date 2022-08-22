#ifndef CHIPC_INSTRUCTION_H
#define CHIPC_INSTRUCTION_H

#include <stdint.h>

/**
 * The CHIP-8 instruction data structure.
 */
// I am well aware that this is technically undefined behavior.
// However, I am unaware of a compiler that this particular instance
// *doesn't* work with.
typedef struct CHIPC_Instruction {
    union {
        uint16_t full;
        struct { uint8_t n:4; uint8_t y:4; uint8_t x:4; uint8_t op:4; };
        struct { uint8_t kk:8; uint8_t jj:8; };
        struct { uint16_t nnn:12; };
    };
} CHIPC_Instruction;

/**
 * Create a new CHIPC_Instruction from the provided value.
 */
CHIPC_Instruction CHIPC_CreateInstruction(uint16_t value);

/**
 * Create a CHIPC_Instruction from the provided bytes.
 * @param high The high byte.
 * @param low The low byte.
 */
CHIPC_Instruction CHIPC_CreateInstructionFromPair(uint8_t high, uint8_t low);

#endif //CHIPC_INSTRUCTION_H

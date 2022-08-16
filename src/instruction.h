#ifndef CHIPC_INSTRUCTION_H
#define CHIPC_INSTRUCTION_H

#include <stdint.h>

typedef struct CHIPC_Instruction {
    union {
        uint16_t full;
        struct { uint8_t n:4; uint8_t y:4; uint8_t x:4; uint8_t op:4; };
        struct { uint8_t kk:8; uint8_t jj:8; };
        struct { uint16_t nnn:12; };
    };
} CHIPC_Instruction;

CHIPC_Instruction CHIPC_CreateInstruction(uint16_t value);
CHIPC_Instruction CHIPC_CreateInstructionFromPair(uint8_t high, uint8_t low);
const char* CHIPC_GetInstructionString(CHIPC_Instruction* instruction);

#endif //CHIPC_INSTRUCTION_H

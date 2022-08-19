#ifndef CHIPC_INSTRUCTION_FUNCTIONS_H
#define CHIPC_INSTRUCTION_FUNCTIONS_H

#include "cpu.h"
#include "instruction.h"

typedef void (*CHIPC_InstructionFunction)(CHIPC_Cpu*, CHIPC_Instruction);

/**
 * Fetches a CHIPC_InstructionFunction given a CHIPC_Instruction
 * @return A CHIPC_InstructionFunction if one is found, NULL otherwise.
 */
CHIPC_InstructionFunction CHIPC_FetchInstruction(CHIPC_Instruction ins);

// Instructions
void CHIPC_Op0(CHIPC_Cpu* cpu, CHIPC_Instruction ins);
void CHIPC_Op1(CHIPC_Cpu* cpu, CHIPC_Instruction ins);
void CHIPC_Op2(CHIPC_Cpu* cpu, CHIPC_Instruction ins);
void CHIPC_Op3(CHIPC_Cpu* cpu, CHIPC_Instruction ins);
void CHIPC_Op4(CHIPC_Cpu* cpu, CHIPC_Instruction ins);
void CHIPC_Op5(CHIPC_Cpu* cpu, CHIPC_Instruction ins);
void CHIPC_Op6(CHIPC_Cpu* cpu, CHIPC_Instruction ins);
void CHIPC_Op7(CHIPC_Cpu* cpu, CHIPC_Instruction ins);
void CHIPC_Op8(CHIPC_Cpu* cpu, CHIPC_Instruction ins);
void CHIPC_Op9(CHIPC_Cpu* cpu, CHIPC_Instruction ins);
void CHIPC_OpA(CHIPC_Cpu* cpu, CHIPC_Instruction ins);
void CHIPC_OpB(CHIPC_Cpu* cpu, CHIPC_Instruction ins);
void CHIPC_OpC(CHIPC_Cpu* cpu, CHIPC_Instruction ins);
void CHIPC_OpD(CHIPC_Cpu* cpu, CHIPC_Instruction ins);
void CHIPC_OpE(CHIPC_Cpu* cpu, CHIPC_Instruction ins);
void CHIPC_OpF(CHIPC_Cpu* cpu, CHIPC_Instruction ins);

#endif //CHIPC_INSTRUCTION_FUNCTIONS_H

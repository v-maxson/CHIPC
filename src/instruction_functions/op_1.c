#include "../instruction_functions.h"

void CHIPC_Op1(CHIPC_Cpu* cpu, CHIPC_Instruction ins) {
    cpu->pc = ins.nnn;
}
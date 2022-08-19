#include "../instruction_functions.h"

void CHIPC_OpA(CHIPC_Cpu* cpu, CHIPC_Instruction ins) {
    cpu->i = ins.nnn;
}
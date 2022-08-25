#include "../instruction_functions.h"

void CHIPC_OpB(CHIPC_Cpu* cpu, CHIPC_Instruction ins) {
    cpu->pc = ins.nnn + cpu->v[0x0];
}
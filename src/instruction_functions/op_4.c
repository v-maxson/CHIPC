#include "../instruction_functions.h"

void CHIPC_Op4(CHIPC_Cpu* cpu, CHIPC_Instruction ins) {
    if (cpu->v[ins.x] != ins.kk) {
        cpu->pc += 2;
    }
}
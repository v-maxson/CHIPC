#include "../instruction_functions.h"

void CHIPC_Op9(CHIPC_Cpu* cpu, CHIPC_Instruction ins) {
    if (cpu->v[ins.x] != cpu->v[ins.y]) {
        cpu->pc += 2;
    }
}
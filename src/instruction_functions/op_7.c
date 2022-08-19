#include "../instruction_functions.h"

void CHIPC_Op7(CHIPC_Cpu* cpu, CHIPC_Instruction ins) {
    cpu->v[ins.x] += ins.kk;
}
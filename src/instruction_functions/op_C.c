#include "../instruction_functions.h"
#include <sodium.h>

void CHIPC_OpC(CHIPC_Cpu* cpu, CHIPC_Instruction ins) {
    cpu->v[ins.x] = (uint8_t)randombytes_uniform(256) & ins.kk;
}
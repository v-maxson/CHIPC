#include "cpu.h"
#include <string.h>

#define CHIPC_STACK_SIZE 16
#define CHIPC_PC_START 512

CHIPC_Cpu CHIPC_CreateCpu(void) {
    CHIPC_Cpu cpu = {0};

    cpu.stack = CHIPC_CreateStack(16);
    cpu.pc = CHIPC_PC_START;

    return cpu;
}

void CHIPC_DestroyCpu(CHIPC_Cpu *cpu) {
    CHIPC_DestroyStack(&cpu->stack);
}

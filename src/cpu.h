#ifndef CHIPC_CPU_H
#define CHIPC_CPU_H

#include "stack.h"
#include <stdint.h>

#define CHIPC_MEMORY_SIZE 4096
#define CHIPC_V_REGISTER_COUNT 16
#define CHIPC_STACK_SIZE 16
#define CHIPC_PC_START 512
#define CHIPC_WINDOW_WIDTH 64
#define CHIPC_WINDOW_HEIGHT 32
#define CHIPC_WINDOW_DIMENSIONS 64 * 32
#define CHIPC_PIXEL_ON  0xFFFFFFFF
#define CHIPC_PIXEL_OFF 0x00000000

typedef struct CHIPC_Cpu {
    uint8_t memory[CHIPC_MEMORY_SIZE];
    uint32_t display_memory[CHIPC_WINDOW_DIMENSIONS];
    uint8_t v[CHIPC_V_REGISTER_COUNT];
    uint16_t i, pc;
    uint8_t dt, st;
    CHIPC_Stack stack;
} CHIPC_Cpu;

/**
 * Creates a CHIPC_Cpu.
 */
CHIPC_Cpu CHIPC_CreateCpu(void);

/**
 * Destroys the provided CHIPC_Cpu.
 * @param cpu The CHIPC_Cpu to destroy.
 */
void CHIPC_DestroyCpu(CHIPC_Cpu* cpu);

/**
 * Begin cycling the CHIPC_Cpu at the given clock speed.
 * @param cpu The CHIPC_Cpu cycle.
 * @param rom_path The path to the ROM to execute.
 * @param clock_speed The speed at which to cycle (in Hz).
 */
void CHIPC_RunCpu(CHIPC_Cpu* cpu, const char* rom_path, uint64_t clock_speed);

#endif //CHIPC_CPU_H

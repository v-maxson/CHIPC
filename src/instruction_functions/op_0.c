#include "../instruction_functions.h"
#include "../cpu.h"
#include <string.h>
#include <SDL.h>

#define CHIPC_1X CHIPC_PIXEL_OFF
#define CHIPC_2X CHIPC_1X, CHIPC_1X
#define CHIPC_4X CHIPC_2X, CHIPC_2X

void CHIPC_Op0(CHIPC_Cpu* cpu, CHIPC_Instruction ins) {
    switch (ins.kk) {
        case 0xE0: {
            // CLS
            // FIXME This only works properly if CHIPC_PIXEL_OFF is 0x0 and not some other value.
            memset(cpu->display_memory, 0, 2048);
            return;
        }

        case 0xEE: {
            // RET
            bool result;
            CHIPC_Stack_t value = CHIPC_StackPop(&cpu->stack, &result);

            if (result) {
                cpu->pc = value;
                return;
            } else {
                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error!", "A stack underflow has occurred.", NULL);
                return;
            }
        }

        default:
            return;
    }
}
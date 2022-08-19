#include "../instruction_functions.h"
#include <SDL.h>

void CHIPC_OpD(CHIPC_Cpu* cpu, CHIPC_Instruction ins) {
    // Set Vf to 0
    cpu->v[0xF] = 0;

    for (uint8_t row = 0; row < ins.n; row++) {
        uint8_t s_byte = cpu->memory[cpu->i + row];

        for (uint8_t col = 0; col < 8; col++) {
            uint8_t s_pixel = s_byte & (0x80u >> col);
            uint32_t* display_pixel = &cpu->display_memory[
                    ((cpu->v[ins.y] % CHIPC_WINDOW_HEIGHT) + row) * CHIPC_WINDOW_WIDTH + ((cpu->v[ins.x] % CHIPC_WINDOW_WIDTH) + col)];

            if (s_pixel) {
                // If display_pixel is also on, set collision flag.
                if (*display_pixel == CHIPC_PIXEL_ON) {
                    cpu->v[0xF] = 1;
                    *display_pixel = CHIPC_PIXEL_OFF;
                } else {
                    *display_pixel = CHIPC_PIXEL_ON;
                }
            }

        }
    }

}
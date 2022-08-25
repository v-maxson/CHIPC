#include "../instruction_functions.h"

void CHIPC_Op8(CHIPC_Cpu* cpu, CHIPC_Instruction ins) {
    switch (ins.n) {
        case 0x0:
            cpu->v[ins.x] = cpu->v[ins.y];
            break;

        case 0x1:
            cpu->v[ins.x] |= cpu->v[ins.y];
            break;

        case 0x2:
            cpu->v[ins.x] &= cpu->v[ins.y];
            break;

        case 0x3:
            cpu->v[ins.x] ^= cpu->v[ins.y];
            break;

        case 0x4: {
            int vx = cpu->v[ins.x];
            int vy = cpu->v[ins.y];
            int result = vx + vy;

            if (result > UINT8_MAX)
                cpu->v[0xF] = 1;

            cpu->v[ins.x] = (uint8_t)result;
        } break;

        case 0x5: {
            int vx = cpu->v[ins.x];
            int vy = cpu->v[ins.y];
            int result = vx - vy;

            if (vx > vy) {
                cpu->v[0xF] = 1;
                cpu->v[ins.x] = 0;
            } else
                cpu->v[ins.x] = result;

        } break;

        case 0x6: {
            uint8_t bit = cpu->v[ins.x] & (0x80u >> 7);
            cpu->v[0xF] = bit;
            cpu->v[ins.x] >>= 1;
        } break;

        case 0x7: {
            int vx = cpu->v[ins.x];
            int vy = cpu->v[ins.y];
            int result = vy - vx;

            if (vy > vx) {
                cpu->v[0xF] = 1;
                cpu->v[ins.x] = 0;
            } else
                cpu->v[ins.x] = result;
        } break;

        case 0xE: {
            uint8_t bit = cpu->v[ins.x] & (0x80u);
            cpu->v[0xF] = bit;
            cpu->v[ins.x] <<= 1;
        } break;

        default: break;
    }
}
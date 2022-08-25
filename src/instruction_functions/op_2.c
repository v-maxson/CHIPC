#include "../instruction_functions.h"
#include <SDL.h>

void CHIPC_Op2(CHIPC_Cpu* cpu, CHIPC_Instruction ins) {
    bool result = CHIPC_StackPush(&cpu->stack, cpu->pc);
    if (!result) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error!", "A stack overflow has occurred.", NULL);
        return;
    } else {
        cpu->pc = ins.nnn;
    }
}
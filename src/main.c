#include "cpu.h"
#include "utility.h"
#include <nfd.h>
#include <SDL.h>

#define SDL_INIT_FLAGS  SDL_INIT_VIDEO   \
                        | SDL_INIT_AUDIO \
                        | SDL_INIT_TIMER

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_FLAGS) != 0) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Could not initialize SDL subsystems.", NULL);
        return 1;
    }

    if (NFD_Init() != NFD_OKAY) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Could not initialize NFD subsystems.", NULL);
        return 1;
    }


    nfdchar_t* rom_path;
    nfdfilteritem_t filters[1] = { {"CHIP-8 ROM", "rom,ch8"} };
    nfdresult_t dialog_result = NFD_OpenDialog(&rom_path, filters, 1, NULL);

    if (dialog_result == NFD_OKAY) {
        // Run the CHIP-8 Cpu with the selected ROM.
        CHIPC_Cpu cpu = CHIPC_CreateCpu();
        // TODO Allow user selectable clock_speed (text box input?).
        CHIPC_RunCpu(&cpu, rom_path, 500);
        CHIPC_DestroyCpu(&cpu);
        NFD_FreePath(rom_path);
    } else if (dialog_result == NFD_CANCEL) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, "Warning", "User cancelled file dialog, aborting...", NULL);
    } else {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", NFD_GetError(), NULL);
    }

    NFD_Quit();
    SDL_Quit();
    return 0;
}
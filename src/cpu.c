#include "cpu.h"
#include "instruction.h"
#include "utility.h"
#include "instruction_functions.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include <sodium.h>

CHIPC_Cpu CHIPC_CreateCpu(void) {
    CHIPC_Cpu cpu = {0};

    cpu.stack = CHIPC_CreateStack(16);
    cpu.pc = CHIPC_PC_START;

    return cpu;
}

void CHIPC_DestroyCpu(CHIPC_Cpu *cpu) {
    CHIPC_DestroyStack(&cpu->stack);
}

void CHIPC_RunCpu(CHIPC_Cpu *cpu, const char *rom_path, uint64_t clock_speed) {
    // Check the size of the provided ROM.
    uint64_t rom_size = CHIPC_GetFileSize(rom_path, NULL);
    if (rom_size > CHIPC_MEMORY_SIZE - CHIPC_PC_START) {
        const char* error_msg = CHIPC_CreateFormattedString(
                "ROM must be less than (or equal to) %d bytes in size. Selected ROM is %llu bytes in size.",
                CHIPC_MEMORY_SIZE - CHIPC_PC_START, rom_size);
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error!", error_msg, NULL);
        CHIPC_DestroyFormattedString(error_msg);
        return;
    }

    // Open the provided ROM.
    FILE* rom = fopen(rom_path, "rb");
    if (!rom) {
        const char* error_msg = CHIPC_CreateFormattedString("Could not open ROM: %s", rom_path);
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", error_msg, NULL);
        CHIPC_DestroyFormattedString(error_msg);
        return;
    }

    // Copy the contents into memory.
    // fread_s(&cpu->memory[CHIPC_PC_START], CHIPC_MEMORY_SIZE - CHIPC_PC_START, 1, CHIPC_MEMORY_SIZE - CHIPC_PC_START, rom);
    fread(&cpu->memory[CHIPC_PC_START], 1, CHIPC_MEMORY_SIZE - CHIPC_PC_START, rom);

    // Close the ROM file.
    fclose(rom);

    SDL_Window* window = SDL_CreateWindow(
            "CHIPC",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            CHIPC_WINDOW_WIDTH_SCALED,
            CHIPC_WINDOW_HEIGHT_SCALED,
            SDL_WINDOW_ALLOW_HIGHDPI
            );

    if (!window) {
        const char* error_message = CHIPC_CreateFormattedString(
                "An error occurred whilst initializing window: %s",
                SDL_GetError()
                );
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error!", error_message, NULL);
        CHIPC_DestroyFormattedString(error_message);
        return;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(
            window,
            -1,
            SDL_RENDERER_ACCELERATED
            | SDL_RENDERER_PRESENTVSYNC
            );

    if (!renderer) {
        const char* error_message = CHIPC_CreateFormattedString(
                "An error occurred whilst initializing renderer: %s",
                SDL_GetError()
                );
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error!", error_message, NULL);
        CHIPC_DestroyFormattedString(error_message);
        return;
    }

    SDL_Texture* texture = SDL_CreateTexture(
            renderer,
            SDL_PIXELFORMAT_RGB888,
            SDL_TEXTUREACCESS_STREAMING,
            CHIPC_WINDOW_WIDTH,
            CHIPC_WINDOW_HEIGHT
            );

    if (!texture) {
        const char* error_message = CHIPC_CreateFormattedString(
                "An error occurred whilst initializing texture: %s",
                SDL_GetError()
        );
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error!", error_message, NULL);
        CHIPC_DestroyFormattedString(error_message);
        return;
    }

    // possibly use surface?
//    SDL_Surface* surface = SDL_CreateRGBSurface(
//            0,
//            CHIPC_WINDOW_WIDTH,
//            CHIPC_WINDOW_HEIGHT,
//            32, 0, 0, 0, 0
//    );

    uint64_t starting_tick;
    bool running = true;
    while (running) {
        starting_tick = SDL_GetTicks64();

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                running = false;
        }

        // TODO Possibly add debug menu using CImGui?

        // Decode current instruction in memory.
        CHIPC_Instruction ins = CHIPC_CreateInstructionFromPair(
                cpu->memory[cpu->pc],
                cpu->memory[cpu->pc + 1]
                );

        // Execute the instruction.
        CHIPC_InstructionFunction ins_func = CHIPC_FetchInstruction(ins);
        if (ins_func) ins_func(cpu, ins);

        // Increment the PC.
        cpu->pc += 2;

        // FIXME Render at 30-60 FPS rather than each loop iteration.
        SDL_UpdateTexture(texture, &CHIPC_WINDOW_RECT, cpu->display_memory, CHIPC_WINDOW_WIDTH * sizeof(uint32_t));
        SDL_RenderCopy(renderer, texture, &CHIPC_WINDOW_RECT, &CHIPC_WINDOW_RECT);
        SDL_RenderPresent(renderer);

        // TODO Implement Delay/Sound timer.

        // Limit Clock speed.
        if ((1000 / clock_speed) > SDL_GetTicks64() - starting_tick) {
            SDL_Delay(1000 / clock_speed - (SDL_GetTicks64() - starting_tick));
        }
    }

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

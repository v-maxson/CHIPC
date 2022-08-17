cmake_minimum_required(VERSION 3.23)

#---- Project Configuration
project(CHIPC
        LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

#---- SDL2
set(SDL_LIBC ON)
add_subdirectory(./dependencies/SDL2)

#---- Compilation
file(GLOB_RECURSE PROJECT_SOURCE_FILES ./src/*.c ./src/*.h)
add_executable(${PROJECT_NAME} WIN32 ${PROJECT_SOURCE_FILES})

#---- Tests
add_subdirectory(tests)

#---- Linking
target_link_libraries(${PROJECT_NAME} SDL2main SDL2-static)

cmake_minimum_required(VERSION 3.23)

#---- Project Configuration
project(CHIPC
        LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

#---- SDL2
add_subdirectory(./dependencies/SDL2)

#---- NFDE
add_subdirectory(./dependencies/NFDE)

#---- libsodium
set(SODIUM_DISABLE_TESTS ON)
add_subdirectory(./dependencies/libsodium)
include_directories(
        PUBLIC ./dependencies/libsodium/libsodium/src/libsodium/include
        PRIVATE ./dependencies/libsodium/libsodium/src/libsodium/include/sodium
)

#---- Compilation
file(GLOB_RECURSE PROJECT_SOURCE_FILES ./src/*.c ./src/*.h)
add_executable(${PROJECT_NAME} WIN32 ${PROJECT_SOURCE_FILES})

#---- Tests
add_subdirectory(tests)

#---- Linking
set(DEPENDENCY_LIBS SDL2main SDL2-static nfd sodium)

if (MINGW)
    target_link_libraries(${PROJECT_NAME} mingw32 ${DEPENDENCY_LIBS})
elseif (MSVC)
    target_link_libraries(${PROJECT_NAME} ${DEPENDENCY_LIBS})
else () # This is only here for future compatibility.
    target_link_libraries(${PROJECT_NAME} ${DEPENDENCY_LIBS})
endif ()
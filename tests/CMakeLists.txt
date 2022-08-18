cmake_minimum_required(VERSION 3.23)

project(CHIPC_Tests LANGUAGES C)
include_directories(../src)

add_executable(CHIPC_StackTest stack.c ../src/stack.c)
add_executable(CHIPC_FileSizeTest filesize.c ../src/utility/filesize.c)
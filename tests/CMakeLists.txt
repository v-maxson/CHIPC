cmake_minimum_required(VERSION 3.23)

project(CHIPC_Tests LANGUAGES C)

add_executable(${PROJECT_NAME}-stacktest stacktest.c ../src/stack.c)
include_directories(../src)
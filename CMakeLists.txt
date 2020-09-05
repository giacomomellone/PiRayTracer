# (1) CMake definitions, compiler flags and useful variables
cmake_minimum_required(VERSION 3.7)
project(RayTracerLinux)

add_compile_options(-std=c++11 -Wall -Werror)

set(APP_NAME RayTracerLinuxApp)
set(APP_LIB_NAME RayTracerLinuxAppLib)

if(CMAKE_CROSSCOMPILING)
# (2) Include application build instructions
    message(STATUS "Crosscompiling enabled, using toolchain file: ${CMAKE_TOOLCHAIN_FILE}")
    add_compile_definitions(CROSS_COMPILING_FLAG)
    add_subdirectory(src)
else()
# (3) include tests build instructions
    message(STATUS "No crosscompiling specified, compiling in /tests only.")
    add_subdirectory(tests)
endif(CMAKE_CROSSCOMPILING)

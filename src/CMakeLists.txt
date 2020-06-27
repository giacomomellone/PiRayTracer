cmake_minimum_required(VERSION 3.10)

include_directories(../include)

file(GLOB USER_SOURCES 
    ${CMAKE_SOURCE_DIR}/src/*.cpp)

add_executable(RayTracer.elf ${USER_SOURCES})
target_link_libraries(RayTracer.elf)

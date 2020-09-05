cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_FLAGS "${COMMON_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${COMMON_CXX_FLAGS}" CACHE STRING "compiler flags")

include_directories(
    ../src/
    ../include/
    ../include/shapes
    ../include/support)

file(GLOB USER_SOURCES
    ${CMAKE_SOURCE_DIR}/src/*.cpp
    ${CMAKE_SOURCE_DIR}/src/modules/*.cpp
    ${CMAKE_SOURCE_DIR}/src/modules/shapes/*.cpp
    ${CMAKE_SOURCE_DIR}/src/support/*.cpp)

add_executable(RayTracer.elf ${USER_SOURCES})
target_link_libraries(RayTracer.elf)

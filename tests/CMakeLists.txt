cmake_minimum_required(VERSION 3.10)

if(DEFINED ENV{CPPUTEST_HOME})
    message(STATUS "Using CppUTest home: $ENV{CPPUTEST_HOME}")
    set(CPPUTEST_INCLUDE_DIRS $ENV{CPPUTEST_HOME}/include)
    set(CPPUTEST_LIBRARIES $ENV{CPPUTEST_HOME}/build/lib)
    set(CPPUTEST_LDFLAGS CppUTest CppUTestExt)
else()
    find_package(PkgConfig REQUIRED)
    pkg_search_module(CPPUTEST REQUIRED cpputest>=3.8)
    message(STATUS "Found CppUTest version ${CPPUTEST_VERSION}")
endif()

set(CMAKE_C_FLAGS "${COMMON_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${COMMON_CXX_FLAGS}" CACHE STRING "compiler flags")

set(TEST_APP_NAME RayTracer_tests.bin)

file(GLOB USER_SOURCES
    ${CMAKE_SOURCE_DIR}/tests/*.c
    ${CMAKE_SOURCE_DIR}/tests/*.cpp)

include_directories(${CPPUTEST_INCLUDE_DIRS}
    ../src/
    ../include/)
link_directories(${CPPUTEST_LIBRARIES})

add_executable(${TEST_APP_NAME} ${USER_SOURCES})
target_link_libraries(${TEST_APP_NAME} ${CPPUTEST_LDFLAGS})

# Run the test once the build is done
add_custom_command(TARGET ${TEST_APP_NAME} COMMAND ./${TEST_APP_NAME} POST_BUILD)

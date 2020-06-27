#include <CppUTest/CommandLineTestRunner.h>
#include "utils.cpp"
#include "tuple.cpp"

int main(int argc, char **argv) {
    return CommandLineTestRunner::RunAllTests(argc, argv);
}

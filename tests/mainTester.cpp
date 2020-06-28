#include <CppUTest/CommandLineTestRunner.h>
#include "support/utils.cpp"
#include "modules/tuple.cpp"

int main(int argc, char **argv) {
    return CommandLineTestRunner::RunAllTests(argc, argv);
}

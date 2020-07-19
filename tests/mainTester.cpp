#include <CppUTest/CommandLineTestRunner.h>

#include "support/utils.cpp"
#include "modules/tuple.cpp"
#include "modules/canvas.cpp"
#include "modules/matrix.cpp"
#include "modules/transformation.cpp"
#include "modules/ray.cpp"
#include "modules/shapes/sphere.cpp"
#include "modules/shapes/shape.cpp"
#include "modules/intersection.cpp"

int main(int argc, char **argv) {
    return CommandLineTestRunner::RunAllTests(argc, argv);
}

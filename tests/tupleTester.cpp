#include <CppUTest/TestHarness.h>
#include "../include/tuple.h"

TEST_GROUP(TupleTest) {};

TEST(TupleTest, isAPoint) {
    Tuple tp(4.3,-4.2,3.1,1.0); 

    DOUBLES_EQUAL(4.3, tp.x, EPSILON);
    DOUBLES_EQUAL(-4.2, tp.y, EPSILON);
    DOUBLES_EQUAL(3.1, tp.z, EPSILON);
    CHECK(tp.IsPoint());
}

TEST(TupleTest, isAVector) {
    Tuple tp(4.3, -4.2, 3.1, 0.0);
    CHECK(tp.IsVector());
}

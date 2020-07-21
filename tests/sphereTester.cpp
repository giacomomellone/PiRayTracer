/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include <CppUTest/TestHarness.h>

//-- module being tested
#include "../include/intersection.h"
#include "../include/shapes/sphere.h"

/*******************************************************************************
 *    DEFINITIONS
 ******************************************************************************/

/*******************************************************************************
 *    PRIVATE TYPES
 ******************************************************************************/

/*******************************************************************************
 *    PRIVATE DATA
 ******************************************************************************/

/*******************************************************************************
 *    PRIVATE FUNCTIONS
 ******************************************************************************/

/*******************************************************************************
 *    SETUP, TEARDOWN
 ******************************************************************************/

/*******************************************************************************
 *    TESTS
 ******************************************************************************/

TEST_GROUP(SphereTest) {};

TEST(SphereTest, intersectionsTangent)
{
    Sphere s;
    Ray r(Point(0, 1, -5), Vector(0, 0, 1));

    vector<Intersection> xs = Intersect(s, r);
    CHECK(xs.size() == 2);
    DOUBLES_EQUAL(5, xs[0].t, EPSILON);
    DOUBLES_EQUAL(5, xs[1].t, EPSILON);
}

TEST(SphereTest, intersectionsMiss)
{
    Sphere s;
    Ray r(Point(0, 2, -5), Vector(0, 0, 1));

    vector<Intersection> xs = Intersect(s, r);
    CHECK(xs.size() == 0);
    UNSIGNED_LONGS_EQUAL(0, xs[0].t);
    DOUBLES_EQUAL(0, xs[1].t, EPSILON);
}

TEST(SphereTest, intersectionsInside)
{
    Sphere s;
    Ray r(Point(0, 0, 0), Vector(0, 0, 1));

    vector<Intersection> xs = Intersect(s, r);
    CHECK(xs.size() == 2);
    DOUBLES_EQUAL(-1, xs[0].t, EPSILON);
    DOUBLES_EQUAL(1, xs[1].t, EPSILON);
}

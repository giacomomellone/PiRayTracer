/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include <CppUTest/TestHarness.h>

//-- module being tested
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
    vector<Intersection> xs(2);
    Ray r(Point(0, 1, -5), Vector(0, 0, 1));

    int inters = s.Intersect(r, xs);
    CHECK(inters == 2);
    DOUBLES_EQUAL(5, xs[0].t, EPSILON);
    DOUBLES_EQUAL(5, xs[1].t, EPSILON);
}

TEST(SphereTest, intersectionsMiss)
{
    Sphere s;
    vector<Intersection> xs(2);
    Ray r(Point(0, 2, -5), Vector(0, 0, 1));

    int inters = s.Intersect(r, xs);
    CHECK(inters == 0);
    DOUBLES_EQUAL(0, xs[0].t, EPSILON);
    DOUBLES_EQUAL(0, xs[1].t, EPSILON);
}

TEST(SphereTest, intersectionsInside)
{
    Sphere s;
    vector<Intersection> xs(2);
    Ray r(Point(0, 0, 0), Vector(0, 0, 1));

    int inters = s.Intersect(r, xs);
    CHECK(inters == 2);
    DOUBLES_EQUAL(-1, xs[0].t, EPSILON);
    DOUBLES_EQUAL(1, xs[1].t, EPSILON);
}

/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include <CppUTest/TestHarness.h>

//-- module being tested
#include "../include/shapes/sphere.h"
#include "../include/intersection.h"

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

TEST_GROUP(IntersectionTest) {};

TEST(IntersectionTest, intersectionsEncapsulation)
{
    Sphere s;

    Intersection i(3.5, &s);

    DOUBLES_EQUAL(3.5, i.t, EPSILON);
    CHECK(s.shapesCount - 1 == i.s->shapeID);
}

TEST(IntersectionTest, intersectionsAggregation)
{
    Sphere s;

    Intersection i1(1, &s);
    Intersection i2(2, &s);

    vector<Intersection> xs = Intersections(i1, i2);

    DOUBLES_EQUAL(1, xs[0].t, EPSILON);
    DOUBLES_EQUAL(2, xs[1].t, EPSILON);
}

TEST(IntersectionTest, intersectionsObjectSet)
{
    Sphere s;
    vector<Intersection> xs(2);
    Ray r(Point(0, 0, -5), Vector(0, 0, 1));

    int xs_cnt = s.Intersect(r, xs);

    vector<Intersection> xs_all = Intersections(xs[0], xs[1]);

    DOUBLES_EQUAL(2, xs_cnt, EPSILON);
    CHECK(xs_all[1].s->shapeID == s.shapeID);
}

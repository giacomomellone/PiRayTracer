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
//    printf("s.shapeID: %d\n", s.shapeID);
//    printf("s.shapesCount: %d\n", s.shapesCount);

    Intersection i(3.5, s);
//    printf("s.shapeID: %d\n", s.shapeID);
//    printf("s.shapesCount: %d\n", s.shapesCount);
//    printf("i.s.shapeID: %d\n", i.s.shapeID);
//    printf("i.s.shapesCount: %d\n", i.s.shapesCount);

    DOUBLES_EQUAL(3.5, i.t, EPSILON);
}

TEST(IntersectionTest, intersectionsAggregation)
{
    Sphere s;

    Intersection i1(1, s);
    Intersection i2(2, s);

    vector<Intersection> xs = Intersections(i1, i2);

    DOUBLES_EQUAL(1, xs[0].t, EPSILON);
    DOUBLES_EQUAL(2, xs[1].t, EPSILON);
//    printf("xs[1].s->shapeID: %d\n", xs[1].s->shapeID);
}

TEST(IntersectionTest, intersectionsObjectSet)
{
    Sphere s;
    Ray r(Point(0, 0, -5), Vector(0, 0, 1));

    vector<Intersection> xs = Intersect(s, r);

    vector<Intersection> xs_all = Intersections(xs[0], xs[1]);

    DOUBLES_EQUAL(2, xs.size(), EPSILON);
}

TEST(IntersectionTest, positiveHit)
{
    Sphere s;

    Intersection i1(1, s);
    Intersection i2(2, s);

    vector<Intersection> xs = Intersections(i1, i2);

    Intersection* i = Hit(&xs);

    CHECK(i != NULL);
    CHECK(*i == i1);
}

TEST(IntersectionTest, negativeHit)
{
    Sphere s;

    Intersection i1(-1, s);
    Intersection i2(1, s);

    vector<Intersection> xs = Intersections(i1, i2);

    Intersection* i = Hit(&xs);

    CHECK(i != NULL);
    CHECK(*i == i2);
}

TEST(IntersectionTest, allNegativeHit)
{
    Sphere s;

    Intersection i1(-2, s);
    Intersection i2(-1, s);

    vector<Intersection> xs = Intersections(i1, i2);

    Intersection* i = Hit(&xs);

    CHECK(i == NULL);
}

TEST(IntersectionTest, lowestPositiveHit)
{
    Sphere s;

    Intersection i1(5, s);
    Intersection i2(8, s);
    Intersection i3(-3, s);
    Intersection i4(2, s);

    vector<Intersection> xs = Intersections(i1, i2, i3, i4);

    Intersection* i = Hit(&xs);

    CHECK(i != NULL);
    CHECK(*i == i4);
}

TEST(IntersectionTest, prepareComputations)
{
    Sphere s;

    Ray r(Point(0, 0, -5), Vector(0, 0, 1));
    Intersection i(4, s);

    comps_s comps = prepareComputation(i, r);

    CHECK(comps.t == i.t);
    CHECK(comps.point == Point(0, 0, -1));
    CHECK(comps.eyeV == Vector(0, 0, -1));
    CHECK(comps.normalV == Vector(0, 0, -1));
}


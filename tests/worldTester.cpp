/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include <CppUTest/TestHarness.h>

//-- module being tested
#include "../include/intersection.h"
#include "../include/world.h"


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

TEST_GROUP(WorldTest) {};

TEST(WorldTest, constructWorld)
{
    World w;

    DOUBLES_EQUAL(-10, w.lightP.position.x, EPSILON);
    DOUBLES_EQUAL(10, w.lightP.position.y, EPSILON);
    DOUBLES_EQUAL(-10, w.lightP.position.z, EPSILON);

    DOUBLES_EQUAL(0.8, w.s1.material.color.r(), EPSILON);
    DOUBLES_EQUAL(1, w.s1.material.color.g(), EPSILON);
    DOUBLES_EQUAL(0.6, w.s1.material.color.b(), EPSILON);
    DOUBLES_EQUAL(0.2, w.s1.material.specular, EPSILON);
    DOUBLES_EQUAL(0.7, w.s1.material.diffuse, EPSILON);

    CHECK(Scaling(0.5, 0.5, 0.5) == w.s2.transfM);

    Light lightW(Point(-10, 10, -10), Color(1, 1, 1));
    CHECK(w.lightP.intensity == lightW.intensity);
    CHECK(w.lightP.position == lightW.position);
}

TEST(WorldTest, intersectWorld)
{
    World w;
    Ray r(Point(0, 0, -5), Vector(0, 0, 1));

    vector<Intersection> xs = w.Intersect(r);

    UNSIGNED_LONGS_EQUAL(4, xs.size());

    DOUBLES_EQUAL(4, xs[0].t, EPSILON);
    DOUBLES_EQUAL(4.5, xs[1].t, EPSILON);
    DOUBLES_EQUAL(5.5, xs[2].t, EPSILON);
    DOUBLES_EQUAL(6, xs[3].t, EPSILON);
}

TEST(WorldTest, shadeHit_oustide)
{
    World w;
    Ray r(Point(0, 0, -5), Vector(0, 0, 1));
    Intersection i(4, &w.s1);

    comps_s comps = prepareComputation(i, r);
    Color c = w.ShadeHit(&comps);

    CHECK(c == Color(0.38066, 0.47583, 0.2855));
}

TEST(WorldTest, shadeHit_inside)
{
    World w;
    w.lightP = Light(Point(0, 0.25, 0), Color(1, 1, 1));
    Ray r(Point(0, 0, 0), Vector(0, 0, 1));
    Intersection i(0.5, &w.s2);

    comps_s comps = prepareComputation(i, r);
    Color c = w.ShadeHit(&comps);

    CHECK(c == Color(0.90498, 0.90498, 0.90498));
}

TEST(WorldTest, colorAt_rayMiss)
{
    World w;
    Ray r(Point(0, 0, -5), Vector(0, 1, 0));

    Color c = w.ColorAt(r);

    CHECK(c == Color(0, 0, 0));
}

TEST(WorldTest, colorAt_rayHit)
{
    World w;
    Ray r(Point(0, 0, -5), Vector(0, 0, 1));

    Color c = w.ColorAt(r);

    DOUBLES_EQUAL(0.38066, c.r(), EPSILON);
    DOUBLES_EQUAL(0.47583, c.g(), EPSILON);
    DOUBLES_EQUAL(0.2855, c.b(), EPSILON);
}

/*
 * We expect color_at to use the hit when computing the color.
 * Here, we put the ray inside the outer sphere, but outside the
 * inner sphere, and pointing at the inner sphere. We expect the
 * hit to be on the inner sphere, and thus return its color.
 */
TEST(WorldTest, colorAt_intersectionBehindRay)
{
    World w;
    Sphere outer = w.s1;
    outer.material.ambient = 1;
    Sphere inner = w.s2;
    inner.material.ambient = 1;
    Ray r(Point(0, 0, 0.75), Vector(0, 0, -1));

    Color c = w.ColorAt(r);

    DOUBLES_EQUAL(inner.material.color.r(), c.r(), EPSILON);
    DOUBLES_EQUAL(inner.material.color.g(), c.g(), EPSILON);
    DOUBLES_EQUAL(inner.material.color.b(), c.b(), EPSILON);
}

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
    DOUBLES_EQUAL(0.2, w.s1.material.specular, EPSILON);
}

TEST(WorldTest, intersectWorld)
{
    World w;
    Ray r(Point(0, 0, -5), Vector(0, 0, 1));

    vector<Intersection> xs = IntersectWorld(w, r);

    UNSIGNED_LONGS_EQUAL(4, xs.size());

    DOUBLES_EQUAL(4, xs[0].t, EPSILON);
    DOUBLES_EQUAL(4.5, xs[1].t, EPSILON);
    DOUBLES_EQUAL(5.5, xs[2].t, EPSILON);
    DOUBLES_EQUAL(6, xs[3].t, EPSILON);
}

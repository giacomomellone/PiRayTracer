/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include <CppUTest/TestHarness.h>

//-- module being tested
#include <cmath>
#include "../include/material.h"
#include "../include/light.h"

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

TEST_GROUP(MaterialTest) {};

TEST(MaterialTest, LightingEyeBetweenLightAndSurface)
{
    Material m;
    Tuple eyeV = Vector(0, 0, -1);
    Tuple normalV = Vector(0, 0, -1);
    Light lightP(Point(0, 0, -10), Color(1, 1, 1));
    Tuple position = Point(0, 0, 0);

    Color res = Lighting(m, lightP, position, eyeV, normalV);

    CHECK(res == Color(1.9, 1.9, 1.9));
}

TEST(MaterialTest, Eye45Degrees)
{
    Material m;
    Tuple eyeV = Vector(0, sqrtf(2)/2, -sqrtf(2)/2);
    Tuple normalV = Vector(0, 0, -1);
    Light lightP(Point(0, 0, -10), Color(1, 1, 1));
    Tuple position = Point(0, 0, 0);

    Color res = Lighting(m, lightP, position, eyeV, normalV);

    CHECK(res == Color(1.0, 1.0, 1.0));
}

TEST(MaterialTest, Light45Degrees)
{
    Material m;
    Tuple eyeV = Vector(0, 0, -1);
    Tuple normalV = Vector(0, 0, -1);
    Light lightP(Point(0, 10, -10), Color(1, 1, 1));
    Tuple position = Point(0, 0, 0);

    Color res = Lighting(m, lightP, position, eyeV, normalV);

    CHECK(res == Color(0.7364, 0.7364, 0.7364));
}

TEST(MaterialTest, EyeAndLight45Degrees)
{
    Material m;
    Tuple eyeV = Vector(0, -sqrtf(2)/2, -sqrtf(2)/2);
    Tuple normalV = Vector(0, 0, -1);
    Light lightP(Point(0, 10, -10), Color(1, 1, 1));
    Tuple position = Point(0, 0, 0);

    Color res = Lighting(m, lightP, position, eyeV, normalV);

    CHECK(res == Color(1.6364, 1.6364, 1.6364));
}

TEST(MaterialTest, LightBehindSurface)
{
    Material m;
    Tuple eyeV = Vector(0, 0, -1);
    Tuple normalV = Vector(0, 0, -1);
    Light lightP(Point(0, 0, 10), Color(1, 1, 1));
    Tuple position = Point(0, 0, 0);

    Color res = Lighting(m, lightP, position, eyeV, normalV);

    CHECK(res == Color(0.1, 0.1, 0.1));
}



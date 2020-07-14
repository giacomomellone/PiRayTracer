/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include <CppUTest/TestHarness.h>
#include <iostream>
#include <fstream>

//-- module being tested
#include "../include/transformation.h"

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

TEST_GROUP(TransformationTest) {};

TEST(TransformationTest, Translation)
{
    Matrix transMat = Translation(5, -3, 2);
    Tuple p = Point(-3, 4, 5);

    Tuple res = transMat * p;
    DOUBLES_EQUAL(res.x, 2, EPSILON);
    DOUBLES_EQUAL(res.y, 1, EPSILON);
    DOUBLES_EQUAL(res.z, 7, EPSILON);
    DOUBLES_EQUAL(res.w, 1, EPSILON);
}

TEST(TransformationTest, TranslationInv)
{
    Matrix transMat = Translation(5, -3, 2);
    transMat = transMat.Inverse();
    Tuple p = Point(-3, 4, 5);

    Tuple res = transMat * p;
    DOUBLES_EQUAL(res.x, -8, EPSILON);
    DOUBLES_EQUAL(res.y, 7, EPSILON);
    DOUBLES_EQUAL(res.z, 3, EPSILON);
    DOUBLES_EQUAL(res.w, 1, EPSILON);
}

TEST(TransformationTest, TranslationVector)
{
    Matrix transMat = Translation(5, -3, 2);
    Tuple v = Vector(-3, 4, 5);

    CHECK((transMat * v) == v);
}

TEST(TransformationTest, ScalingPoint)
{
    Matrix scaleMat = Scaling(2, 3, 4);
    Tuple p = Point(-4, 6, 8);

    Tuple res = scaleMat * p;
    DOUBLES_EQUAL(res.x, -8, EPSILON);
    DOUBLES_EQUAL(res.y, 18, EPSILON);
    DOUBLES_EQUAL(res.z, 32, EPSILON);
    DOUBLES_EQUAL(res.w, 1, EPSILON);
}

TEST(TransformationTest, ScalingVector)
{
    Matrix scaleMat = Scaling(2, 3, 4);
    Tuple v = Vector(-4, 6, 8);

    Tuple res = scaleMat * v;
    DOUBLES_EQUAL(res.x, -8, EPSILON);
    DOUBLES_EQUAL(res.y, 18, EPSILON);
    DOUBLES_EQUAL(res.z, 32, EPSILON);
}

TEST(TransformationTest, ScalingInv)
{
    Matrix scaleMat = Scaling(2, 3, 4);
    scaleMat = scaleMat.Inverse();

    Tuple v = Vector(-4, 6, 8);

    Tuple res = scaleMat * v;
    DOUBLES_EQUAL(res.x, -2, EPSILON);
    DOUBLES_EQUAL(res.y, 2, EPSILON);
    DOUBLES_EQUAL(res.z, 2, EPSILON);
}

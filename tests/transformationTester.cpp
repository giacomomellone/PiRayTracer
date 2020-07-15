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

TEST(TransformationTest, RotationX)
{
    Matrix rotMat = RotationX(M_PI / 4);
    Tuple p = Point(0, 1, 0);

    Tuple res = rotMat * p;
    DOUBLES_EQUAL(res.x, 0, EPSILON);
    DOUBLES_EQUAL(res.y, sqrtf(2) / 2, EPSILON);
    DOUBLES_EQUAL(res.z, sqrtf(2) / 2, EPSILON);
}

TEST(TransformationTest, RotationX2)
{
    Matrix rotMat = RotationX(M_PI / 2);
    Tuple p = Point(0, 1, 0);

    Tuple res = rotMat * p;
    DOUBLES_EQUAL(res.x, 0, EPSILON);
    DOUBLES_EQUAL(res.y, 0, EPSILON);
    DOUBLES_EQUAL(res.z, 1, EPSILON);
}

TEST(TransformationTest, RotationY)
{
    Matrix rotMat = RotationY(M_PI / 4);
    Tuple p = Point(0, 0, 1);

    Tuple res = rotMat * p;
    DOUBLES_EQUAL(res.x, sqrtf(2) / 2, EPSILON);
    DOUBLES_EQUAL(res.y, 0, EPSILON);
    DOUBLES_EQUAL(res.z, sqrtf(2) / 2, EPSILON);
}

TEST(TransformationTest, RotationY2)
{
    Matrix rotMat = RotationY(M_PI / 2);
    Tuple p = Point(0, 0, 1);

    Tuple res = rotMat * p;
    DOUBLES_EQUAL(res.x, 1, EPSILON);
    DOUBLES_EQUAL(res.y, 0, EPSILON);
    DOUBLES_EQUAL(res.z, 0, EPSILON);
}

TEST(TransformationTest, RotationZ)
{
    Matrix rotMat = RotationZ(M_PI / 4);
    Tuple p = Point(0, 1, 0);

    Tuple res = rotMat * p;
    DOUBLES_EQUAL(res.x, -sqrtf(2) / 2, EPSILON);
    DOUBLES_EQUAL(res.y, sqrtf(2) / 2, EPSILON);
    DOUBLES_EQUAL(res.z, 0, EPSILON);
}

TEST(TransformationTest, RotationZ2)
{
    Matrix rotMat = RotationZ(M_PI / 2);
    Tuple p = Point(0, 1, 0);

    Tuple res = rotMat * p;
    DOUBLES_EQUAL(res.x, -1, EPSILON);
    DOUBLES_EQUAL(res.y, 0, EPSILON);
    DOUBLES_EQUAL(res.z, 0, EPSILON);
}

TEST(TransformationTest, Shearing1)
{
    Matrix shearMat = Shearing(1, 0, 0, 0, 0, 0);
    Tuple p = Point(2, 3, 4);

    Tuple res = shearMat * p;
    DOUBLES_EQUAL(res.x, 5, EPSILON);
    DOUBLES_EQUAL(res.y, 3, EPSILON);
    DOUBLES_EQUAL(res.z, 4, EPSILON);
}

TEST(TransformationTest, Shearing2)
{
    Matrix shearMat = Shearing(0, 1, 0, 0, 0, 0);
    Tuple p = Point(2, 3, 4);

    Tuple res = shearMat * p;
    DOUBLES_EQUAL(res.x, 6, EPSILON);
    DOUBLES_EQUAL(res.y, 3, EPSILON);
    DOUBLES_EQUAL(res.z, 4, EPSILON);
}

TEST(TransformationTest, Shearing3)
{
    Matrix shearMat = Shearing(0, 0, 1, 0, 0, 0);
    Tuple p = Point(2, 3, 4);

    Tuple res = shearMat * p;
    DOUBLES_EQUAL(res.x, 2, EPSILON);
    DOUBLES_EQUAL(res.y, 5, EPSILON);
    DOUBLES_EQUAL(res.z, 4, EPSILON);
}

TEST(TransformationTest, Shearing4)
{
    Matrix shearMat = Shearing(0, 0, 0, 1, 0, 0);
    Tuple p = Point(2, 3, 4);

    Tuple res = shearMat * p;
    DOUBLES_EQUAL(res.x, 2, EPSILON);
    DOUBLES_EQUAL(res.y, 7, EPSILON);
    DOUBLES_EQUAL(res.z, 4, EPSILON);
}

TEST(TransformationTest, Shearing5)
{
    Matrix shearMat = Shearing(0, 0, 0, 0, 1, 0);
    Tuple p = Point(2, 3, 4);

    Tuple res = shearMat * p;
    DOUBLES_EQUAL(res.x, 2, EPSILON);
    DOUBLES_EQUAL(res.y, 3, EPSILON);
    DOUBLES_EQUAL(res.z, 6, EPSILON);
}

TEST(TransformationTest, Shearing6)
{
    Matrix shearMat = Shearing(0, 0, 0, 0, 0, 1);
    Tuple p = Point(2, 3, 4);

    Tuple res = shearMat * p;
    DOUBLES_EQUAL(res.x, 2, EPSILON);
    DOUBLES_EQUAL(res.y, 3, EPSILON);
    DOUBLES_EQUAL(res.z, 7, EPSILON);
}

TEST(TransformationTest, Concatenate)
{
    Tuple p = Point(1, 0, 1);

    Tuple res = (Translation(10, 5, 7) *
            Scaling(5, 5, 5) *
            RotationX(M_PI / 2)) * p;

    DOUBLES_EQUAL(res.x, 15, EPSILON);
    DOUBLES_EQUAL(res.y, 0, EPSILON);
    DOUBLES_EQUAL(res.z, 7, EPSILON);
}

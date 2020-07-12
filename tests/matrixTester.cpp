/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include <CppUTest/TestHarness.h>
#include <iostream>
#include <fstream>

//-- module being tested
#include "../include/utils.h"
#include "../include/matrix.h"

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

TEST_GROUP(MatrixTest) {};

TEST(MatrixTest, MatrixConstructor)
{
    Matrix m1(4, 4,
        {1, 2, 3, 4,
        5.5, 6.5, 7.5, 8.5,
        9, 10, 11, 12,
        13.5, 14.5, 15.5, 16.5});
    DOUBLES_EQUAL(m1(0,0), 1, EPSILON);
    DOUBLES_EQUAL(m1(0,3), 4, EPSILON);
    DOUBLES_EQUAL(m1(1,0), 5.5, EPSILON);
    DOUBLES_EQUAL(m1(1,2), 7.5, EPSILON);
    DOUBLES_EQUAL(m1(2,2), 11, EPSILON);
    DOUBLES_EQUAL(m1(3,0), 13.5, EPSILON);
    DOUBLES_EQUAL(m1(3,2), 15.5, EPSILON);

    Matrix m2(4, 4);
    DOUBLES_EQUAL(m2(0,0), 0, EPSILON);
    DOUBLES_EQUAL(m2(0,3), 0, EPSILON);
    DOUBLES_EQUAL(m2(1,0), 0, EPSILON);
    DOUBLES_EQUAL(m2(1,2), 0, EPSILON);
    DOUBLES_EQUAL(m2(2,2), 0, EPSILON);
    DOUBLES_EQUAL(m2(3,0), 0, EPSILON);
    DOUBLES_EQUAL(m2(3,2), 0, EPSILON);

    Matrix m3(3, 4,
        {1, 2, 3, 4,
        5.5, 6.5, 7.5, 8.5,
        9, 10, 11, 12});
    DOUBLES_EQUAL(m3(0,0), 1, EPSILON);
    DOUBLES_EQUAL(m3(0,3), 4, EPSILON);
    DOUBLES_EQUAL(m3(1,0), 5.5, EPSILON);
    DOUBLES_EQUAL(m3(1,2), 7.5, EPSILON);
    DOUBLES_EQUAL(m3(2,2), 11, EPSILON);
}

TEST(MatrixTest, MatrixEqual)
{
    Matrix m1(4, 4,
        {1, 2, 3, 4,
        5.5, 6.5, 7.5, 8.5,
        9, 10, 11, 12,
        13.5, 14.5, 15.5, 16.5});

    Matrix m2(4, 4,
        {1, 2, 3, 4,
        5.5, 6.5, 7.5, 8.5,
        9, 10, 11, 12,
        13.5, 14.5, 15.5, 16.5});

    Matrix m3(4, 4,
        {1, 2, 3, 4,
        5.5, 6.5, 7.5, 8.5,
        9, 10, 11, 12,
        13.5, 14.5, 15.1, 16.5});

    Matrix m4(3, 4,
        {1, 2, 3, 4,
        5.5, 6.5, 7.5, 8.5,
        9, 10, 11, 12});

    CHECK(m1 == m2);
    CHECK_FALSE(m1 == m3);
    CHECK_FALSE(m1 == m4);
    CHECK_FALSE(m1 != m2);
    CHECK(m1 != m3);
    CHECK(m1 != m4);
}

TEST(MatrixTest, MatrixMultiplication)
{
    Matrix m1(4, 4,
        {1, 2, 3, 4,
        5, 6, 7, 8,
        9, 8, 7, 6,
        5, 4, 3, 2});

    Matrix m2(4, 4,
        {-2, 1, 2, 3,
        3, 2, 1, -1,
        4, 3, 6, 5,
        1, 2, 7, 8});

    Matrix m_res = m1 * m2;

    DOUBLES_EQUAL(20, m_res(0,0), EPSILON);
    DOUBLES_EQUAL(48, m_res(0,3), EPSILON);
    DOUBLES_EQUAL(44, m_res(1,0), EPSILON);
    DOUBLES_EQUAL(114, m_res(1,2), EPSILON);
    DOUBLES_EQUAL(110, m_res(2,2), EPSILON);
    DOUBLES_EQUAL(16, m_res(3,0), EPSILON);
    DOUBLES_EQUAL(46, m_res(3,2), EPSILON);
}

TEST(MatrixTest, TupleMultiplication)
{
    Matrix m(4, 4,
        {1, 2, 3, 4,
        2, 4, 4, 2,
        8, 6, 4, 1,
        0, 0, 0, 1});

    Tuple t = Tuple(1, 2, 3, 1);

    Tuple t_res = m * t;

    DOUBLES_EQUAL(18, t_res.x, EPSILON);
    DOUBLES_EQUAL(24, t_res.y, EPSILON);
    DOUBLES_EQUAL(33, t_res.z, EPSILON);
    DOUBLES_EQUAL(1, t_res.w, EPSILON);
}


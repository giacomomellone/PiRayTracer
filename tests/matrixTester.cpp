/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include <CppUTest/TestHarness.h>
#include <iostream>
#include <fstream>

//-- module being tested
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

TEST(MatrixTest, Identity)
{
    Matrix m(4, 4,
        {1, 2, 3, 4,
        2, 4, 4, 2,
        8, 6, 4, 1,
        0, 0, 0, 1});

    Matrix identity = IdentityMatrix(4, 4);

    Tuple t = Tuple(1, 2, 3, 1);

    CHECK(m == (m * identity));
    CHECK(t == (identity * t));
}

TEST(MatrixTest, Transpose)
{
    Matrix m(4, 4,
        {1, 2, 3, 4,
        2, 4, 4, 2,
        8, 6, 4, 1,
        0, 0, 0, 1});

    Matrix m_t(4, 4,
        {1, 2, 8, 0,
        2, 4, 6, 0,
        3, 4, 4, 0,
        4, 2, 1, 1});

    Matrix t = m.Transpose();

    CHECK(m_t == t);
}

TEST(MatrixTest, DeterminantOf3x3Matrix) {
    Matrix m( 3, 3, {
        1,2,6,
        -5,8,-4,
        2,6,4
    });

    DOUBLES_EQUAL(m.Cofactor(0,0), 56, EPSILON);
    DOUBLES_EQUAL(m.Cofactor(0,1), 12, EPSILON);
    DOUBLES_EQUAL(m.Cofactor(0,2), -46, EPSILON);
    DOUBLES_EQUAL(m.Determinant(), -196, EPSILON);
}

TEST(MatrixTest, DeterminantOf4x4Matrix) {
    Matrix m(4, 4, {
        -2,-8,3,5,
        -3,1,7,3,
        1,2,-9,6,
        -6,7,7,-9
    });

    DOUBLES_EQUAL(m.Cofactor(0,0), 690, EPSILON);
    DOUBLES_EQUAL(m.Cofactor(0,1), 447, EPSILON);
    DOUBLES_EQUAL(m.Cofactor(0,2), 210, EPSILON);
    DOUBLES_EQUAL(m.Cofactor(0,3), 51, EPSILON);
    DOUBLES_EQUAL(m.Determinant(), -4071, EPSILON);
}

TEST(MatrixTest, TestInvertibleMatrix) {
    Matrix m(4, 4, {
        6,4,4,4,
        5,5,7,6,
        4,-9,3,-7,
        9,1,7,-6
    });

    DOUBLES_EQUAL(m.Determinant(), -2120, EPSILON);
    CHECK(m.IsInvertible());
}

TEST(MatrixTest, TestNonInvertibleMatrix) {
    Matrix m(4, 4, {
        -4,2,-2,-3,
        9,6,2,6,
        0,-5,1,-5,
        0,0,0,0
    });

    DOUBLES_EQUAL(m.Determinant(), 0, EPSILON);
    CHECK(!m.IsInvertible());
}

TEST(MatrixTest, CalculateInverseOfMatrix) {
    Matrix A(4, 4, {
        -5,2,6,-8,
        1,-5,1,8,
        7,7,-6,-7,
        1,-3,7,4
    });

    Matrix B = A.Inverse();

    DOUBLES_EQUAL(A.Determinant(), 532, EPSILON);

    DOUBLES_EQUAL(A.Cofactor(2,3), -160, EPSILON);
    DOUBLES_EQUAL(B(3,2), (float) -160/532, EPSILON);

    DOUBLES_EQUAL(A.Cofactor(3,2), 105, EPSILON);
    DOUBLES_EQUAL(B(2,3), (float) 105/532, EPSILON);

    Matrix C( 4, 4, {
        0.21805, 0.45113, 0.24060, -0.04511,
        -0.80827, -1.45677, -0.44361, 0.52068,
        -0.07895, -0.22368, -0.05263, 0.19737,
        -0.52256, -0.81391, -0.30075, 0.30639
    });

//    for(int i = 0; i < C.Rows(); i++) {
//        for(int j = 0; j < C.Cols(); j++) {
//            printf("B(%d, %d) = %f\n", i, j, B(i, j));
//            printf("C(%d, %d) = %f\n", i, j, C(i, j));
//        }
//    }

    CHECK(B == C);
}

TEST(MatrixTest, CalculateInverseOfMatrix2) {
    Matrix A(4, 4, {
        8,-5,9,2,
        7,5,6,1,
        -6,0,9,6,
        -3,0,-9,-4
    });

    Matrix B(4, 4, {
         -0.15385, -0.15385, -0.28205, -0.53846,
        -0.07692,  0.12308,  0.02564,  0.03077,
        0.35897,  0.35897,  0.43590,  0.92308,
        -0.69231, -0.69231, -0.76923, -1.92308
    });

    CHECK(A.Inverse() == B);
}

TEST(MatrixTest, CalculateInverseOfMatrix3) {
    Matrix A(4, 4, {
        9,3,0,9,
        -5,-2,-6,-3,
        -4,9,6,4,
        -7,6,6,2
    });

    Matrix B(4, 4, {
        -0.04074, -0.07778,  0.14444, -0.22222,
        -0.07778,  0.03333,  0.36667, -0.33333,
        -0.02901, -0.14630, -0.10926,  0.12963,
        0.17778, 0.06667, -0.26667, 0.33333
    });

    CHECK(A.Inverse() == B);
}

TEST(MatrixTest, MultiplyAProductByItsInverse) {
    Matrix A(4, 4, {
        3,-9,7,3,
        3,-8,2,-9,
        -4,4,4,1,
        -6,5,-1,1
    });

    Matrix B(4, 4, {
        8,2,2,2,
        3,-1,7,0,
        7,0,5,4,
        6,-2,0,5
    });

    Matrix C = A * B;

    CHECK((C * B.Inverse()) == A);
}

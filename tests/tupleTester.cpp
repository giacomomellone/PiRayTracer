/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include <CppUTest/TestHarness.h>

//-- module being tested
#include "../include/tuple.h"


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

TEST_GROUP(TupleTest) {};

TEST(TupleTest, isAPoint)
{
    Tuple tp(4.3,-4.2, 3.1, 1.0);

    DOUBLES_EQUAL(4.3, tp.x, EPSILON);
    DOUBLES_EQUAL(-4.2, tp.y, EPSILON);
    DOUBLES_EQUAL(3.1, tp.z, EPSILON);
    CHECK(tp.IsPoint());

    Tuple t_point = Point(1.3, 2.5, -2.6);
    DOUBLES_EQUAL(1.3, t_point.x, EPSILON);
    DOUBLES_EQUAL(2.5, t_point.y, EPSILON);
    DOUBLES_EQUAL(-2.6, t_point.z, EPSILON);
    CHECK(t_point.IsPoint());
}

TEST(TupleTest, isAVector)
{
    Tuple tp(4.3, -4.2, 3.1, 0.0);
    CHECK(tp.IsVector());

    Tuple t_vector = Vector(1.3, 32.5, -2.6);
    DOUBLES_EQUAL(1.3, t_vector.x, EPSILON);
    DOUBLES_EQUAL(32.5, t_vector.y, EPSILON);
    DOUBLES_EQUAL(-2.6, t_vector.z, EPSILON);
    CHECK(t_vector.IsVector());
}

TEST(TupleTest, equal_tuple)
{
	Tuple t1(4.3, -4.2, 3.1, 0.0);
	Tuple t2(4.3, -4.2, 3.1, 0.0);
	Tuple t3(1.3, 4.2, 3.1, 1);

	CHECK(t1 == t2);
	CHECK_FALSE(t1 == t3);
}

TEST(TupleTest, add_tuple)
{
	Tuple t1(3, -2, 5, 1);
	Tuple t2(-2, 3, 1, 0);
	Tuple t_sum(1, 1, 6, 1);

	CHECK((t1 + t2) == t_sum);
}

TEST(TupleTest, subtract_point)
{
	Tuple p1 = Point(3, 2, 1);
	Tuple p2 = Point(5, 6, 7);
	Tuple v_diff = Vector(-2, -4, -6);

	CHECK((p1 - p2) == v_diff);
}

TEST(TupleTest, subtract_point_to_vector)
{
	Tuple p1 = Point(3, 2, 1);
	Tuple v2 = Vector(5, 6, 7);
	Tuple p_diff = Point(-2, -4, -6);

	CHECK((p1 - v2) == p_diff);
}

TEST(TupleTest, subtract_vector)
{
	Tuple v1 = Vector(3, 2, 1);
	Tuple v2 = Vector(5, 6, 7);
	Tuple v_diff = Vector(-2, -4, -6);

	CHECK((v1 - v2) == v_diff);
}

TEST(TupleTest, negate_tuple)
{
	Tuple v1 = Vector(1, -2, 3);
	Tuple v_n = Vector(-1, 2, -3);

	CHECK(-v1 == v_n);
}

TEST(TupleTest, multiply_tuple_by_scalar)
{
    Tuple t1 = Tuple(1, -2, 3, -4);
    Tuple t_res = Tuple(3.5, -7, 10.5, -14);

    CHECK(t1 * 3.5 == t_res);
}

TEST(TupleTest, multiply_tuple_by_fraction)
{
    Tuple t1 = Tuple(1, -2, 3, -4);
    Tuple t_res = Tuple(0.5, -1, 1.5, -2);

    CHECK(t1 * 0.5 == t_res);
}

TEST(TupleTest, divide_tuple_by_scalar)
{
    Tuple t1 = Tuple(1, -2, 3, -4);
    Tuple t_res = Tuple(0.5, -1, 1.5, -2);

    CHECK(t1 / 2 == t_res);
}

TEST(TupleTest, Magnitude)
{
    CHECK(Vector(1, 0, 0).Magnitude() == 1);
    CHECK(Vector(0, 1, 0).Magnitude() == 1);
    CHECK(Vector(0, 0, 1).Magnitude() == 1);
    DOUBLES_EQUAL(Vector(1, 2, 3).Magnitude(), sqrtf(14), EPSILON);
    DOUBLES_EQUAL(Vector(-1, -2, -3).Magnitude(), sqrtf(14), EPSILON);
}

TEST(TupleTest, Normalize)
{
    Tuple t_norm = Vector(1, 2, 3).Normalize();

    CHECK(Vector(4, 0, 0).Normalize() == Vector(1, 0, 0));
    CHECK(t_norm == Vector(1/sqrtf(14), 2/sqrtf(14), 3/sqrtf(14)));

    DOUBLES_EQUAL(t_norm.Magnitude(), 1, EPSILON);
}

TEST(TupleTest, Dot)
{
    DOUBLES_EQUAL(Vector(1, 2, 3).Dot(Vector(2, 3, 4)), 20, EPSILON);
}

TEST(TupleTest, Cross)
{
    CHECK(Vector(1, 2, 3).Cross(Vector(2, 3, 4)) == Vector(-1, 2, -1));
    CHECK(Vector(2, 3, 4).Cross(Vector(1, 2, 3)) == Vector(1, -2, 1));
}

TEST(TupleTest, Reflect)
{
    Tuple v = Vector(0, -1, 0);
    Tuple n = Vector(sqrtf(2)/2, sqrtf(2)/2, 0);

    CHECK(v.Reflect(n) == Vector(1, 0, 0));
}

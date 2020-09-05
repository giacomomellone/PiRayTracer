/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include <CppUTest/TestHarness.h>

//-- module being tested
#include "../include/intersection.h"
#include "../include/shapes/sphere.h"

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

TEST_GROUP(SphereTest) {};

TEST(SphereTest, intersectionsTangent)
{
    Sphere s;
    Ray r(Point(0, 1, -5), Vector(0, 0, 1));

    vector<Intersection> xs = s.Intersect(r);
    CHECK(xs.size() == 2);
    DOUBLES_EQUAL(5, xs[0].t, EPSILON);
    DOUBLES_EQUAL(5, xs[1].t, EPSILON);
}

TEST(SphereTest, intersectionsMiss)
{
    Sphere s;
    Ray r(Point(0, 2, -5), Vector(0, 0, 1));

    vector<Intersection> xs = s.Intersect(r);
    CHECK(xs.size() == 0);
    UNSIGNED_LONGS_EQUAL(0, xs[0].t);
    DOUBLES_EQUAL(0, xs[1].t, EPSILON);
}

TEST(SphereTest, intersectionsInside)
{
    Sphere s;
    Ray r(Point(0, 0, 0), Vector(0, 0, 1));

    vector<Intersection> xs = s.Intersect(r);
    CHECK(xs.size() == 2);
    DOUBLES_EQUAL(-1, xs[0].t, EPSILON);
    DOUBLES_EQUAL(1, xs[1].t, EPSILON);
}

TEST(SphereTest, identititySphereMatrix)
{
    Sphere s;

    CHECK(s.transfM == IdentityMatrix(4, 4));
}

TEST(SphereTest, transformationSphereMatrix)
{
    Sphere s;

    s.SetTranformation(Translation(2, 3, 4));

    CHECK(s.transfM == Translation(2, 3, 4));
}

TEST(SphereTest, scaledSphereIntersectionWithRay)
{
    Sphere s;
    Ray r(Point(0, 0, -5), Vector(0, 0, 1));

    s.SetTranformation(Scaling(2, 2, 2));

    vector<Intersection> xs = s.Intersect(r);

    UNSIGNED_LONGS_EQUAL(2, xs.size());

    UNSIGNED_LONGS_EQUAL(3, xs[0].t);
    UNSIGNED_LONGS_EQUAL(7, xs[1].t);
}

TEST(SphereTest, translatedSphereIntersectionWithRay)
{
    Sphere s;
    Ray r(Point(0, 0, -5), Vector(0, 0, 1));

    s.SetTranformation(Translation(5, 0, 0));

    vector<Intersection> xs = s.Intersect(r);

    UNSIGNED_LONGS_EQUAL(0, xs.size());
}

TEST(SphereTest, NormalToSphere)
{
    Sphere s1;
    Tuple sN = s1.Normal(Point(1, 0, 0));

    CHECK(sN == Vector(1, 0, 0));

    Sphere s2;
    sN = s2.Normal(Point(0, 1, 0));

    CHECK(sN == Vector(0, 1, 0));

    Sphere s3;
    sN = s3.Normal(Point(0, 0, 1));

    CHECK(sN == Vector(0, 0, 1));

    Sphere s4;
    sN = s4.Normal(Point(sqrtf(3)/3, sqrtf(3)/3, sqrtf(3)/3));

    CHECK(sN == Vector(sqrtf(3)/3, sqrtf(3)/3, sqrtf(3)/3));
}

TEST(SphereTest, TransformedSphereNormalTranslation)
{
    Sphere s;

    s.SetTranformation(Translation(0, 1, 0));

    Tuple sN = s.Normal(Point(0, 1.70711, -0.70711));

    CHECK(sN == Vector(0, 0.70711, -0.70711));
}


TEST(SphereTest, TransformedSphereNormal)
{
    Sphere s;

    s.SetTranformation(Scaling(1, 0.5, 1) * RotationZ(M_PI/5));

    Tuple sN = s.Normal(Point(0, sqrtf(2)/2, -sqrtf(2)/2));

    CHECK(sN == Vector(0, 0.97014, -0.24254));
}

TEST(SphereTest, defaultMaterial)
{
    Sphere s;
    Material m;

   CHECK(s.material == m);
}

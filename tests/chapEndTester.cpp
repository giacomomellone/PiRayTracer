/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include <CppUTest/TestHarness.h>

//-- module being tested
#include "../include/tuple.h"
#include "../include/color.h"
#include "../include/canvas.h"
#include "../include/matrix.h"
#include "../include/transformation.h"


/*******************************************************************************
 *    DEFINITIONS
 ******************************************************************************/

/*******************************************************************************
 *    PRIVATE TYPES
 ******************************************************************************/
class Projectile
{
    public:
        Tuple position, velocity;

        Projectile(Tuple position, Tuple velocity);
};

class Environment
{
    public:
        Tuple gravity, wind;

        Environment(Tuple gravity, Tuple wind);
};

Projectile tick(Environment e, Projectile p);

/*******************************************************************************
 *    PRIVATE DATA
 ******************************************************************************/

/*******************************************************************************
 *    PRIVATE FUNCTIONS
 ******************************************************************************/
Projectile::Projectile(Tuple position, Tuple velocity)
{
    this->position = position;
    this->velocity = velocity;
}

Environment::Environment(Tuple gravity, Tuple wind)
{
    this->gravity = gravity;
    this->wind = wind;
}

Projectile tick(Environment e, Projectile p)
{
    Tuple pos = p.position + p.velocity;
    Tuple vel = p.velocity + e.gravity + e.wind;

    return Projectile(pos, vel);
}

/*******************************************************************************
 *    SETUP, TEARDOWN
 ******************************************************************************/

/*******************************************************************************
 *    TESTS
 ******************************************************************************/

TEST_GROUP(EndChapterTest) {};

TEST(EndChapterTest, Chap1_projectile)
{
    Tuple projPosition = Point(0, 1, 0.3);
    Tuple projVelocity = Vector(1, 1, -0.3);

    Tuple envGravity = Vector(0, -0.05, 0);
    Tuple envWind = Vector(-0.01, 0, 0);

    Projectile p = Projectile(projPosition, projVelocity.Normalize());
    Environment e = Environment(envGravity, envWind);

    int count = 0;

    while (p.position.y > 0)
    {
//        printf("\n%d: Proj.pos.x = %f, Proj.pos.y = %f, Proj.pos.z = %f",
//                count, p.position.x, p.position.y, p.position.z);
        p = tick(e, p);

        count++;
    }
}

TEST(EndChapterTest, Chap2_projectileCanvas)
{
    Tuple projPosition = Point(0, 1, 0);
    Tuple projVelocity = Vector(10, 5.8, 0);

    Tuple envGravity = Vector(0, -0.01, 0);
    Tuple envWind = Vector(-0.01, 0, 0);

    Projectile p = Projectile(projPosition, projVelocity.Normalize());
    Environment e = Environment(envGravity, envWind);

    Canvas cv = Canvas(800, 300);

    Color co = Color(1, 1, 1);

    int count = 0;

    while (p.position.y > 0)
    {
//        printf("\n%d: Proj.pos.x = %f, Proj.pos.y = %f, Proj.pos.z = %f",
//                count, p.position.x, p.position.y, p.position.z);

        cv.WritePixel(p.position.x * 20, cv.y - (p.position.y * 20), co);
        p = tick(e, p);

        count++;
    }

    cv.SavePPM("0x002.ppm");
}

TEST(EndChapterTest, Chap4_watchRotation)
{
    uint32_t side = 300;

    Canvas cv = Canvas(side, side);
    Color co = Color(1, 1, 1);

    Tuple origin = Point(100, 0, 0);

    Matrix tr = Translation(side/2, side/2, 0);
    Matrix rot_z = RotationZ(M_PI / 6);

    Tuple p = tr * origin;

    for (int i = 0; i < 12; i++)
    {
        origin = rot_z * origin;
        p = tr * rot_z * origin;
//        printf("%d) p.x: %f, p.y: %f\n", i, p.x, p.y);
        cv.WritePixel(p.x, cv.y - p.y, co);
    }

    cv.SavePPM("0x003.ppm");
}

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
#include "../include/ray.h"
#include "../include/intersection.h"
#include "../include/shapes/sphere.h"


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
//    Tuple projPosition = Point(0, 1, 0.3);
//    Tuple projVelocity = Vector(1, 1, -0.3);
//
//    Tuple envGravity = Vector(0, -0.05, 0);
//    Tuple envWind = Vector(-0.01, 0, 0);
//
//    Projectile p = Projectile(projPosition, projVelocity.Normalize());
//    Environment e = Environment(envGravity, envWind);
//
//    int count = 0;
//
//    while (p.position.y > 0)
//    {
////        printf("\n%d: Proj.pos.x = %f, Proj.pos.y = %f, Proj.pos.z = %f",
////                count, p.position.x, p.position.y, p.position.z);
//        p = tick(e, p);
//
//        count++;
//    }
}

TEST(EndChapterTest, Chap2_projectileCanvas)
{
//    Tuple projPosition = Point(0, 1, 0);
//    Tuple projVelocity = Vector(10, 5.8, 0);
//
//    Tuple envGravity = Vector(0, -0.01, 0);
//    Tuple envWind = Vector(-0.01, 0, 0);
//
//    Projectile p = Projectile(projPosition, projVelocity.Normalize());
//    Environment e = Environment(envGravity, envWind);
//
//    Canvas cv = Canvas(800, 300);
//
//    Color co = Color(1, 1, 1);
//
//    int count = 0;
//
//    while (p.position.y > 0)
//    {
////        printf("\n%d: Proj.pos.x = %f, Proj.pos.y = %f, Proj.pos.z = %f",
////                count, p.position.x, p.position.y, p.position.z);
//
//        cv.WritePixel(p.position.x * 20, cv.y - (p.position.y * 20), co);
//        p = tick(e, p);
//
//        count++;
//    }
//
//    cv.SavePPM("0x002.ppm");
}

TEST(EndChapterTest, Chap4_watchRotation)
{
//    uint32_t side = 300;
//
//    Canvas cv = Canvas(side, side);
//    Color co = Color(1, 1, 1);
//
//    Tuple origin = Point(100, 0, 0);
//
//    Matrix tr = Translation(side/2, side/2, 0);
//    Matrix rot_z = RotationZ(M_PI / 6);
//
//    Tuple p = tr * origin;
//
//    for (int i = 0; i < 12; i++)
//    {
//        origin = rot_z * origin;
//        p = tr * rot_z * origin;
////        printf("%d) p.x: %f, p.y: %f\n", i, p.x, p.y);
//        cv.WritePixel(p.x, cv.y - p.y, co);
//    }
//
//    cv.SavePPM("0x003.ppm");
}

TEST(EndChapterTest, Chap5_RaySphereIntersection)
{
//    uint32_t cv_px = 100;
//    int wall_z = 1;
//    float wall_size = 7.0;
//    float pixel_size = wall_size / cv_px;
//    float half = wall_size / 2;
//    float world_x, world_y;
//
//    Sphere s;
//    s.SetTranformation(Translation(1, -1, 0));
//    Tuple rayOrigin = Point(0, 0, -3);
//
//    Canvas cv = Canvas(cv_px, cv_px);
//    Color red = Color(1, 0, 0);
//
//    for (uint32_t y = 0; y < cv_px - 1; y++)
//    {
//        world_y = half - pixel_size * y;
//
//        for (uint32_t x = 0; x < cv_px - 1; x++)
//        {
//            world_x = - half + pixel_size * x;
//
//            Tuple pW = Point(world_x, world_y, wall_z);
//
//            Ray rW(rayOrigin, (pW - rayOrigin).Normalize());
//
//            vector<Intersection> xs = s.Intersect(rW);
//
//            if (Hit(&xs) != nullptr)
//            {
//                cv.WritePixel(x, y, red);
//            }
//        }
//    }
//
//    cv.SavePPM("0x004.ppm");
}

TEST(EndChapterTest, Chap6__LightAndShading)
{
    uint32_t cv_px = 100;
    int wall_z = 10;
    float wall_size = 7.0;
    float pixel_size = wall_size / cv_px;
    float half = wall_size / 2;
    float world_x, world_y;

    Sphere s;
    s.material.color = Color(1, 0, 0);
    s.material.ambient = 0.1;
    s.material.diffuse = 0.9;
    s.material.specular = 0.9;
    s.material.shininess = 200;

//    s.SetTranformation(Translation(1, -1, 0));
    Tuple rayOrigin = Point(0, 0, -5);

    Canvas cv = Canvas(cv_px, cv_px);

    Light lightP(Point(-10, 10, -10), Color(1, 1, 1));

    for (uint32_t y = 0; y < cv_px - 1; y++)
    {
        world_y = half - pixel_size * y;

        for (uint32_t x = 0; x < cv_px - 1; x++)
        {
            world_x = - half + pixel_size * x;

            Tuple pW = Point(world_x, world_y, wall_z);

            /* Normalize the ray direction, otherwise the light
             * cast won't work
             */
            Ray rW(rayOrigin, (pW - rayOrigin).Normalize());

            vector<Intersection> xs = s.Intersect(rW);

            Intersection hit = Hit(xs);

            if (hit.s != nullptr)
            {
                /* Calculate the normal vector at the hit */
                Tuple pointHit = rW.Position(hit.t);
                Tuple normalAtHit = hit.s->Normal(pointHit);
                Tuple eyeV = -rW.directionV;

                cv.WritePixel(x, y, Lighting(s.material, lightP, pointHit, eyeV, normalAtHit));
            }
        }
    }

    cv.SavePPM("0x005.ppm");
}

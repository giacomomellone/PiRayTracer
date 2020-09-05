#include <iostream>

#include "../include/tuple.h"
#include "../include/color.h"
#include "../include/canvas.h"
#include "../include/matrix.h"
#include "../include/transformation.h"
#include "../include/ray.h"
#include "../include/intersection.h"
#include "../include/shapes/sphere.h"

using namespace std;

int main(int argc, char **argv)
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

    cv.SavePPM("PiRayTracer.ppm");

	return 0;
}

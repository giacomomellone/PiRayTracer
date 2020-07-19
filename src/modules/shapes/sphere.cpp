/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include "../../../include/shapes/sphere.h"

/*******************************************************************************
 *    CONSTRUCTOR, DESTRUCTOR
 ******************************************************************************/

Sphere::Sphere()
{
    this->originP = Point(0, 0, 0);
    this->radius = 1;
}

/*******************************************************************************
 *    PUBLIC METHODS
 ******************************************************************************/
int Sphere::Intersect(Ray r, vector<Intersection> &p)
{
    /* Calculate the discriminant to know whether the ray
     * intersect the sphere */
    Tuple sphereToRay = r.originP - this->originP;

    float a = r.directionV.Dot(r.directionV);
    float b = 2 * r.directionV.Dot(sphereToRay);
    float c = sphereToRay.Dot(sphereToRay) - 1;

    float discriminant = powf(b, 2) - 4 * a * c;

    if (discriminant < 0)
    {
        p[0].t = p[1].t = 0;
        return 0;
    }
    else
    {
        p[0].t = (-b - sqrtf(discriminant)) / (2 * a);
        p[1].t = (-b + sqrtf(discriminant)) / (2 * a);

        if (p[0].t > p[1].t)
        {

            sort(p.begin(), p.end(),
                    [](Intersection & i1, Intersection & i2){return i1.t < i2.t;});
        }

        return 2;
    }
}

/*******************************************************************************
 *    CLASS SUPPORT FUNCTIONS
 ******************************************************************************/



/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include "../../include/intersection.h"

/*******************************************************************************
 *    CONSTRUCTOR, DESTRUCTOR
 ******************************************************************************/

Intersection::Intersection(float xsValue, Sphere s)
{
    this->t = xsValue;
    this->s = s;
}

/*******************************************************************************
 *    PUBLIC METHODS
 ******************************************************************************/
bool Intersection::operator== (Intersection const &other)
{
    if(equal(this->t, other.t) && (this->s == other.s))
    {
        return true;
    }
    else
        return false;
}

bool Intersection::operator< (Intersection const &other)
{
    return this->t < other.t;
}

vector<Intersection> Intersect(Sphere s, Ray r)
{
    vector<Intersection> intV(2);

    /* Apply the inverse of the sphere transformation
     * to the ray itself
     */
    r = r.Transform(s.transfM.Inverse());

    /* Calculate the discriminant to know whether the ray
     * intersect the sphere */
    Tuple sphereToRay = r.originP - s.originP;

    float a = r.directionV.Dot(r.directionV);
    float b = 2 * r.directionV.Dot(sphereToRay);
    float c = sphereToRay.Dot(sphereToRay) - 1;

    float discriminant = powf(b, 2) - 4 * a * c;

    if (discriminant < 0)
    {
        intV.clear();
    }
    else
    {
        intV[0].t = (-b - sqrtf(discriminant)) / (2 * a);
        intV[1].t = (-b + sqrtf(discriminant)) / (2 * a);

        if (intV[0].t > intV[1].t)
        {
            sort(intV.begin(), intV.end(),
                    [](Intersection & i1, Intersection & i2){return i1.t < i2.t;});
        }
    }

    return intV;
}

Intersection* Hit(vector<Intersection> *xs)
{
    for(size_t i = 0; i < xs->size(); i++)
    {
        if (xs->at(i).t >= 0)
        {
            return &xs->at(i);
        }
    }

    return NULL;
}
/*******************************************************************************
 *    CLASS SUPPORT FUNCTIONS
 ******************************************************************************/
bool compareIntersections (const Intersection &i1, const Intersection &i2)
{
    return i1.t < i2.t;
}

/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include "../../include/intersection.h"

/*******************************************************************************
 *    CONSTRUCTOR, DESTRUCTOR
 ******************************************************************************/

Intersection::Intersection(float xsValue, Sphere *s)
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

Intersection Hit(vector<Intersection> const &xs)
{
    for (auto x : xs)
    {
        /* Return first non-zero element */
        if(x.t > 0.f)
        {
            return x;
        }
    }

    return Intersection(0, nullptr);
}

comps_s prepareComputation(Intersection const& i, Ray r)
{
    comps_s comps;

    comps.t = i.t;
    comps.object = i.s;
    comps.point = r.Position(comps.t);
    comps.eyeV = -r.directionV;
    comps.normalV = comps.object->Normal(comps.point);

    if (comps.normalV.Dot(comps.eyeV) < 0)
    {
        comps.inside = true;
        comps.normalV = -comps.normalV;
    }
    else
    {
        comps.inside = false;
    }

    return comps;
}

/*******************************************************************************
 *    CLASS SUPPORT FUNCTIONS
 ******************************************************************************/
bool compareIntersections (const Intersection &i1, const Intersection &i2)
{
    return i1.t < i2.t;
}

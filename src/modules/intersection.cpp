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

vector<Intersection> IntersectWorld(World w, Ray r)
{
    vector<Intersection> intS1(2);
    vector<Intersection> intS2(2);

    intS1 = Intersect(w.s1, r);
    intS2 = Intersect(w.s2, r);

    vector<Intersection> intAll(intS1.size() + intS2.size());

    /* Append S2 intersections to S1 */
    intS1.insert(intS1.end(), intS2.begin(), intS2.end());
    intAll = intS1;

    /* Sort the intersections */
    sort(intAll.begin(), intAll.end(),
            [](Intersection & i1, Intersection & i2){return i1.t < i2.t;});

    return intAll;
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

comps_s prepareComputation(Intersection i, Ray r)
{
    comps_s comps;

    comps.t = i.t;
    comps.object = &i.s;
    comps.point = r.Position(comps.t);
    comps.eyeV = -r.directionV;
    comps.normalV = comps.object->Normal(comps.point);

    return comps;
}

/*******************************************************************************
 *    CLASS SUPPORT FUNCTIONS
 ******************************************************************************/
bool compareIntersections (const Intersection &i1, const Intersection &i2)
{
    return i1.t < i2.t;
}

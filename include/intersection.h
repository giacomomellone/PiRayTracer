/*******************************************************************************
 *    Intersections header
 ******************************************************************************/

#ifndef INCLUDE_INTERSECTION_H_
#define INCLUDE_INTERSECTION_H_

/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include <vector>
#include "tuple.h"
#include "ray.h"
#include "shapes/sphere.h"
#include "support/utils.h"

using namespace std;
/*******************************************************************************
 *    PUBLIC TYPES
 ******************************************************************************/

/**
 * Intersection object
 *
 */
class Intersection
{
    public:
        float t;
        Sphere s;

        /********** CTOR / DTOR ***********/
        Intersection(float xsValue, Sphere s);
        Intersection() {this->t = 0; this->s = Sphere();}

        bool operator== (const Intersection &);
        bool operator< (const Intersection &);

        /********** PUBLIC METHOD PROTOTYPES ***********/
};

vector<Intersection> Intersect(Sphere s, Ray r);

/*******************************************************************************
 *    CLASS SUPPORT FUNCTIONS PROTOTYPES
 ******************************************************************************/
bool compareIntersections(const Intersection &i1, const Intersection &i2);

template<typename... Args>
vector<Intersection> Intersections(Args const&... args)
{
    vector<Intersection> retVal{ args... };
    sort(retVal.begin(), retVal.end());

    return retVal;
}

Intersection* Hit(vector<Intersection> *xs);

#endif /* INCLUDE_INTERSECTION_H_ */

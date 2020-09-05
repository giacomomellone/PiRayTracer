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
#include "world.h"
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
        Sphere *s;

        /********** CTOR / DTOR ***********/
        Intersection(float xsValue, Sphere *s);
        Intersection() {this->t = 0; this->s = nullptr;}

        bool operator== (const Intersection &);
        bool operator< (const Intersection &);

        /********** PUBLIC METHOD PROTOTYPES ***********/
};

typedef struct computation
{
    float t;
    Sphere *object;
    Tuple point;
    Tuple eyeV;
    Tuple normalV;
    bool inside; /* Has the interesection occured inside the object? */
} comps_s;

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

Intersection Hit(vector<Intersection> const &xs);

comps_s prepareComputation(Intersection const& i, Ray r);

#endif /* INCLUDE_INTERSECTION_H_ */

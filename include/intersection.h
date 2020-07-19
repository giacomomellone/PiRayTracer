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
#include "support/utils.h"

using namespace std;
/*******************************************************************************
 *    PUBLIC TYPES
 ******************************************************************************/

/* Forward declarations */
class Shape;

/**
 * Intersection object
 *
 */
class Intersection
{
    public:
        float t;
        Shape *s;

        /********** CTOR / DTOR ***********/
        Intersection(float xsValue, Shape *s);
        Intersection() {this->t = 0; this->s = NULL;}

        bool operator== (const Intersection &);
        bool operator< (const Intersection &);

        /********** PUBLIC METHOD PROTOTYPES ***********/
};

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

Intersection Hit(vector<Intersection> xs);

#endif /* INCLUDE_INTERSECTION_H_ */

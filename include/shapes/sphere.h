/*******************************************************************************
 *    Sphere header
 ******************************************************************************/

#ifndef INCLUDE_SPHERE_H_
#define INCLUDE_SPHERE_H_

/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include "../shapes/shape.h"
#include "../intersection.h"
/*******************************************************************************
 *    PUBLIC TYPES
 ******************************************************************************/

/* Forward declarations */
class Shape;
class Intersection;

/**
 * Sphere object
 *
 */
class Sphere: public Shape
{
    public:
        Tuple originP;
        float radius;

        /********** CTOR / DTOR ***********/
        Sphere();

        /********** PUBLIC METHOD PROTOTYPES ***********/
        int Intersect(Ray r, vector<Intersection> &p);
};

/*******************************************************************************
 *    CLASS SUPPORT FUNCTIONS PROTOTYPES
 ******************************************************************************/


#endif /* INCLUDE_SPHERE_H_ */

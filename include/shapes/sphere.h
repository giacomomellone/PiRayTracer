/*******************************************************************************
 *    Sphere header
 ******************************************************************************/

#ifndef INCLUDE_SPHERE_H_
#define INCLUDE_SPHERE_H_

/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include "../shapes/shape.h"
#include "../ray.h"
/*******************************************************************************
 *    PUBLIC TYPES
 ******************************************************************************/
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
        Sphere(Material material);

        /********** PUBLIC METHOD PROTOTYPES ***********/
        Tuple Normal(Tuple worldPoint);
        vector<Intersection> Intersect(Ray const &r);
};

/*******************************************************************************
 *    CLASS SUPPORT FUNCTIONS PROTOTYPES
 ******************************************************************************/


#endif /* INCLUDE_SPHERE_H_ */

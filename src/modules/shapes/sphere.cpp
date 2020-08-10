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
    this->material = Material();
}

Sphere::Sphere(Material material)
{
    this->originP = Point(0, 0, 0);
    this->radius = 1;
    this->material = material;
}

/*******************************************************************************
 *    PUBLIC METHODS
 ******************************************************************************/
Tuple Sphere::Normal(Tuple worldPoint)
{
    Tuple objPoint = this->transfM.Inverse() * worldPoint;
    Tuple objNormal = objPoint - Point(0, 0, 0);
    Tuple worldNormal = (this->transfM.Inverse()).Transpose() * objNormal;

    /* if your transform includes any kind of translation,
     * then multiplying by its transpose will wind up mucking
     * with the w coordinate in your vector */
    worldNormal.w = 0;

    return worldNormal.Normalize();
};

/*******************************************************************************
 *    CLASS SUPPORT FUNCTIONS
 ******************************************************************************/



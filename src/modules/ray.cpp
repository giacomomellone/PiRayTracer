/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include "../../include/ray.h"

/*******************************************************************************
 *    CONSTRUCTOR, DESTRUCTOR
 ******************************************************************************/

Ray::Ray(Tuple originP, Tuple directionV)
{
    this->originP = originP;
    this->directionV = directionV;
}

/*******************************************************************************
 *    PUBLIC METHODS
 ******************************************************************************/
Tuple Ray::Position(float distance)
{
    return (this->originP + this->directionV * distance);
}

Ray Ray::Transform(Matrix m)
{
    Tuple originPTransformed = m * this->originP;
    Tuple directionVTransformed = m * this->directionV;

    return Ray(originPTransformed, directionVTransformed);
}
/*******************************************************************************
 *    CLASS SUPPORT FUNCTIONS
 ******************************************************************************/

/*******************************************************************************
 *    Rays header
 ******************************************************************************/

#ifndef INCLUDE_RAY_H_
#define INCLUDE_RAY_H_

/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include "tuple.h"
#include "matrix.h"
#include "transformation.h"
/*******************************************************************************
 *    PUBLIC TYPES
 ******************************************************************************/

/**
 * Ray object
 *
 */
class Ray
{
    public:
        Tuple originP, directionV;

        /********** CTOR / DTOR ***********/
        Ray(Tuple originP, Tuple directionV);

        /********** PUBLIC METHOD PROTOTYPES ***********/
        Tuple Position(float distance);
        Ray Transform(Matrix m);
};

/*******************************************************************************
 *    CLASS SUPPORT FUNCTIONS PROTOTYPES
 ******************************************************************************/


#endif /* INCLUDE_RAY_H_ */

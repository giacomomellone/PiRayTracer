/*******************************************************************************
 *    Sphere header
 ******************************************************************************/
#ifndef INCLUDE_SHAPE_H_
#define INCLUDE_SHAPE_H_

/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include <vector>
#include <algorithm>
#include <cmath>
#include "../tuple.h"
#include "../ray.h"
#include "../support/utils.h"

using namespace std;
/*******************************************************************************
 *    PUBLIC TYPES
 ******************************************************************************/

/**
 * Shape object
 *
 */
class Shape
{
    public:
        static int shapesCount;
        int shapeID;

        /********** CTOR / DTOR ***********/
        Shape();
        virtual ~Shape() {};

        /********** PUBLIC METHOD PROTOTYPES ***********/
        friend bool operator== (const Shape &s1, const Shape &s2);
};

/*******************************************************************************
 *    CLASS SUPPORT FUNCTIONS PROTOTYPES
 ******************************************************************************/


#endif /* INCLUDE_SHAPE_H_ */

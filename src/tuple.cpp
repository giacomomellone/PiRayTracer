/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include "../include/tuple.h"

/*******************************************************************************
 *    CONSTRUCTOR, DESTRUCTOR
 ******************************************************************************/

Tuple::Tuple(float x, float y, float z, float w)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

Tuple::Tuple()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
    this->w = 0;
}

/*******************************************************************************
 *    PUBLIC METHODS
 ******************************************************************************/

bool Tuple::IsPoint()
{
    return equal(this->w, 1.0);
}

bool Tuple::IsVector()
{
    return equal(this->w, 0.0);
}

/*******************************************************************************
 *    CLASS SUPPORT FUNCTIONS
 ******************************************************************************/

Tuple Point(float x, float y, float z)
{
	return Tuple(x, y, z, 1);
}

Tuple Vector(float x, float y, float z)
{
	return Tuple(x, y, z, 0);
}



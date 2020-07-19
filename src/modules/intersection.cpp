/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include "../../include/intersection.h"

/*******************************************************************************
 *    CONSTRUCTOR, DESTRUCTOR
 ******************************************************************************/

Intersection::Intersection(float xsValue, Shape *s)
{
    this->t = xsValue;
    this->s = s;
}

/*******************************************************************************
 *    PUBLIC METHODS
 ******************************************************************************/
bool Intersection::operator== (Intersection const &other)
{
    if(equal(this->t, other.t) && (this->s == other.s))
    {
        return true;
    }
    else
        return false;
}

bool Intersection::operator< (Intersection const &other)
{
    return this->t < other.t;
}
/*******************************************************************************
 *    CLASS SUPPORT FUNCTIONS
 ******************************************************************************/
bool compareIntersections (const Intersection &i1, const Intersection &i2)
{
    return i1.t < i2.t;
}

//Intersection Hit(vector<Intersection> xs)
//{
//    return 0;
//}

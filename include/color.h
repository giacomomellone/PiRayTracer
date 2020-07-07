/*******************************************************************************
 *    Color header
 ******************************************************************************/

#ifndef COLOR_HPP
#define COLOR_HPP

/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/

#include "utils.h"
#include "tuple.h"
#include <stdlib.h>
#include <cmath>

using namespace std;

/*******************************************************************************
 *    PUBLIC TYPES
 ******************************************************************************/

/**
 * Tuple object
 *
 */
class Color: public Tuple
{
    public:
        /********** CTOR / DTOR ***********/
        Color(float r, float g, float b) : Tuple(r, g, b, 0) {};

        /********** PUBLIC METHOD PROTOTYPES ***********/
        inline float r() 
        {
            return this->x;
        }
        
        inline float g() 
        {
            return this->y;
        }
        
        inline float b() 
        {
            return this->z;
        }

        inline friend Color operator * (Color &c1, Color &c2)
        {
            return Color(
                    c1.r() * c2.r(),
                    c1.g() * c2.g(),
                    c1.b() * c2.b());
        }
};

/*******************************************************************************
 *    CLASS SUPPORT FUNCTIONS PROTOTYPES
 ******************************************************************************/

#endif // COLOR_HPP_

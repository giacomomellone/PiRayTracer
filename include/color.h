/*******************************************************************************
 *    Color header
 ******************************************************************************/

#ifndef COLOR_HPP
#define COLOR_HPP

/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include <stdlib.h>
#include <cmath>
#include "tuple.h"

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
        Color() : Tuple(0, 0, 0, 0) {};

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

        inline friend Color operator + (Color &c1, Color &c2)
        {
            return Color(
                    c1.r() + c2.r(),
                    c1.g() + c2.g(),
                    c1.b() + c2.b());
        }

        inline friend Color operator * (Color &c1, Color &c2)
        {
            return Color(
                    c1.r() * c2.r(),
                    c1.g() * c2.g(),
                    c1.b() * c2.b());
        }

        inline friend Color operator * (Color &c, const float &s)
        {
            return Color(
                    c.r() * s,
                    c.g() * s,
                    c.b() * s);
        }

        inline friend Color operator * (const float &s, Color &c)
        {
            return c * s;
        }
};

/*******************************************************************************
 *    CLASS SUPPORT FUNCTIONS PROTOTYPES
 ******************************************************************************/

#endif // COLOR_HPP_

/*******************************************************************************
 *    Tuple header
 ******************************************************************************/

#ifndef TUPLE_HPP
#define TUPLE_HPP

/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/

#include "utils.h"
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
class Tuple
{
	public:
		float x, y, z, w;

		/********** CTOR / DTOR ***********/
		Tuple();
		Tuple(float x, float y, float z, float w);

		/********** PUBLIC METHOD PROTOTYPES ***********/
		bool IsPoint();
		bool IsVector();
		float Magnitude();

		friend bool operator == (const Tuple &t1, const Tuple &t2);
		friend Tuple operator + (const Tuple &t1, const Tuple &t2);
};

/*******************************************************************************
 *    CLASS SUPPORT FUNCTIONS PROTOTYPES
 ******************************************************************************/

Tuple Point(float x, float y, float z);
Tuple Vector(float x, float y, float z);

#endif // TUPLE_HPP_

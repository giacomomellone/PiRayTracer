/*******************************************************************************
 *    Tuple header
 ******************************************************************************/

#ifndef TUPLE_HPP
#define TUPLE_HPP

/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include <stdlib.h>
#include <cmath>
#include "utils.h"

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
		Tuple Normalize();
		float Dot(Tuple const &t);
		Tuple Cross(Tuple const &t);

		friend bool operator == (const Tuple &t1, const Tuple &t2);
		friend Tuple operator + (const Tuple &t1, const Tuple &t2);
		friend Tuple operator - (const Tuple &t1, const Tuple &t2);
		friend Tuple operator - (const Tuple &t);
		friend Tuple operator * (const Tuple &t, const float &s);
		friend float operator * (const Tuple &t1, const Tuple &t2);
		friend Tuple operator / (const Tuple &t, const float &s);
};

/*******************************************************************************
 *    CLASS SUPPORT FUNCTIONS PROTOTYPES
 ******************************************************************************/

Tuple Point(float x, float y, float z);
Tuple Vector(float x, float y, float z);

#endif // TUPLE_HPP_

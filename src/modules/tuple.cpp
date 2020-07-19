/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include "../../include/tuple.h"

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

float Tuple::Magnitude()
{
    return sqrtf(powf(this->x, 2) + powf(this->y, 2) + powf(this->z, 2));
}

Tuple Tuple::Normalize()
{
    float mag = this->Magnitude();

    return Vector(this->x / mag, this->y / mag, this->z / mag);
}

float Tuple::Dot (const Tuple &t)
{
    return this->x * t.x +
           this->y * t.y +
           this->z * t.z +
           this->w * t.w;
}

Tuple Tuple::Cross (const Tuple &t)
{
    return Vector(
           this->y * t.z - this->z * t.y,
           this->z * t.x - this->x * t.z,
           this->x * t.y - this->y * t.x);
}

float Tuple::operator() (int pos) const
{
    assert (pos < 4);

    switch (pos)
    {
    case 0:
        return this->x;
    case 1:
        return this->y;
    case 2:
        return this->z;
    case 3:
        return this->w;
    default:
        return 0;
    }
}

float& Tuple::operator() (int pos)
{
    assert (pos < 4);

    switch (pos)
    {
    default:
    case 0:
        return this->x;
    case 1:
        return this->y;
    case 2:
        return this->z;
    case 3:
        return this->w;
    }
}

bool operator == (const Tuple &t1, const Tuple &t2)
{
	return (equal(t1.x, t2.x) &&
			equal(t1.y, t2.y) &&
			equal(t1.z, t2.z) &&
			equal(t1.w, t2.w)
			);
}

Tuple operator + (const Tuple &t1, const Tuple &t2)
{
	return Tuple(
			t1.x + t2.x,
			t1.y + t2.y,
			t1.z + t2.z,
			t1.w + t2.w);
}

Tuple operator - (const Tuple &t1, const Tuple &t2)
{
	return Tuple(
			t1.x - t2.x,
			t1.y - t2.y,
			t1.z - t2.z,
			t1.w - t2.w);
}

Tuple operator - (const Tuple &t)
{
	return Tuple( -t.x, -t.y, -t.z, -t.w);
}

Tuple operator * (const Tuple &t, const float &s)
{
    return Tuple(
            t.x * s,
            t.y * s,
            t.z * s,
            t.w * s);
}

Tuple operator * (const float &s, const Tuple &t)
{
    return t * s;
}

Tuple operator / (const Tuple &t, const float &s)
{
    return Tuple(
            t.x / s,
            t.y / s,
            t.z / s,
            t.w / s);
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


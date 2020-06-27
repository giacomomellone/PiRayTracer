/*
 * utils.cpp
 *
 *  Created on: 28 giu 2020
 *      Author: deddi
 */

#include "../include/utils.h"

bool equal(float x, float y)
{
    return (fabs(x -y) < EPSILON);
}


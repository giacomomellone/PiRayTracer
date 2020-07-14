/*******************************************************************************
 *    Tuple header
 ******************************************************************************/

#ifndef TRANSFORMATION_HPP
#define TRANSFORMATION_HPP

/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include <stdlib.h>
#include <stdint.h>
#include "matrix.h"

using namespace std;

/*******************************************************************************
 *    PUBLIC TYPES
 ******************************************************************************/
Matrix Translation(float x, float y, float z);

Matrix Scaling(float x, float y, float z);

#endif // TRANSFORMATION_HPP

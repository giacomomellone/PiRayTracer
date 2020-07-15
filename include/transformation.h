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

Matrix RotationX(float rad);
Matrix RotationY(float rad);
Matrix RotationZ(float rad);

Matrix Shearing(float x_y, float x_z, float y_x, float y_z,
        float z_x, float z_y);

#endif // TRANSFORMATION_HPP

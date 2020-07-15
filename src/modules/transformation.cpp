/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include <assert.h>
#include "../../include/transformation.h"

/*******************************************************************************
 *    PRIVATES
 ******************************************************************************/

Matrix Translation(float x, float y, float z)
{
    Matrix transMat = IdentityMatrix(4, 4);

    /* Build the transformation matrix */
    transMat(0, 3) = x;
    transMat(1, 3) = y;
    transMat(2, 3) = z;

    return transMat;
}

Matrix Scaling(float x, float y, float z)
{
    Matrix scaleMat = IdentityMatrix(4, 4);

    /* Build the transformation matrix */
    scaleMat(0, 0) = x;
    scaleMat(1, 1) = y;
    scaleMat(2, 2) = z;

    return scaleMat;
}

Matrix RotationX(float rad)
{
    Matrix rotMat = IdentityMatrix(4, 4);

    rotMat(1, 1) = cosf(rad);
    rotMat(1, 2) = -sinf(rad);
    rotMat(2, 1) = sinf(rad);
    rotMat(2, 2) = cosf(rad);

    return rotMat;
}

Matrix RotationY(float rad)
{
    Matrix rotMat = IdentityMatrix(4, 4);

    rotMat(0, 0) = cosf(rad);
    rotMat(0, 2) = sinf(rad);
    rotMat(2, 0) = -sinf(rad);
    rotMat(2, 2) = cosf(rad);

    return rotMat;
}

Matrix RotationZ(float rad)
{
    Matrix rotMat = IdentityMatrix(4, 4);

    rotMat(0, 0) = cosf(rad);
    rotMat(0, 1) = -sinf(rad);
    rotMat(1, 0) = sinf(rad);
    rotMat(1, 1) = cosf(rad);

    return rotMat;
}

Matrix Shearing(float x_y, float x_z, float y_x, float y_z,
        float z_x, float z_y)
{
    Matrix shearMat = IdentityMatrix(4, 4);

    shearMat(0, 1) = x_y;
    shearMat(0, 2) = x_z;
    shearMat(1, 0) = y_x;
    shearMat(2, 0) = z_x;
    shearMat(1, 2) = y_z;
    shearMat(2, 1) = z_y;

    return shearMat;
}

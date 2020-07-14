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

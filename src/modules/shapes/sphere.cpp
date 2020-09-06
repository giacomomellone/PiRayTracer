/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include "../../../include/shapes/sphere.h"
#include "../../../include/intersection.h"

/*******************************************************************************
 *    CONSTRUCTOR, DESTRUCTOR
 ******************************************************************************/

Sphere::Sphere()
{
    this->originP = Point(0, 0, 0);
    this->radius = 1;
    this->material = Material();
}

Sphere::Sphere(Material material)
{
    this->originP = Point(0, 0, 0);
    this->radius = 1;
    this->material = material;
}

/*******************************************************************************
 *    PUBLIC METHODS
 ******************************************************************************/
Tuple Sphere::Normal(Tuple worldPoint)
{
    Tuple objPoint = this->transfM.Inverse() * worldPoint;
    Tuple objNormal = objPoint - Point(0, 0, 0);
    Tuple worldNormal = (this->transfM.Inverse()).Transpose() * objNormal;

    /* if your transform includes any kind of translation,
     * then multiplying by its transpose will wind up mucking
     * with the w coordinate in your vector */
    worldNormal.w = 0;

    return worldNormal.Normalize();
};

vector<Intersection> Sphere::Intersect(Ray const &r)
{
    vector<Intersection> intV(2);

    /* Apply the inverse of the sphere transformation
     * to the ray itself
     */
    Ray rT = r;
    rT = rT.Transform(this->transfM.Inverse());

    /* Calculate the discriminant to know whether the ray
     * intersect the sphere */
    Tuple sphereToRay = rT.originP - this->originP;

    float a = rT.directionV.Dot(rT.directionV);
    float b = 2 * rT.directionV.Dot(sphereToRay);
    float c = sphereToRay.Dot(sphereToRay) - 1;

    float discriminant = powf(b, 2) - 4 * a * c;

    if (discriminant < 0)
    {
        intV.clear();
    }
    else
    {
        intV[0].s = this;
        intV[0].t = (-b - sqrtf(discriminant)) / (2 * a);

        intV[1].s = this;
        intV[1].t = (-b + sqrtf(discriminant)) / (2 * a);

        if (intV[0].t > intV[1].t)
        {
            sort(intV.begin(), intV.end(),
                    [](Intersection & i1, Intersection & i2){return i1.t < i2.t;});
        }
    }

    return intV;
}

/*******************************************************************************
 *    CLASS SUPPORT FUNCTIONS
 ******************************************************************************/



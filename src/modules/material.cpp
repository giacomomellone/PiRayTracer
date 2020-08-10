/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include "material.h"

/*******************************************************************************
 *    CONSTRUCTOR, DESTRUCTOR
 ******************************************************************************/

Material::Material()
{
    this->color = Color(1, 1, 1);
    this->ambient = 0.1;
    this->diffuse = 0.9;
    this->specular = 0.9;
    this->shininess = 200;
}

Material::Material(Color co, float ambient, float diffuse,
        float specular, float shininess)
{
    this->color = co;
    this->ambient = ambient;
    this->diffuse = diffuse;
    this->specular = specular;
    this->shininess = shininess;
}

/*******************************************************************************
 *    PUBLIC METHODS
 ******************************************************************************/

bool operator == (const Material &m1, const Material &m2)
{
    return (m1.color == m2.color &&
            m1.ambient == m2.ambient &&
            m1.diffuse == m2.diffuse &&
            m1.specular == m2.specular &&
            m1.shininess == m2.shininess);
}

/*******************************************************************************
 *    CLASS SUPPORT FUNCTIONS
 ******************************************************************************/
Color Lighting(Material material, Light lightP, Tuple position, Tuple eyeV, Tuple normalV)
{
    /* Results Colors */
    Color Ambient, Diffuse, Specular;
    /* Combine the surface color with the light's color intensity */
    Color effectiveColor = material.color * lightP.intensity;

    /* Find the direction to the light source */
    Tuple lightV = (lightP.position - position).Normalize();

    /* Compute the ambient contribution */
    Ambient = effectiveColor * material.ambient;

    /* Cosine of the angle between light vector and normal vector */
    float lightDotNormal = lightV.Dot(normalV);

    if (lightDotNormal < 0)
    {
        /* Light is on the other side of the surface */
        Diffuse = Color(0, 0, 0);
        Specular = Color(0, 0, 0);
    }
    else
    {
        Diffuse = effectiveColor * (material.diffuse * lightDotNormal);
    }

    Tuple reflectV = (-lightV).Reflect(normalV);

    /* Cosine of the angle between reflection vector and eye vector */
    float reflectDotEye = reflectV.Dot(eyeV);

    if (reflectDotEye <= 0)
    {
        /* Light reflects away from the eye */
        Specular = Color(0, 0, 0);
    }
    else
    {
        float factor = powf(reflectDotEye, material.shininess);
        Specular = lightP.intensity * (material.specular * factor);
    }

    Color retC = Ambient + Diffuse;
    retC = retC + Specular;

    return retC;
}

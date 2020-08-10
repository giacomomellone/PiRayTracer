/*******************************************************************************
 *    MATERIAL header
 ******************************************************************************/

#ifndef INCLUDE_MATERIAL_H_
#define INCLUDE_MATERIAL_H_

/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include "tuple.h"
#include "color.h"
#include "light.h"
#include "support/utils.h"

/*******************************************************************************
 *    PUBLIC TYPES
 ******************************************************************************/

/**
 * Material object
 *
 */
class Material
{
    public:
        Color color;
        float ambient, diffuse, specular, shininess;

        /********** CTOR / DTOR ***********/
        Material();
        Material(Color co, float ambient, float diffuse,
                float specular, float shininess);

        /********** PUBLIC METHOD PROTOTYPES ***********/
        friend bool operator == (const Material &m1, const Material &m2);
};

/*******************************************************************************
 *    CLASS SUPPORT FUNCTIONS PROTOTYPES
 ******************************************************************************/
Color Lighting(Material material, Light lightP, Tuple position, Tuple eyeV, Tuple normalV);

#endif /* INCLUDE_MATERIAL_H_ */

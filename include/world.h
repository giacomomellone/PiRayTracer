/*
 * world.h
 *
 *  Created on: 24 ago 2020
 *      Author: deddi
 */

/*******************************************************************************
 *    World header
 ******************************************************************************/

#ifndef INCLUDE_WORLD_H_
#define INCLUDE_WORLD_H_


/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include "light.h"
#include "shapes/sphere.h"
#include "intersection.h"
#include "ray.h"

/*******************************************************************************
 *    PUBLIC TYPES
 ******************************************************************************/
class Intersection;

/**
 * World object
 *
 */
class World
{
    public:
        Light lightP;
        Sphere s1, s2;

        /********** CTOR / DTOR ***********/
        World(){};

        /********** PUBLIC METHOD PROTOTYPES ***********/
        Color ShadeHit(struct computation const comps);
        vector<Intersection> Intersect(Ray const &r);
        Color ColorAt(Ray const &r);
};

/*******************************************************************************
 *    CLASS SUPPORT FUNCTIONS PROTOTYPES
 ******************************************************************************/
World DefaultWorld(void);

#endif /* INCLUDE_WORLD_H_ */

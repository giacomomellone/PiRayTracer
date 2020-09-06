/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include "world.h"
#include "intersection.h"

/*******************************************************************************
 *    CONSTRUCTOR, DESTRUCTOR
 ******************************************************************************/

World DefaultWorld(void)
{
    World w;
    /* Define the deafult world with the following features */
    w.lightP = Light(Point(-10, 10, -10), Color(1, 1, 1));

    w.s1 = Sphere();
    w.s1.material.color = Color(0.8, 1.0, 0.6);
    w.s1.material.diffuse = 0.7;
    w.s1.material.specular = 0.2;

    w.s2 = Sphere();
    w.s2.SetTranformation(Scaling(0.5, 0.5, 0.5));

    return w;
}

/*******************************************************************************
 *    PUBLIC METHODS
 ******************************************************************************/
Color World::ShadeHit(struct computation const comps)
{
    return(Lighting(comps.object->material, this->lightP,
            comps.point, comps.eyeV, comps.normalV));
}

vector<Intersection> World::Intersect(Ray const &r)
{
    vector<Intersection> intS1 = this->s1.Intersect(r);
    vector<Intersection> intS2 = this->s2.Intersect(r);

    vector<Intersection> intAll(intS1.size() + intS2.size());

    /* Append S2 intersections to S1 */
    intS1.insert(intS1.end(), intS2.begin(), intS2.end());
    intAll = intS1;

    /* Sort the intersections */
    sort(intAll.begin(), intAll.end(),
            [](Intersection & i1, Intersection & i2){return i1.t < i2.t;});

    return intAll;
}

Color World::ColorAt(Ray const &r)
{
    Color colorAt(0, 0, 0);

    /* 1) Call IntersectWorld to find the intersections of
     * the given ray with the given world. */
    vector<Intersection> xs = this->Intersect(r);

    /* 2) Find the hit from the resulting intersections. */
    Intersection hit = Hit(xs);

    /* 3) Return the color black if there is no such intersection. */
    if (hit.s == nullptr)
    {
        return Color(0, 0, 0);
    }

    /* 4) Precompute the necessary values with prepareComputation. */
    comps_s comps = prepareComputation(hit, r);

    /* 5) Call shadeHit to find the color at the hit. */
    return this->ShadeHit(comps);
}

/*******************************************************************************
 *    CLASS SUPPORT FUNCTIONS
 ******************************************************************************/


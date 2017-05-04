//
// Created by keltar on 5/4/17.
//

#ifndef CG_LIGHT_H
#define CG_LIGHT_H

#include "Vector.h"

class Light
{
public:
    Light();
    ~Light();

    Vec3f Color();
    Vec3f AmbientIntensity();

private:
    Vec3f color;
    Vec3f ambientIntensity;
};


#endif //CG_LIGHT_H

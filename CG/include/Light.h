//
// Created by keltar on 5/4/17.
//

#ifndef CG_LIGHT_H
#define CG_LIGHT_H

#include <GL/glew.h>
#include "Vector.h"

class Light
{
public:
    Light();
    ~Light();

    Vec3f &Color();
    GLfloat &AmbientIntensity();

protected:
    Vec3f color;
    GLfloat ambientIntensity;
};

class DirectionalLight: public Light
{
public:
    DirectionalLight();
    DirectionalLight(Vec3f color, GLfloat ambientIntensity);
    DirectionalLight(Vec3f color, GLfloat ambientIntensity, Vec3f direction, GLfloat diffuseIntensity);

    Vec3f &Direction();
    GLfloat &DiffuseIntensity();

    ~DirectionalLight();

private:
    Vec3f direction;
    GLfloat diffuseIntensity;
};

#endif //CG_LIGHT_H

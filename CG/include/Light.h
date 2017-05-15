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
    GLfloat &DiffuseIntensity();
protected:
    Vec3f color;
    GLfloat ambientIntensity;
    GLfloat diffuseIntensity;
};

class DirectionalLight: public Light
{
public:
    DirectionalLight();
    DirectionalLight(Vec3f color, GLfloat ambientIntensity);
    DirectionalLight(Vec3f color, GLfloat ambientIntensity, Vec3f direction, GLfloat diffuseIntensity);

    Vec3f &Direction();


    ~DirectionalLight();

private:
    Vec3f direction;

};

class PointLight: public Light
{
public:
    PointLight(const Vec3f &color, const Vec3f &pos, GLfloat ambientIntensity, GLfloat diffuseIntensity, GLfloat constant, GLfloat linear, GLfloat exp);
    PointLight();

    GLfloat &Constant();
    GLfloat &Linear();
    GLfloat &Exp();

    Vec3f &Pos();
protected:
    Vec3f pos;
    GLfloat constant, linear, exp;
};

class SpotLight: public PointLight
{
public:
    SpotLight();
    SpotLight(const Vec3f &color, const Vec3f &pos, const Vec3f &direction, GLfloat cutoof,GLfloat ambientIntensity, GLfloat diffuseIntensity, GLfloat constant, GLfloat linear, GLfloat exp);

    Vec3f &Direction();
    GLfloat &Cutoff();
private:
    Vec3f direction;
    GLfloat cutoff;
};




#endif //CG_LIGHT_H

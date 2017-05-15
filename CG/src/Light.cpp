//
// Created by keltar on 5/4/17.
//

#include "../include/Light.h"

Light::Light()
{

}

Light::~Light()
{

}

Vec3f &Light::Color()
{
    return color;
}

GLfloat &Light::AmbientIntensity()
{
    return ambientIntensity;
}

GLfloat &Light::DiffuseIntensity()
{
    return diffuseIntensity;
}

DirectionalLight::DirectionalLight()
{

}

DirectionalLight::DirectionalLight(Vec3f color, GLfloat ambientIntensity)
{
    this->color            = color;
    this->ambientIntensity = ambientIntensity;
}

DirectionalLight::~DirectionalLight() {}

Vec3f &DirectionalLight::Direction()
{
    return direction;
}

DirectionalLight::DirectionalLight(Vec3f color, GLfloat ambientIntensity, Vec3f direction, GLfloat diffuseIntensity)
{
    this->color            = color;
    this->ambientIntensity = ambientIntensity;
    this->direction        = direction;
    this->diffuseIntensity = diffuseIntensity;
}

PointLight::PointLight(const Vec3f &color, const Vec3f &pos, GLfloat ambientIntensity, GLfloat diffuseIntensity,
                       GLfloat constant, GLfloat linear, GLfloat exp)
{
    this->color            = color;
    this->pos              = pos;
    this->ambientIntensity = ambientIntensity;
    this->diffuseIntensity = diffuseIntensity;
    this->constant         = constant;
    this->linear           = linear;
    this->exp              = exp;
}

GLfloat &PointLight::Constant()
{
    return constant;
}

GLfloat &PointLight::Linear()
{
    return linear;
}

GLfloat &PointLight::Exp()
{
    return exp;
}

Vec3f &PointLight::Pos()
{
    return pos;
}

PointLight::PointLight()
{

}

SpotLight::SpotLight()
{

}

SpotLight::SpotLight(const Vec3f &color, const Vec3f &pos, const Vec3f &direction, GLfloat cutoof,
                     GLfloat ambientIntensity, GLfloat diffuseIntensity, GLfloat constant, GLfloat linear, GLfloat exp)
{
    this->color = color;
    this->pos = pos;
    this->direction = direction;
    this->cutoff = cutoof;
    this->ambientIntensity = ambientIntensity;
    this->diffuseIntensity = diffuseIntensity;
    this->constant = constant;
    this->linear = linear;
    this->exp = exp;
}

Vec3f &SpotLight::Direction()
{
    return direction;
}

GLfloat &SpotLight::Cutoff()
{
    return cutoff;
}

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

GLfloat &DirectionalLight::DiffuseIntensity()
{
    return diffuseIntensity;
}

DirectionalLight::DirectionalLight(Vec3f color, GLfloat ambientIntensity, Vec3f direction, GLfloat diffuseIntensity)
{
    this->color            = color;
    this->ambientIntensity = ambientIntensity;
    this->direction        = direction;
    this->diffuseIntensity = diffuseIntensity;
}

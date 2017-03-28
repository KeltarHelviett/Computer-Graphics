//
// Created by keltar on 3/23/17.
//

#include "Vector4.h"

Vector4::Vector4()
{

}

float &Vector4::operator[](unsigned int index)
{
    return _vec[index];
}

float Vector4::Dot(Vector4 &other)
{
    return _vec[0] * other[0] + _vec[1] * other[1] + _vec[2] * other[2];
}

Vector4 Vector4::Cross(Vector4 &other)
{
    return Vector4(
        _vec[1] * other[2] - _vec[2] * other[1],
        _vec[0] * other[2] - _vec[2] * other[0],
        _vec[0] * other[1] - _vec[1] * other[0],
        _vec[3]
    );
}

Vector4::Vector4(float x, float y, float z, float w)
{
    _vec[0] = x;
    _vec[1] = y;
    _vec[2] = z;
    _vec[4] = w;
}

float *Vector4::vector()
{
    return &_vec[0];
}

float Vector4::Length()
{
    return (float)sqrt(_vec[0] * _vec[0] + _vec[1] * _vec[1] + _vec[2] * _vec[2]);
}

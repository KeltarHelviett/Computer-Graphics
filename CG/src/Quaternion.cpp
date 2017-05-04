//
// Created by keltar on 3/28/17.
//

#include <iostream>
#include "../include/Quaternion.h"

Quaternion::Quaternion()
{
}

Quaternion::Quaternion(float x, float y, float z, float w): Quaternion(Vec3f({x, y, z}), w)
{
}

Quaternion::Quaternion(Vec3f v, float w)
{
    Vec3f nv = v;
    nv.Normalize();
    _vec = Vec4f({nv[0], nv[1], nv[2], w});
    float sinhalfangle = sinf(w / 2.0f);
    for (int i = 0; i < 3; ++i)
        _vec[i] = _vec[i] * sinhalfangle;
    _vec[3] = cosf(w / 2.0f);
}

Quaternion Quaternion::Conjugate()
{
    Quaternion q;
    q._vec[0] = -_vec[0];
    q._vec[1] = -_vec[1];
    q._vec[2] = -_vec[2];
    q._vec[3] = _vec[3];
    return q;
}

Quaternion &Quaternion::Normalize()
{
    _vec.Normalize();
    return *this;
}

Quaternion &Quaternion::Inverse()
{
    return this->Conjugate().Normalize();
}


float Quaternion::Length()
{
    return _vec.Length();
}

Quaternion Quaternion::Mult(const Vec3f &other)
{
    Quaternion q;
    for (int i = 0; i < 3; ++i)
        q[i] = other._vec[i];
    q[3] = 0;
    return this->Mult(q);
}

Quaternion Quaternion::Mult(const Quaternion &other)
{
    Quaternion res;
    res._vec[3] = _vec._vec[3] * other._vec._vec[3] - _vec._vec[0] * other._vec._vec[0] - _vec._vec[1] * other._vec._vec[1] - _vec._vec[2] * other._vec._vec[2];
    res._vec[0] = _vec._vec[3] * other._vec._vec[0] + _vec._vec[0] * other._vec._vec[3] + _vec._vec[1] * other._vec._vec[2] - _vec._vec[2] * other._vec._vec[1];
    res._vec[1] = _vec._vec[3] * other._vec._vec[1] - _vec._vec[0] * other._vec._vec[2] + _vec._vec[1] * other._vec._vec[3] + _vec._vec[2] * other._vec._vec[0];
    res._vec[2] = _vec._vec[3] * other._vec._vec[2] + _vec._vec[0] * other._vec._vec[1] - _vec._vec[1] * other._vec._vec[0] + _vec._vec[2] * other._vec._vec[3];

    return res;
}

Quaternion Quaternion::operator*(const Vec3f &other)
{
    return this->Mult(other);
}

Quaternion Quaternion::operator*(const Quaternion &other)
{
    return this->Mult(other);
}

Vec3f Quaternion::Rotate(Vec3f &other)
{
    auto tmp = (*this * other * this->Conjugate())._vec;
    return {tmp._vec[0], tmp._vec[1], tmp._vec[2]};
}

float &Quaternion::operator[](unsigned int index)
{
    return _vec[index];
}




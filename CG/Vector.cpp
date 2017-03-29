//
// Created by keltar on 3/23/17.
//

#include "Vector.h"

/// Vector 4

Vector4::Vector4()
{
}

Vector4::Vector4(float x, float y, float z, float w)
{
    _vec[0] = x;
    _vec[1] = y;
    _vec[2] = z;
    _vec[4] = w;
}

Vector4::Vector4(Vector3 &other)
{
    _vec[0] = other[0];
    _vec[1] = other[1];
    _vec[2] = other[2];
    _vec[3] = 0;
}

float Vector4::Dot(Vector4 &other)
{
    return _vec[0] * other[0] + _vec[1] * other[1] + _vec[2] * other[2] + _vec[3] * _vec[3];
}

float Vector4::operator*(Vector4 &other)
{
    return this->Dot(other);
}

float Vector4::Length()
{
    return sqrtf(this->Dot(*this));
}

Vector4 &Vector4::Normalize()
{
    float l = this->Length();
    for (int i = 0; i < 4; ++i)
        _vec[i] /= l;
    return *this;
}

float &Vector4::operator[](unsigned int index)
{
    return _vec[index];
}

/// Vector3

Vector3::Vector3()
{
}

Vector3::Vector3(float x, float y, float z)
{
    _vec[0] = x;
    _vec[1] = y;
    _vec[2] = z;
}

Vector3::Vector3(Vector4 &other)
{
    _vec[0] = other[0];
    _vec[1] = other[1];
    _vec[2] = other[2];
}

float Vector3::Dot(Vector3 &other)
{
    return _vec[0] * other[0] + _vec[1] * other[1] + _vec[2] * other[2];
}

float Vector3::operator*(Vector3 &other)
{
    return this->Dot(other);
}

Vector3 Vector3::Cross(Vector3 &other)
{
    return Vector3
    (
        _vec[1] * other[2] - _vec[2] * other[1],
        _vec[0] * other[2] - _vec[2] * other[0],
        _vec[0] * other[1] - _vec[1] * other[0]
    );
}

Vector3 Vector3::operator%(Vector3 &other)
{
    return this->Cross(other);
}

float Vector3::Length()
{
    return sqrtf(this->Dot(*this));
}

Vector3 &Vector3::Normalize()
{
    float l = this->Length();
    for (int i = 0; i < 3; ++i)
        _vec[i] /= l;
    return *this;
}


float& Vector3::operator[](unsigned int index)
{
    return _vec[index];
}


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

Vector4::Vector4(const Vector3 &other, float w)
{
    _vec[0] = other._vec[0];
    _vec[1] = other._vec[1];
    _vec[2] = other._vec[2];
    _vec[3] = w;
}

float Vector4::Dot(const Vector4 &other)
{
    return _vec[0] * other._vec[0] + _vec[1] * other._vec[1] + _vec[2] * other._vec[2] + _vec[3] * other._vec[3];
}

float Vector4::operator*(const Vector4 &other)
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

Vector4 Vector4::operator-()
{
    return Vector4(-_vec[0], -_vec[1], -_vec[2], -_vec[3]);
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

Vector3::Vector3(const Vector4 &other)
{
    _vec[0] = other._vec[0];
    _vec[1] = other._vec[1];
    _vec[2] = other._vec[2];
}

Vector3::Vector3(const Vector3 &other)
{
    for (int i = 0; i < 3; ++i)
        _vec[i] = other._vec[i];
}


float Vector3::Dot(const Vector3 &other)
{
    return _vec[0] * other._vec[0] + _vec[1] * other._vec[1] + _vec[2] * other._vec[2];
}

float Vector3::operator*(const Vector3 &other)
{
    return this->Dot(other);
}

Vector3 Vector3::operator*(const float scale)
{
    return Vector3(_vec[0] * scale, _vec[1] * scale, _vec[2] * scale);
}

Vector3 &Vector3::operator*=(const float scale)
{
    for (int i = 0; i < 3; ++i)
        _vec[i] *= scale;
    return *this;
}

Vector3 Vector3::Cross(const Vector3 &other)
{
    return Vector3
    (
        _vec[1] * other._vec[2] - _vec[2] * other._vec[1],
        _vec[2] * other._vec[0] - _vec[0] * other._vec[2],
        _vec[0] * other._vec[1] - _vec[1] * other._vec[0]
    );
}

Vector3 Vector3::operator%(const Vector3 &other)
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

Vector3 Vector3::Add(const Vector3 &other)
{
    return Vector3(_vec[0] + other._vec[0], _vec[1] + other._vec[1], _vec[2] + other._vec[2]);
}

Vector3 Vector3::operator+(const Vector3 &other)
{
    return this->Add(other);
}

Vector3 &Vector3::operator+=(const Vector3 &other)
{
    *this = this->Add(other);
    return *this;
}

Vector3 Vector3::Sub(const Vector3 &other)
{
    return Vector3(_vec[0] - other._vec[0], _vec[1] - other._vec[1], _vec[2] - other._vec[2]);
}

Vector3 Vector3::operator-(const Vector3 &other)
{
    return this->Sub(other);
}

Vector3 &Vector3::operator-=(const Vector3 &other)
{
    *this = this->Sub(other);
    return *this;
}

Vector3 Vector3::operator-()
{
    return Vector3(-_vec[0], -_vec[1], -_vec[2]);
}






#ifndef CG_VECTOR_H
#define CG_VECTOR_H

#include <cmath>
class Vector3;
class Vector4;

class Vector4
{
public:
    friend class Vector3;
    friend class Quaternion;
    Vector4();
    Vector4(float x, float y, float z, float w = 0);
    Vector4(const Vector3 &other, float w);

    float Dot(const Vector4 &other);
    float operator*(const Vector4 &other);

    float Length();

    Vector4 &Normalize();

    Vector4 operator-();
    float &operator[](unsigned int index);
private:
    float _vec[4];
};

class Vector3
{
public:
    friend class Vector4;
    friend class Quaternion;
    Vector3();
    Vector3(float x, float y, float z);
    Vector3(const Vector4 &other);
    Vector3(const Vector3 &other);

    float Dot(const Vector3 &other);
    float operator*(const Vector3 &other);
    Vector3 operator*(const float scale);
    Vector3 &operator*=(const float scale);

    Vector3 Cross(const Vector3 &other);
    Vector3 operator%(const Vector3 &other);

    Vector3 Add(const Vector3 &other);
    Vector3 operator+(const Vector3 &other);
    Vector3 &operator+=(const Vector3 &other);

    Vector3 Sub(const Vector3 &other);
    Vector3 operator-(const Vector3 &other);
    Vector3 &operator-=(const Vector3 &other);

    Vector3 operator-();

    float Length();

    Vector3 &Normalize();

    float &operator[](unsigned int index);
private:
    float _vec[3];

};

#endif //CG_VECTOR_H

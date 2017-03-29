#ifndef CG_VECTOR_H
#define CG_VECTOR_H

#include <cmath>
class Vector3;
class Vector4;

class Vector4
{
public:
    Vector4();
    Vector4(float x, float y, float z, float w = 0);
    Vector4(Vector3 &other);

    float Dot(Vector4 &other);
    float operator*(Vector4 &other);

    float Length();

    Vector4 &Normalize();

    float &operator[](unsigned int index);
private:
    float _vec[4];
};

class Vector3
{
public:
    Vector3();
    Vector3(float x, float y, float z);
    Vector3(Vector4 &other);

    float Dot(Vector3 &other);
    float operator*(Vector3 &other);

    Vector3 Cross(Vector3 &other);
    Vector3 operator%(Vector3 &other);

    float Length();

    Vector3 &Normalize();

    float &operator[](unsigned int index);
private:
    float _vec[3];

};

#endif //CG_VECTOR_H

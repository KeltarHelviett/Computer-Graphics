#ifndef CG_MATRIX4_H
#define CG_MATRIX4_H

#include <initializer_list>
#include "Vector.h"

class Matrix4
{
public:
    Matrix4();
    Matrix4(std::initializer_list<std::initializer_list<float>> mat);

    Matrix4 Mult(const Matrix4 &other);
    Matrix4 operator*(const Matrix4 &other);
    Matrix4 Add(const Matrix4 &other);
    Matrix4 operator+(const Matrix4 &other);

    Vector4 Mult(Vector4 &other);
    Vector4 operator*(Vector4 &other);

    float* operator[](unsigned int index);

private:
    float _mat[4][4];
};


#endif

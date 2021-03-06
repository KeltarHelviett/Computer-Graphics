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

    Vec4f  Mult(Vec4f &other);
    Vec4f  operator*(Vec4f &other);

    GLfloat * operator[](unsigned int index);

    bool operator==(const Matrix4 &other);

private:
    float _mat[4][4];
};


#endif

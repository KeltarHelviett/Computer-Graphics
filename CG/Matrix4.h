#ifndef CG_MATRIX4_H
#define CG_MATRIX4_H

#include "Vector4.h"

class Matrix4
{
public:
    Matrix4();


    Matrix4 Mult(Matrix4 &other);
//    Vector4 Mult(Vector4 &other);
    Matrix4 Add(Matrix4 &other);

    Matrix4 operator*(Matrix4 &other);
    float* operator[](unsigned int index);
    float* matrix();
private:
    float _mat[4][4];
};


#endif
//
// Created by keltar on 3/23/17.
//

#ifndef CG_VECTOR4_H
#define CG_VECTOR4_H

#include <cmath>

class Vector4
{
public:
    Vector4();
    Vector4(float x, float y, float z, float w = 0);

    float Dot(Vector4 &other);
    Vector4 Cross(Vector4 &other);
    float Length();
    float *vector();

    float &operator[](unsigned int index);
private:
    float _vec[4];
};


#endif //CG_VECTOR4_H

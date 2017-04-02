//
// Created by keltar on 3/28/17.
//

#ifndef CG_QUATERNION_H
#define CG_QUATERNION_H

#include "Vector.h"

class Quaternion
{
public:
    Quaternion();
    Quaternion(const Vector3 &v, float w);
    Quaternion(float x, float y, float z, float w);

    Quaternion Conjugate();
    Quaternion &Normalize();
    Quaternion &Inverse();

    Quaternion Mult(const Vector3 &other);
    Quaternion Mult(const Quaternion &other);
    Quaternion operator*(const Vector3 &other);
    Quaternion operator*(const Quaternion &other);

    Vector3 Rotate(Vector3 &other);

    float &operator[](unsigned int index);
    float Length();
private:
    Vector4 _vec;
};


#endif //CG_QUATERNION_H

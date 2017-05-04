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
    Quaternion(Vec3f v, float w);
    Quaternion(float x, float y, float z, float w);

    Quaternion Conjugate();
    Quaternion &Normalize();
    Quaternion &Inverse();

    Quaternion Mult(const Vec3f &other);
    Quaternion Mult(const Quaternion &other);
    Quaternion operator*(const Vec3f &other);
    Quaternion operator*(const Quaternion &other);

    Vec3f Rotate(Vec3f &other);

    float &operator[](unsigned int index);
    float Length();
private:
    Vec4f _vec;
};


#endif //CG_QUATERNION_H

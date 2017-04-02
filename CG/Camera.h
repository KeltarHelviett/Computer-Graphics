//
// Created by keltar on 3/29/17.
//

#ifndef CG_CAMERA_H
#define CG_CAMERA_H


#include "Vector.h"
#include "Matrix4.h"
#include "Point.h"

class Camera
{
public:
    Camera();

    Matrix4 SetPosition(float x, float y, float z);
    Matrix4 GetUVNMatrix();

    void Rotate(Point &newAngles);
    Vector3 Position();
    Vector3 Target();
    Point Angles();
private:
    Vector3 up, target, pos;
    Point angles;
};

#endif //CG_CAMERA_H

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
    Camera(float FOV, float z1, float z2);

    Matrix4 SetPosition(float x, float y, float z);
    Matrix4 GetUVNMatrix();
    Matrix4 GetProjectionPerspectiveMatrix();

    void Rotate(Point &newAngles);
    Vec3f Position();
    Vec3f Target();
    Vec3f Up();
    Point Angles();
private:
    Vec3f up, target, pos;
    float fov, z1, z2;
    Point angles;
};

#endif //CG_CAMERA_H

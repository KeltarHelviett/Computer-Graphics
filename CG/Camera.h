//
// Created by keltar on 3/29/17.
//

#ifndef CG_CAMERA_H
#define CG_CAMERA_H


#include "Vector.h"
#include "Matrix4.h"

class Camera
{
public:
    Camera();

    Matrix4 SetPosition(float x, float y, float z);
    Matrix4 GetUVNMatrix();
private:
    Vector3 up, target, pos;
};

#endif //CG_CAMERA_H

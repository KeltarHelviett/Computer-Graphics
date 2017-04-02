//
// Created by keltar on 3/29/17.
//

#include "Camera.h"
#include "Quaternion.h"

#define ToRadian(x) (float)((x) * M_PI / 180.0f)
#define ToDegree(x) (float)((x) * 180.0f / M_PI)

Camera::Camera()
{
    pos    = Vector3(1.0f, 1.0f, -3.0f);
    target = Vector3(0.0f, 0.0f, 1.0f);
    up     = Vector3(0.0f, 1.0f, 0.0f);

    Vector3 hTarget(target[0], 0.0f, target[2]);
    hTarget.Normalize();
    if (hTarget[2] >= 0.0f){
        if (hTarget[0] >= 0.0f){
            angles.x = 360.0f - ToDegree(asin(hTarget[2]));
        }
        else{
            angles.x = 180.0f + ToDegree(asin(hTarget[2]));
        }
    }
    else{
        if (hTarget[0] >= 0.0f){
            angles.x = ToDegree(asin(-hTarget[2]));
        }
        else{
            angles.x = 90.0f + ToDegree(asin(-hTarget[2]));
        }
    }

    angles.y = -ToDegree(asin(target[1]));
}

Matrix4 Camera::SetPosition(float x, float y, float z)
{
    pos[0] = x; pos[1] = y; pos[2] = z;
    return
    {
            {1, 0, 0, -x},
            {0, 1, 0, -y},
            {0, 0, 1, -z},
            {0, 0, 0, 1}
    };
}

Matrix4 Camera::GetUVNMatrix()
{
    Vector3 N = target.Normalize();
    Vector3 U = up.Normalize();
    U = U % target;
    Vector3 V = N % U;
    U.Normalize();
    V.Normalize();
    return
    {

            {U[0], U[1], U[2], 0.0f},
            {V[0], V[1], V[2], 0.0f},
            {N[0], N[1], N[2], 0.0f},
            {0.0f, 0.0f, 0.0f, 1.0f}
    };

}

Vector3 Camera::Position()
{
    return pos;
}

void Camera::Rotate(Point &newAngles)
{
    if (newAngles.x == 0 && newAngles.y == 0)
        return;
    angles.x += newAngles.x / 20.0f;
    angles.y += newAngles.y / 20.0f;
    Vector3 Vaxis(0.0f, 1.0f, 0.0f);
    Vector3 View(1.0f, 0.0f, 0.0f);
    Quaternion hor(Vaxis, ToRadian(angles.x));
    View = hor.Rotate(View);
    View.Normalize();

    // Rotate the view vector by the vertical angle around the horizontal axis
    Vector3 Haxis = View.Cross(Vaxis);
    Haxis.Normalize();

    Quaternion ver(Haxis, ToRadian(angles.y));
    View = ver.Rotate(View);
    View.Normalize();

    target = View;
    target.Normalize();

    up = Haxis % target;
    up.Normalize();
}

Point Camera::Angles()
{
    return angles;
}

Vector3 Camera::Target()
{
    return target;
}

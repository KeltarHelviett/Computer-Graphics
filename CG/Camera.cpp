//
// Created by keltar on 3/29/17.
//

#include "Camera.h"

Camera::Camera()
{
    pos    = Vector3(0.0f, 0.0f, 0.0f);
    target = Vector3(0.0f, 0.0f, 1.0f);
    up     = Vector3(0.0f, 1.0f, 0.0f);
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

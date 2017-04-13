//
// Created by keltar on 3/29/17.
//

#include <GL/glut.h>
#include "Camera.h"
#include "Quaternion.h"

#define ToRadian(x) (float)((x) * M_PI / 180.0f)
#define ToDegree(x) (float)((x) * 180.0f / M_PI)

Camera::Camera(): Camera(60, 1, 100) {}

Camera::Camera(float FOV, float z1, float z2)
{
    fov = FOV;
    this->z1 = z1;
    this->z2 = z2;
    pos    = {1.0f, 1.0f, -3.0f};
    target = {0.0f, 0.0f, 1.0f};
    up     = {0.0f, 1.0f, 0.0f};

    Vec3f hTarget = {target[0], 0.0f, target[2]};
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
    Vec3f N = target.Normalize();
    Vec3f U = up.Normalize();
    U = U % target;
    Vec3f V = N % U;
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

Vec3f Camera::Position()
{
    return pos;
}

void Camera::Rotate(Point &newAngles)
{
    if (newAngles.x == 0 && newAngles.y == 0)
        return;
    angles.x += newAngles.x / 10.0f;
    angles.y += newAngles.y / 10.0f;
    Vec3f Vaxis = {0.0f, 1.0f, 0.0f};
    Vec3f View = {1.0f, 0.0f, 0.0f};
    Quaternion hor(Vaxis, ToRadian(angles.x));
    View = hor.Rotate(View);
    View.Normalize();

    // Rotate the view vector by the vertical angle around the horizontal axis
    Vec3f Haxis = View.Cross(Vaxis);
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

Vec3f Camera::Target()
{
    return target;
}

Vec3f Camera::Up()
{
    return up;
}

Matrix4 Camera::GetProjectionPerspectiveMatrix()
{
    Matrix4 m;
    float ar = glutGet(GLUT_WINDOW_WIDTH) / glutGet(GLUT_WINDOW_HEIGHT);
    float zrange = z1 - z2;
    float halftan = tanf(ToRadian(fov) / 2.0f);
    m[0][0] = 1.0f / (halftan * ar);  m[0][1] = 0.0f;            m[0][2] = 0.0f;                   m[0][3] = 0.0;
    m[1][0] = 0.0f;                   m[1][1] = 1.0f / halftan;  m[1][2] = 0.0f;                   m[1][3] = 0.0;
    m[2][0] = 0.0f;                   m[2][1] = 0.0f;            m[2][2] = (-z1 -z2) / zrange ;    m[2][3] = (2.0f * z2 * z1) / zrange;
    m[3][0] = 0.0f;                   m[3][1] = 0.0f;            m[3][2] = 1.0f;                   m[3][3] = 0.0;
    return m;
}

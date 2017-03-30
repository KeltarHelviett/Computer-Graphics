//
// Created by keltar on 3/30/17.
//

#include "CameraEventHandler.h"

CameraEventHandler::CameraEventHandler()
{

}

Vector3 CameraEventHandler::GetCameraSpeed(bool *keys)
{
    Vector3 speed(0.0f, 0.0f, 0.0f);
    if (keys['W'] || keys['w'])
        speed[2] = 0.001f;
    if (keys['A'] || keys['a'])
        speed[0] = -0.001f;
    if (keys['D'] || keys['d'])
        speed[0] = 0.001f;
    if (keys['S'] || keys['s'])
        speed[2] = -0.001f;
    return speed;
}

//
// Created by keltar on 3/30/17.
//

#include <iostream>
#include "../include/CameraEventHandler.h"
#include <GL/glut.h>

CameraEventHandler::CameraEventHandler()
{

}

Vec3f CameraEventHandler::GetCameraPosition(bool *keys, Vec3f target, Vec3f up, Vec3f oldPos)
{
    static float step = 0.0007f;
    if (keys['W'] || keys['w'])
        oldPos += (target * step);
    if (keys['A'] || keys['a'])
    {
        Vec3f l = target % up;
        l.Normalize();
        oldPos += l * step;
    }
    if (keys['D'] || keys['d'])
    {
        Vec3f r = up % target;
        r.Normalize();
        oldPos += r * step;
    }
    if (keys['S'] || keys['s'])
        oldPos -= (target * step);
    return oldPos;
}

Point CameraEventHandler::GetRotationAngles(MouseInfo mi)
{
    Point delta;
//    if (mi.buttons[GLUT_RIGHT_BUTTON] == GLUT_DOWN)
//    {
        delta.x = mi.cur.x - mi.prev.x;
        delta.y = mi.prev.y - mi.cur.y;

//    }
    return delta;
}

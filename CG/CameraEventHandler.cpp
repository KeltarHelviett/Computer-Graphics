//
// Created by keltar on 3/30/17.
//

#include <GL/glut.h>
#include <iostream>
#include "CameraEventHandler.h"


CameraEventHandler::CameraEventHandler()
{

}

Vector3 CameraEventHandler::GetCameraPosition(bool *keys, Vector3 target, Vector3 up, Vector3 oldPos)
{
    static float step = 0.0005f;
    if (keys['W'] || keys['w'])
        oldPos += (target * step);
    if (keys['A'] || keys['a'])
    {
        Vector3 l = target % up;
        l.Normalize();
        oldPos += l * step;
    }
    if (keys['D'] || keys['d'])
    {
        Vector3 r = up % target;
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
        delta.y = mi.cur.y - mi.prev.y;

//    }
    return delta;
}

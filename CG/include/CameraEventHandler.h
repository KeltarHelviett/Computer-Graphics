//
// Created by keltar on 3/30/17.
//

#ifndef CG_CAMERAEVENTHANDLER_H
#define CG_CAMERAEVENTHANDLER_H

#include "Vector.h"
#include "EventHandler.h"
#include "Point.h"
#include "MouseEventArgs.h"
#include "MouseEventHandler.h"
#include "Camera.h"

class CameraEventHandler
{
public:
    CameraEventHandler();

    Vec3f GetCameraPosition(bool *keys, Camera *cam);
    Vec3f GetCameraPosition(bool *keys, Vec3f target, Vec3f up, Vec3f oldPos);
    Point GetRotationAngles(MouseInfo mi);
//    void GetMouseInfo()
private:

};


#endif //CG_CAMERAEVENTHANDLER_H

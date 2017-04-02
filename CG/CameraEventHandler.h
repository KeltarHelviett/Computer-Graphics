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

class CameraEventHandler
{
public:
    CameraEventHandler();

    Vector3 GetCameraSpeed(bool *keys);
    Point GetRotationAngles(MouseInfo mi);
//    void GetMouseInfo()
private:

};


#endif //CG_CAMERAEVENTHANDLER_H

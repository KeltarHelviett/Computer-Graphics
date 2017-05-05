//
// Created by keltar on 3/31/17.
//

#ifndef CG_MOUSEEVENTHANDLER_H
#define CG_MOUSEEVENTHANDLER_H



#include "Vector.h"
#include "MouseEventArgs.h"
#include "Point.h"
#include <GL/glut.h>

struct MouseInfo
{
    int *buttons;
    Point prev, cur;
};

class MouseEventHandler
{
public:
    MouseEventHandler();
    void GetMouseInfo(int button , int state, int x, int y);
    void MouseMove(int x, int y);

    int *Buttons();
    MouseInfo Info();
private:
    int buttons[3];
    Point posPrev, posCur;
};


#endif //CG_MOUSEEVENTHANDLER_H

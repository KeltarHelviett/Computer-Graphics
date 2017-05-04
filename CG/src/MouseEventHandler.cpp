//
// Created by keltar on 3/31/17.
//

#include "../include/MouseEventHandler.h"

MouseEventHandler::MouseEventHandler()
{
    for (int i = 0; i < 3; ++i)
        buttons[i] = GLUT_UP;
}

void MouseEventHandler::GetMouseInfo(int button, int state, int x, int y)
{
    buttons[button] = state;
    posPrev = posCur;
    posCur = Point(x, y);
}

int *MouseEventHandler::Buttons()
{
    return &buttons[0];
}

MouseInfo MouseEventHandler::Info()
{
    MouseInfo mi;
    mi.buttons = this->Buttons();
    mi.cur = posCur;
    mi.prev = posPrev;
    return mi;
}

void MouseEventHandler::MouseMove(int x, int y)
{
    posPrev = posCur;
    posCur = Point(x, y);
}

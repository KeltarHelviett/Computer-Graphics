//
// Created by keltar on 4/1/17.
//

#include "../include/MouseEventArgs.h"


MouseEventArgs::MouseEventArgs()
{

}

MouseEventArgs::MouseEventArgs(int button, int state, int x, int y)
{
    this->button = button;
    this->state = state;
    this->x = x;
    this->y = y;
}

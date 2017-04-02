//
// Created by keltar on 4/1/17.
//

#ifndef CG_MOUSEEVENTARGS_H
#define CG_MOUSEEVENTARGS_H


struct MouseEventArgs
{
    int button, state, x, y;
    MouseEventArgs();
    MouseEventArgs(int button, int state, int x, int y);
};


#endif //CG_MOUSEEVENTARGS_H

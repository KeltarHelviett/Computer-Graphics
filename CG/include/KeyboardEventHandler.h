//
// Created by keltar on 3/30/17.
//

#ifndef CG_KEYBOARDEVENTHANDLER_H
#define CG_KEYBOARDEVENTHANDLER_H

#include "EventHandler.h"
#include "Event.h"

class KeyboardEventHandler: public EventHandler
{
public:
    KeyboardEventHandler();

    void Press(int key, int x, int y);
    void Release(int key, int x, int y);

    bool *keys();
private:
    bool _keys[256];
};


#endif //CG_KEYBOARDEVENTHANDLER_H


#include "KeyboardEventHandler.h"

KeyboardEventHandler::KeyboardEventHandler()
{
    for (int i = 0; i < 256; ++i)
        _keys[i] = false;
}

void KeyboardEventHandler::Press(int key, int x, int y)
{
    _keys[key] = true;
}

void KeyboardEventHandler::Release(int key, int x, int y)
{
    _keys[key] = false;
}

bool *KeyboardEventHandler::keys()
{
    return &_keys[0];
}


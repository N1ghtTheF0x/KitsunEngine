#include <Input.hpp>

namespace KitsunEngine
{
    void Keyboard::setKeyState(char key,bool state)
    {
        keyState[key] = state;
    }
    bool Keyboard::isKeyPressed(char key)
    {
        return keyState[key];
    }
    char Keyboard::getLastKeyPressed()
    {
        return lastKey;
    }
    void Keyboard::setLastKeyPressed(char key)
    {
        lastKey = key;
    }
}
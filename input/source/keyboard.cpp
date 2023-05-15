#include <Input.hpp>

namespace KitsunEngine
{
    void Keyboard::setKeyState(KeyType key,bool state)
    {
        keyState[key] = state;
    }
    bool Keyboard::isKeyPressed(KeyType key)
    {
        return keyState[key];
    }
    Keyboard::KeyType Keyboard::getLastKeyPressed()
    {
        return lastKey;
    }
    void Keyboard::setLastKeyPressed(KeyType key)
    {
        lastKey = key;
    }
}
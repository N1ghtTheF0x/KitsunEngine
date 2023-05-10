#include <Input.hpp>

namespace KitsunEngine
{
    void Mouse::setPosition(double x,double y)
    {
        position.setX(x);
        position.setY(y);
    }
    Utils::Vector2& Mouse::getPosition()
    {
        return position;
    }
    bool Mouse::isButtonPressed(Mouse::Button button)
    {
        return buttonState[(size_t)button];
    }
    void Mouse::setButtonPressed(Mouse::Button button,bool state)
    {
        buttonState[(size_t)button] = state;
    }
}
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
}
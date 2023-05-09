#include <Utils.hpp>

namespace KitsunEngine
{
    namespace Utils
    {
#ifdef OS_WINDOWS
        Rectangle::Rectangle(RECT rect):
            position(rect.left,rect.top), size(rect.right - rect.left,rect.bottom - rect.top)
        {
            
        }
#endif
        Rectangle::Rectangle(double x,double y,double width,double height):
            position(x,y), size(width,height)
        {

        }
        Rectangle::Rectangle(Vector2 pos,Vector2 s):
            position(pos), size(s)
        {

        }
        Vector2 &Rectangle::getPosition()
        {
            return position;
        }
        Vector2 &Rectangle::getSize()
        {
            return size;
        }
        void Rectangle::setPosition(Vector2 &pos)
        {
            position = pos;
        }
        void Rectangle::setPosition(double x,double y)
        {
            position.setX(x);position.setY(y);
        }
        void Rectangle::setSize(Vector2 &s)
        {
            size = s;
        }
        void Rectangle::setSize(double width,double height)
        {
            size.setX(width);size.setY(height);
        }
    }
}
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
        Rectangle::Rectangle(Rectangle::BBox box):
            position(box.left,box.top), size(box.right - box.left,box.bottom - box.top)
        {

        }
        Rectangle::BBox Rectangle::getBBox()
        {
            return {
                position.getX(),position.getX() + size.getX(),
                position.getY(),position.getY() + size.getY()
            };
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
        double Rectangle::getX()
        {
            return position.getX();
        }
        double Rectangle::getY()
        {
            return position.getY();
        }
        double Rectangle::getWidth()
        {
            return size.getX();
        }
        double Rectangle::getHeight()
        {
            return size.getY();
        }
        void Rectangle::setX(double x)
        {
            position.setX(x);
        }
        void Rectangle::setY(double y)
        {
            position.setY(y);
        }
        void Rectangle::setWidth(double w)
        {
            size.setX(w);
        }
        void Rectangle::setHeight(double h)
        {
            size.setY(h);
        }
    }
}
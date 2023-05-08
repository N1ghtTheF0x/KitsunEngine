#include <Utils.hpp>

namespace KitsunEngine
{
    namespace Utils
    {
        Vector2::Vector2(double _x,double _y): x(_x), y(_y)
        {

        }
        void Vector2::setX(double newX)
        {
            x = newX;
        }
        void Vector2::setY(double newY)
        {
            y = newY;
        }
        double Vector2::getX() const
        {
            return x;
        }
        double Vector2::getY() const
        {
            return y;
        }
        std::ostream &KitsunEngine::Utils::operator<<(std::ostream &os, const Vector2 &vec)
        {
            os << '(' << vec.x << '|' << vec.y << ')';
            return os;
        }
        Vector3::Vector3(double _x,double _y,double _z): x(_x), y(_y), z(_z)
        {

        }
        void Vector3::setX(double newX)
        {
            x = newX;
        }
        void Vector3::setY(double newY)
        {
            y = newY;
        }
        void Vector3::setZ(double newZ)
        {
            z = newZ;
        }
        double Vector3::getX() const
        {
            return x;
        }
        double Vector3::getY() const
        {
            return y;
        }
        double Vector3::getZ() const
        {
            return z;
        }
        std::ostream &KitsunEngine::Utils::operator<<(std::ostream &os, const Vector3 &vec)
        {
            os << '(' << vec.x << '|' << vec.y << '|' << vec.z << ')';
            return os;
        }
    }
}
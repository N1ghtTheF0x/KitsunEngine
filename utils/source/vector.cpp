#include <Utils.hpp>

#include <cmath>

#define CLOSETOZERO 0.000001

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
        double Vector2::length() const
        {
            return sqrt(x*x+y*y);
        }
        Vector2 Vector2::toPolar() const
        {
            return Vector2(
                length(),
                atan(y/(x == 0 ? CLOSETOZERO : 0))
            );
        }
        Vector2 Vector2::toCartesian() const
        {
            return Vector2(
                x * cos(y),
                x * sin(y)
            );
        }
        Vector2 Vector2::operator=(const Vector2 &other)
        {
            x = other.x;y = other.y;
            return *this;
        }
        Vector2 Vector2::operator+(const Vector2 &other)
        {
            return Vector2(x + other.x,y + other.y);
        }
        Vector2 Vector2::operator-(const Vector2 &other)
        {
            return Vector2(x - other.x,y - other.y);
        }
        Vector2 &Vector2::operator+=(const Vector2 &other)
        {
            x += other.x;
            y += other.y;
            return *this;
        }
        Vector2 &Vector2::operator-=(const Vector2 &other)
        {
            x -= other.x;
            y -= other.y;
            return *this;
        }
        double Vector2::operator*(const Vector2& other)
        {
            return x*other.x+y*other.y;
        }
        Vector2 Vector2::operator*(const double& scalar)
        {
            return Vector2(x * scalar,y * scalar);
        }
        Vector2 &Vector2::operator*=(const double& scalar)
        {
            x *= scalar;
            y *= scalar;
            return *this;
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
        double Vector3::length() const
        {
            return sqrt(x*x+y*y+z*z);
        }
        Vector3 Vector3::cross(const Vector3 &other) const
        {
            return Vector3(
                y*other.z - z*other.y,
                z*other.x - x*other.z,
                x*other.y - y*other.x
            );
        }
        Vector3 Vector3::operator=(const Vector3 &other)
        {
            x = other.x;y = other.y;z = other.z;
            return *this;
        }
        Vector3 Vector3::operator+(const Vector3 &other)
        {
            return Vector3(x + other.x,y + other.y,z + other.z);
        }
        Vector3 Vector3::operator-(const Vector3 &other)
        {
            return Vector3(x - other.x,y - other.y,z - other.z);
        }
        Vector3 &Vector3::operator+=(const Vector3 &other)
        {
            x += other.x;
            y += other.y;
            z += other.z;
            return *this;
        }
        Vector3 &Vector3::operator-=(const Vector3 &other)
        {
            x -= other.x;
            y -= other.y;
            z -= other.z;
            return *this;
        }
        double Vector3::operator*(const Vector3& other)
        {
            return x*other.x+y*other.y+z*other.z;
        }
        Vector3 Vector3::operator*(const double& scalar)
        {
            return Vector3(x * scalar,y * scalar,z * scalar);
        }
        Vector3 &Vector3::operator*=(const double& scalar)
        {
            x *= scalar;
            y *= scalar;
            z *= scalar;
            return *this;
        }
        std::ostream &KitsunEngine::Utils::operator<<(std::ostream &os, const Vector3 &vec)
        {
            os << '(' << vec.x << '|' << vec.y << '|' << vec.z << ')';
            return os;
        }
    }
}
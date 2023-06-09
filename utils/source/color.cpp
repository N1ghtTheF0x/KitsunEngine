#include <Utils.hpp>

namespace KitsunEngine
{
    namespace Utils
    {
        Color::Color(unsigned char r,unsigned char g,unsigned char b,unsigned char a): red(r), green(g), blue(b), alpha(a)
        {

        }
        Color::Color(unsigned int value)
        {
            alpha = (unsigned char)(value & 0xFF);
            blue = (unsigned char)((value & 0xFF00) >> 8);
            green = (unsigned char)((value & 0xFF0000) >> 16);
            red = (unsigned char)((value & 0xFF000000) >> 24);
        }
        Color::operator unsigned int()
        {
            return ((unsigned int)red << 24) | ((unsigned int)green << 16) | ((unsigned int)blue << 8) | (unsigned int)alpha;
        }
        unsigned char Color::getRed()
        {
            return red;
        }
        unsigned char Color::getGreen()
        {
            return green;
        }
        unsigned char Color::getBlue()
        {
            return blue;
        }
        unsigned char Color::getAlpha()
        {
            return alpha;
        }
        void Color::setRed(unsigned char value)
        {
            red = value;
        }
        void Color::setGreen(unsigned char value)
        {
            green = value;
        }
        void Color::setBlue(unsigned char value)
        {
            blue = value;
        }
        void Color::setAlpha(unsigned char value)
        {
            alpha = value;
        }
    }
}
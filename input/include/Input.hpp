#ifndef KITSUNENGINE_INPUT_HPP
#define KITSUNENGINE_INPUT_HPP

#include <Utils.hpp>

namespace KitsunEngine
{
    class Keyboard
    {
    private:
        static inline bool keyState[0xFF];
        static inline char lastKey = 0;
    public:
        static void setKeyState(char key,bool state);
        static bool isKeyPressed(char key);
        static char getLastKeyPressed();
        static void setLastKeyPressed(char key);
    };
    class Mouse
    {
    public:
        enum struct Button
        {
            Primary,
            Auxiliary,
            Secondary,
            Forward,
            Back,
            Count
        };
    private:
        static inline Utils::Vector2 position = Utils::Vector2(0,0);
        static inline bool buttonState[(size_t)Button::Count];
    public:
        static Utils::Vector2& getPosition();
        static void setPosition(double x,double y);
        static bool isButtonPressed(Button button);
        static void setButtonPressed(Button button,bool state);
    };
}

#endif
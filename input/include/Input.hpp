#ifndef KITSUNENGINE_INPUT_HPP
#define KITSUNENGINE_INPUT_HPP

#include <Utils.hpp>

#if OS_WINDOWS
    #define KITSUNENGINE_INPUT_KEYBOARD_SIZE 0xFF
#endif
#if OS_LINUX
    #define KITSUNENGINE_INPUT_KEYBOARD_SIZE 0xFFFFFFFF
#endif

namespace KitsunEngine
{
    class Keyboard
    {
    public:
#if OS_WINDOWS
        typedef char KeyType;
#endif
#if OS_LINUX
        typedef unsigned int KeyType;
#endif
    private:
        static inline bool keyState[KITSUNENGINE_INPUT_KEYBOARD_SIZE];
        static inline KeyType lastKey = 0;
    public:
        static void setKeyState(KeyType key,bool state);
        static bool isKeyPressed(KeyType key);
        static KeyType getLastKeyPressed();
        static void setLastKeyPressed(KeyType key);
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
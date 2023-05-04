#ifndef KITSUNENGINE_WINDOW_HPP
#define KITSUNENGINE_WINDOW_HPP

#ifdef OS_WINDOWS
    #ifndef UNICODE
        #define UNICODE
    #endif
    #include <windows.h>
    #define WINDOWS_CLASS_NAME L"KitsunEngineClass"
    #define WINDOWS_DEFAULT_WINDOW_TITLE L"KitsunEngine"
#endif

#include <Utils.hpp>

#include <thread>

namespace KitsunEngine
{
    class Window
    {
    private:
        Utils::Logger logger;
#ifdef OS_WINDOWS
    private:
        HWND handle;
        HINSTANCE instance;
        static LRESULT CALLBACK WindowProc(HWND handle,UINT message,WPARAM wparam,LPARAM lparam);
        STARTUPINFO info;
        void messageThreadLoop();
        std::thread threadMessage;
    public:
        struct State
        {
            Window *window;
        };
        State* curState;
        static Window::State* getWindowState(HWND handle);
#endif
    public:
        Window(unsigned int width,unsigned int height);
        void show();
        void hide();
        void listen();
        void setTitle(const char* title);
    };
}

#endif
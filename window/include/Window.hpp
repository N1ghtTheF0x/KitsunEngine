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

namespace KitsunEngine
{
    class Window
    {
    public:
        struct MessageState
        {
            enum struct Type
            {
                Nothing,
                KeyboardDown,
                KeyboardUp,
                Close,
                MouseMove,
                Ready
            };
            Type type;
            
        };
        struct State
        {
            Window *window;
            MessageState message;
        };
    private:
        Utils::Logger logger;
        State* curState;
#ifdef OS_WINDOWS
    private:
        HWND handle;
        HDC gdi;
        int pixelFormat;
        HINSTANCE instance;
        static LRESULT CALLBACK WindowProc(HWND handle,UINT message,WPARAM wparam,LPARAM lparam);
        STARTUPINFO info;
        bool running;
    public:
        static Window::State* getWindowState(HWND handle);
        int getPixelFormat();
        operator HWND();
        operator HINSTANCE();
        operator HDC();
#endif

    public:
        Window(unsigned int width,unsigned int height);
        ~Window();
        void show();
        void close();
        void hide();
        void setTitle(const char* title);
        bool isRunning();
        State* getState();
        void refreshMessages();
        MessageState &getMessage();
        Utils::Rectangle getRect();
    };
}

#endif
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
#ifdef OS_LINUX
    #include <X11/Xlib.h>
    #include <X11/Xutil.h>
    #include <X11/Xos.h>

    #define LINUX_DEFAULT_WINDOW_TITLE "KitsunEngine"
#endif

#include <Utils.hpp>

namespace KitsunEngine
{
    class Window
    {
    public:
        enum struct MessageType
        {
            Nothing,
            KeyboardDown,
            KeyboardUp,
            MouseDown,
            MouseUp,
            Close,
            MouseMove,
            Ready,
            Draw
        };
        struct State
        {
            Window *window;
            MessageType message;
        };
    private:
        Utils::Logger logger;
        State* curState;
        bool running;
#ifdef OS_WINDOWS
    private:
        HWND handle;
        HDC gdi;
        int pixelFormat;
        HINSTANCE instance;
        static LRESULT CALLBACK WindowProc(HWND handle,UINT message,WPARAM wparam,LPARAM lparam);
        STARTUPINFO info;
    public:
        static Window::State* getWindowState(HWND handle);
        int getPixelFormat();
        operator HWND();
        operator HINSTANCE();
        operator HDC();
#endif
#ifdef OS_LINUX
    private:
        Display *dis;
        int screen;
        X11Window win;
        XVisualInfo *vinfo;
        Colormap cmap;
    public:
        operator Display*();
        operator X11Window&();
        operator XVisualInfo*();
        Colormap &getColormap();
#endif
    public:
        // OS-Dependent
        Window(unsigned int width,unsigned int height);
        ~Window();
        void show();
        void close();
        void hide();
        void setTitle(const char* title);
        void setTitle(std::string title);
        void setTitle(std::stringstream title);
        void refreshMessages();
        Utils::Rectangle getRect();
        // OS-Independent
        bool isRunning();
        State* getState();
        MessageType &getMessage();
    };
}

#endif
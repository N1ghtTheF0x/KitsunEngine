#ifndef KITSUNENGINE_RENDERER_HPP
#define KITSUNENGINE_RENDERER_HPP

#ifdef OS_WINDOWS
    #include <windows.h>
#endif
#ifdef OS_LINUX
    #include <X11/X.h>
    #include <X11/Xlib.h>
    #include <GL/glx.h>
#endif

#include <GL/gl.h>
#include <GL/glu.h>

#include <Utils.hpp>

namespace KitsunEngine
{
    class Context
    {
    private:
        Utils::Logger logger;
        void printVersion();
#ifdef OS_WINDOWS
    private:
        HGLRC wgl;
        HDC gdi;
    public:
        Context(HDC gdi);
#endif
#ifdef OS_LINUX
    private:
        GLXContext glx;
        Display* dis;
        X11Window win;
        XVisualInfo *vinfo;
    public:
        Context(Display *d,X11Window w,XVisualInfo *v);
#endif
    public:
        ~Context();
        void swapBuffers();
        void drawRectangle(Utils::Rectangle &rect,Utils::Color color = 255);
        static Utils::Rectangle getViewport();
        static void setViewport(Utils::Rectangle &rect);
    };
}

#endif
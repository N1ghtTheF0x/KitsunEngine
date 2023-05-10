#ifndef KITSUNENGINE_RENDERER_HPP
#define KITSUNENGINE_RENDERER_HPP

#ifdef OS_WINDOWS
    #include <windows.h>
    #include <GL/gl.h>
    #include <GL/glu.h>
#endif
#ifdef OS_LINUX
    #include <X11/X.h>
    #include <X11/Xlib.h>
    #include <GL/glx.h>
    #include <GL/glu.h>
#endif

#include <Utils.hpp>

namespace KitsunEngine
{
    class Context
    {
    private:
        Utils::Logger logger;
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
    };
}

#endif
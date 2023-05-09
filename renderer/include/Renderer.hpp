#ifndef KITSUNENGINE_RENDERER_HPP
#define KITSUNENGINE_RENDERER_HPP

#ifdef OS_WINDOWS
    #include <windows.h>
    #include <GL/gl.h>
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
    public:
        ~Context();
    };
}

#endif
#include <Renderer.hpp>

namespace KitsunEngine
{
#ifdef OS_WINDOWS
    Context::Context(HDC g): gdi(g), logger("OpenGL")
    {
        logger.info("Creating Context...");
        wgl = wglCreateContext(gdi);
        if(wgl == NULL)
            logger.error("Couldn't create Context!");
        wglMakeCurrent(gdi,wgl);
    }
#endif
    Context::~Context()
    {
        logger.info("Deleting Context...");
#ifdef OS_WINDOWS
        if(wgl != NULL) wglDeleteContext(wgl);
#endif
    }
}
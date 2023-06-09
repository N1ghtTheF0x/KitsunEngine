#include <Renderer.hpp>

namespace KitsunEngine
{
    void Context::printVersion()
    {
        auto opengl = glGetString(GL_VERSION);
        auto renderer = glGetString(GL_RENDERER);
        auto vendor = glGetString(GL_VENDOR);
        
#ifdef OS_LINUX
        auto glsl = glGetString(GL_SHADING_LANGUAGE_VERSION);
#endif
        auto openglu = gluGetString(GLU_VERSION);

        std::string OpenGL;
            OpenGL
            .append((const char*)opengl).append(" | ")
            .append((const char*)vendor).append(" | ")
            .append((const char*)renderer).append(" | ")
#ifdef OS_LINUX
            .append((const char*)glsl).append(" | ")
#endif
            .append((const char*)openglu);

        logger.info(OpenGL);
    }
#ifdef OS_WINDOWS
    Context::Context(HDC g): gdi(g), logger("OpenGL")
    {
        logger.info("Creating Context...");
        wgl = wglCreateContext(gdi);
        if(wgl == NULL)
            logger.error("Couldn't create Context!");
        wglMakeCurrent(gdi,wgl);
        printVersion();
    }
#endif
    Context::~Context()
    {
        logger.info("Deleting Context...");
#ifdef OS_WINDOWS
        if(wgl != NULL) wglDeleteContext(wgl);
#endif
#ifdef OS_LINUX
        glXMakeCurrent(dis,None,NULL);
        glXDestroyContext(dis,glx);
#endif
    }
#ifdef OS_LINUX
    Context::Context(Display *d,X11Window w,XVisualInfo *v): logger("OpenGL"), dis(d), win(w), vinfo(v)
    {
        logger.info("Creating Context...");
        glx = glXCreateContext(dis,vinfo,NULL,GL_TRUE);
        glXMakeCurrent(dis,win,glx);
        printVersion();
    }
#endif
    void Context::swapBuffers()
    {
#ifdef OS_LINUX
        glXSwapBuffers(dis,win);
#endif
#ifdef OS_WINDOWS
        SwapBuffers(gdi);
#endif
    }
    Utils::Rectangle Context::getViewport()
    {
        int viewport[4];
        glGetIntegerv(GL_VIEWPORT,viewport);
        return Utils::Rectangle(viewport[0],viewport[1],viewport[2],viewport[3]);
    }
    void Context::setViewport(Utils::Rectangle &rect)
    {
        glViewport(rect.getX(),rect.getY(),rect.getWidth(),rect.getWidth());
    }
}
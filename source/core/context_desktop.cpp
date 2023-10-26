#include <N1ghtTheF0x/KitsunEngine/Core/Context.hpp>
#include <N1ghtTheF0x/KitsunEngine/Utils/OpenGL.hpp>
#include <N1ghtTheF0x/LibKitsune/Logger.hpp>

namespace N1ghtTheF0x
{
    namespace KitsunEngine
    {
        static LibKitsune::Logger _displayLogger = "Context";
        namespace Core
        {
            OpenGLContext::OpenGLContext(Display &display)
            {
                _display = std::make_shared<Display>(display);
                SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
                SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,4);
                SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,6);
                SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,SDL_GL_CONTEXT_PROFILE_CORE);
                _display->create(SDL_WINDOW_OPENGL|SDL_WINDOW_SHOWN);
                _context = SDL_GL_CreateContext(_display->operator SDL_Window *());
                if(_context == 0)
                {
                    _displayLogger.error() << "Couldn't create OpenGL Context for Display: " << SDL_GetError() << std::endl;
                    exit(EXIT_FAILURE);
                }
                _ready = OpenGL::InitOpenGL();
            }
            void OpenGLContext::clear()
            {
                clear(0.0f,0.0f,0.0f);
            }
            void OpenGLContext::clear(float red,float green,float blue,float alpha)
            {
                if(!_ready) return;
                glClearColor(red,green,blue,alpha);
                glClear(GL_COLOR_BUFFER_BIT);
            }
            void OpenGLContext::swap() 
            {
                SDL_GL_SwapWindow(_display->operator SDL_Window *());
            }
            Context::Type OpenGLContext::type() const
            {
                return Type::OpenGL;
            }
        }
    }
}
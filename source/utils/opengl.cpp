#include <N1ghtTheF0x/KitsunEngine/Utils/OpenGL.hpp>
#include <N1ghtTheF0x/LibKitsune/Logger.hpp>

namespace N1ghtTheF0x
{
    namespace KitsunEngine
    {
        namespace OpenGL
        {
            static LibKitsune::Logger _openglLogger = "OpenGL";
            bool __opengl_ready = false;
            bool InitOpenGL()
            {
                if(__opengl_ready) return true;
                int result = gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress);
                if(!result)
                {
                    _openglLogger.error() << "Couldn't load OpenGL!" << std::endl;
                    return false;
                }
                _openglLogger.info() << 'v' << +GLVersion.major << '.' << +GLVersion.minor << std::endl;
                __opengl_ready = true;
                return true;
            }
        }
    }
}
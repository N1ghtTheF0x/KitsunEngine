#include <N1ghtTheF0x/KitsunEngine/App.hpp>

namespace N1ghtTheF0x
{
    namespace KitsunEngine
    {
        void Application::_init()
        {
            SDL2::InitSDL2();
            createContext(Core::Context::Type::OpenGL);
        }
        void Application::_displayEvents()
        {
            while(SDL_PollEvent(&_event))
            {
                switch(_event.type)
                {
                    case SDL_QUIT:
                        _running = false;
                        break;
                }
            }
        }
        void Application::_clean()
        {
            SDL2::DestroySDL2();
        }
    }
}
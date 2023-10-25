#include <N1ghtTheF0x/KitsunEngine/App.hpp>

namespace N1ghtTheF0x
{
    namespace KitsunEngine
    {
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
    }
}
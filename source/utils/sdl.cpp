#include <N1ghtTheF0x/KitsunEngine/Utils/SDL.hpp>
#include <N1ghtTheF0x/LibKitsune/Logger.hpp>

#include <iostream>

namespace N1ghtTheF0x
{
    namespace KitsunEngine
    {
        namespace SDL2
        {
            static LibKitsune::Logger _sdl2Logger = "SDL2";
            bool __sdl_ready = false;       
            void InitSDL2()
            {
                if(__sdl_ready) return;
                if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
                {
                    _sdl2Logger.error() << "Couldn't initialize SDL: " << SDL_GetError() << std::endl;
                    exit(EXIT_FAILURE);
                }
                __sdl_ready = true;
                SDL_version version;
                SDL_GetVersion(&version);
                _sdl2Logger.info() << "SDL v" << +version.major << "." << +version.minor << "." << +version.patch << std::endl;
                IMG_Init(IMG_INIT_JPG|IMG_INIT_PNG);
            }
            void DestroySDL2()
            {
                SDL_Quit();
            }
        }
    }
}
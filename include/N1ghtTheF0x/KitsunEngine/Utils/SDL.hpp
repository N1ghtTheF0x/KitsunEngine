#ifndef __N1GHTTHEF0X_KITSUNENGINE_UTILS_SDL_HPP
#define __N1GHTTHEF0X_KITSUNENGINE_UTILS_SDL_HPP

#ifdef PLATTFORM_DESKTOP
#include <SDL.h>
#include <glad/glad.h>
#include <SDL_mixer.h>
#include <SDL_image.h>

namespace N1ghtTheF0x
{
    namespace KitsunEngine
    {
        namespace SDL2
        {
            void InitSDL2();
            void DestroySDL2();

            void InitOpenGL();
        }
    }
}

#endif
#endif
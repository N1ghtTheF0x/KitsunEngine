#ifndef __N1GHTTHEF0X_KITSUNENGINE_CORE_DISPLAY_HPP
#define __N1GHTTHEF0X_KITSUNENGINE_CORE_DISPLAY_HPP

#include "../Utils/SDL.hpp"
#include "../Utils/String.hpp"

namespace N1ghtTheF0x
{
    namespace KitsunEngine
    {
        namespace Core
        {
            class Display
            {
#ifdef PLATTFORM_DESKTOP
            public:
                static void init_sdl();
                static void deinit_sdl();

                Display(int width,int height);
                Display(int width,int height,const String &title);

                operator SDL_Window*();
            private:
                SDL_Window *_pointer;
#endif
            public:
                Display();
                ~Display();

                int width() const;
                int height() const;
            };
        }
    }
}

#endif
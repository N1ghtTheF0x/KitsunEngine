#ifndef __N1GHTTHEF0X_KITSUNENGINE_CORE_DISPLAY_HPP
#define __N1GHTTHEF0X_KITSUNENGINE_CORE_DISPLAY_HPP

#include <N1ghtTheF0x/LibKitsune/String.hpp>

#include "../Utils/SDL.hpp"

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
                

                Display(int width,int height);
                Display(int width,int height,const LibKitsune::String title);

                operator SDL_Window*();
                operator SDL_Surface*();
            private:
                LibKitsune::String _title;
                SDL_Window *_pointer;
                SDL_Surface *_surface;
#endif
            private:
                bool _created = false;
                int _width;
                int _height;
            public:
                Display();
                ~Display();

                bool create();

                int width() const;
                int height() const;
            };
        }
    }
}

#endif
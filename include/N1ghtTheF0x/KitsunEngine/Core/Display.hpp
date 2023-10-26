#ifndef __N1GHTTHEF0X_KITSUNENGINE_CORE_DISPLAY_HPP
#define __N1GHTTHEF0X_KITSUNENGINE_CORE_DISPLAY_HPP

#include <N1ghtTheF0x/LibKitsune/String.hpp>

#include "../Utils/SDL.hpp"
#include "../Utils/Macros.hpp"

namespace N1ghtTheF0x
{
    namespace KitsunEngine
    {
        namespace Core
        {
            KITSUNENGINE_CLASS(Display)
            class Display
            {
#ifdef PLATTFORM_DESKTOP
            public:
                

                Display(int width,int height);
                Display(int width,int height,const LibKitsune::String title);

                operator SDL_Window*();
                operator SDL_Surface*();

                bool create(u32 flags);
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
                bool close();

                int width() const;
                int height() const;
            };
        }
    }
}

#endif
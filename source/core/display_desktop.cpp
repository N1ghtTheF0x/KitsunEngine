#include <N1ghtTheF0x/KitsunEngine/Core/Display.hpp>
#include <N1ghtTheF0x/LibKitsune/Logger.hpp>

#define DEFAULT_WIDTH 1280
#define DEFAULT_HEIGHT 720
#define DEFAULT_TITLE "KitsunEngine"

namespace N1ghtTheF0x
{
    namespace KitsunEngine
    {
        LibKitsune::Logger _displayLogger = "Display";
        namespace Core
        {
            Display::Display(int width,int height,const LibKitsune::String title)
            {
                _width = width;
                _height = height;
                _title = title;
            }
            Display::Display(int width,int height): Display(width,height,DEFAULT_TITLE)
            {
                
            }
            Display::Display(): Display(DEFAULT_WIDTH,DEFAULT_HEIGHT,DEFAULT_TITLE)
            {

            }
            Display::~Display()
            {
                SDL_DestroyWindow(_pointer);
            }
            Display::operator SDL_Window *()
            {
                return _pointer;
            }
            Display::operator SDL_Surface *()
            {
                return _surface;
            }
            bool Display::create()
            {
                if(_created)
                    SDL_DestroyWindow(_pointer);
                _created = false;
                _pointer = SDL_CreateWindow(_title,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,_width,_height,0);
                if(_pointer == 0)
                {
                    _displayLogger.error() << "Couldn't create Window \"" << _title << "\" with a resolution of " << _width << "x" << _height << ": " << SDL_GetError() << std::endl;
                    return false;
                }
                _surface = SDL_GetWindowSurface(_pointer);
                if(_pointer == 0)
                {
                    _displayLogger.error() << "Couldn't get Window surface \"" << _title << "\" with a resolution of " << _width << "x" << _height << ": " << SDL_GetError() << std::endl;
                    return false;
                }
                _created = true;
                return true;
            }
            int Display::width() const
            {
                return _width;
            }
            int Display::height() const
            {
                return _height;
            }
        }
    }
}
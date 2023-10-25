#include <N1ghtTheF0x/KitsunEngine/Core/Display.hpp>
#include <N1ghtTheF0x/KitsunEngine/Utils/Logger.hpp>

#define DEFAULT_WIDTH 1280
#define DEFAULT_HEIGHT 720
#define DEFAULT_TITLE "KitsunEngine"

namespace N1ghtTheF0x
{
    namespace KitsunEngine
    {
        Logger _displayLogger = "Display";
        namespace Core
        {
            void Display::init_sdl()
            {
                if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
                {
                    _displayLogger.error() << "Couldn't initialize SDL: " << SDL_GetError() << std::endl;
                    exit(EXIT_FAILURE);
                }
            }
            void Display::deinit_sdl()
            {
                SDL_Quit();
            }
            Display::Display(int width,int height,const String &title)
            {
                _pointer = SDL_CreateWindow(title,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,0);
                if(_pointer == 0)
                {
                    _displayLogger.error() << "Couldn't create Window \"" << title << "\" with a resolution of " << width << "x" << height << ": " << SDL_GetError() << std::endl;
                    exit(EXIT_FAILURE);
                }
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
            int Display::width() const
            {
                int _;
                SDL_GetWindowSize(_pointer,&_,0);
                return _;
            }
            int Display::height() const
            {
                int _;
                SDL_GetWindowSize(_pointer,0,&_);
                return _;
            }
        }
    }
}
#ifndef __N1GHTTHEF0X_KITSUNENGINE_APP_HPP
#define __N1GHTTHEF0X_KITSUNENGINE_APP_HPP

#include "Utils.hpp"
#include "Core.hpp"

namespace N1ghtTheF0x
{
    namespace KitsunEngine
    {
        class Application
        {
#ifdef PLATTFORM_DESKTOP
        private:
            SDL_Event _event;
#endif
        private:
            Core::Display _display;
            bool _running = true;
        public:
            Application();
            Application(int argc,char** argv);

            int run();
        private:
            void _displayEvents();
            void _update();
            void _rendering();
        };
    }
}

#endif
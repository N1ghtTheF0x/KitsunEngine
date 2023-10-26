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
            Core::Context *_context = nullptr;
            bool _running = true;
            bool _hasContext = false;
        public:
            Application();
            Application(int argc,char** argv);
            ~Application();

            int run();
            const Core::Context *context() const;
            const Core::Display &display() const;
            Core::Context *createContext(Core::Context::Type type);
            bool hasContext() const;
        private:
            void _init();
            void _displayEvents();
            void _update();
            void _rendering();
            void _clean();
        };
    }
}

#endif
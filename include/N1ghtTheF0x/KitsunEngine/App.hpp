#ifndef __N1GHTTHEF0X_KITSUNENGINE_APP_HPP
#define __N1GHTTHEF0X_KITSUNENGINE_APP_HPP

#include "Utils.hpp"

namespace N1ghtTheF0x
{
    namespace KitsunEngine
    {
        class Application
        {
        private:
            Argv _argv;
        public:
            Application(int argc,char** argv);
        };
    }
}

#endif
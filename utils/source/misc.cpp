#include <Utils.hpp>

namespace KitsunEngine
{
    namespace Utils
    {
        double rad2deg(double rad)
        {
            return rad * 180/KITSUNENGINE_PI;
        }
        double deg2rad(double deg)
        {
            return deg * KITSUNENGINE_PI/180;
        }
    }
}

#ifdef OS_WINDOWS
namespace KitsunEngine::Utils::Win32
{
    void initConsole()
    {
#ifndef NDEBUG
        if(!AllocConsole()) return;
        FILE* dummy;
        freopen_s(&dummy,"CONIN$","r",stdin);
        freopen_s(&dummy,"CONOUT$","w",stderr);
        freopen_s(&dummy,"CONOUT$","w",stdout);
        std::cout.clear();
        std::clog.clear();
        std::cerr.clear();
        std::cin.clear();
        SetConsoleTitle("DEBUG CONSOLE");
#endif
    }
}
#endif
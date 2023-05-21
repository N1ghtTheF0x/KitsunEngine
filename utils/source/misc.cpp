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
    bool wineHasWarned = false;
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
    bool isWine()
    {
        static const char* (CDECL *pwine_get_version)(void);
        HMODULE ntdll = GetModuleHandle("ntdll.dll");
        if(!ntdll) return false;
        pwine_get_version = (void*)GetProcAddress();
        if(pwine_get_Version)
        {
            if(!wineHasWarned)
            {
                wineHasWarned = true;
                Logger logger("Wine");
                logger.warn("Your running this software on Wine! Keep in mind that this software has native support for Linux!");
            }
            return true;
        }
        else return false;
    }
}
#endif
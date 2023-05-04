#include <Utils.hpp>

namespace KitsunEngine
{
    namespace Utils
    {
        Date::Date()
        {
            time = std::time(NULL);
        }
        Date::Date(std::time_t t): time(t)
        {
            
        }
        long long Date::getMiliseconds()
        {
            return time;
        }
        long long Date::getSeconds()
        {
            return time % 60;
        }
        int Date::getMinutes()
        {
            return (time / 60) % 60;
        }
        int Date::getHours()
        {
            return (time / 3600) % 24;
        }
        int Date::getYears()
        {
            return 0;
        }
        int Date::getDay()
        {
            return 0;
        }
        int Date::getMonth()
        {
            return 0;
        }
        int Date::getWeek()
        {
            return 0;
        }
    }
}
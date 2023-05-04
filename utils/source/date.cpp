#include <Utils.hpp>

namespace KitsunEngine
{
    namespace Utils
    {
        Date::Date()
        {
            time = std::chrono::high_resolution_clock::now();
        }
        Date::Date(std::chrono::steady_clock::time_point t): time(t)
        {

        }
        long long Date::getMiliseconds()
        {
            auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(time.time_since_epoch());
            return ms.count();
        }
        long long Date::getSeconds()
        {
            auto sec = std::chrono::duration_cast<std::chrono::seconds>(time.time_since_epoch());
            return sec.count();
        }
        int Date::getMinutes()
        {
            auto min = std::chrono::duration_cast<std::chrono::minutes>(time.time_since_epoch());
            return min.count();
        }
        int Date::getHours()
        {
            auto hours = std::chrono::duration_cast<std::chrono::hours>(time.time_since_epoch());
            return hours.count();
        }
        int Date::getYears()
        {
            auto years = std::chrono::duration_cast<std::chrono::years>(time.time_since_epoch());
            return years.count();
        }
        int Date::getDay()
        {
            auto day = std::chrono::duration_cast<std::chrono::days>(time.time_since_epoch());
            return day.count();
        }
        int Date::getMonth()
        {
            auto month = std::chrono::duration_cast<std::chrono::months>(time.time_since_epoch());
            return month.count();
        }
        int Date::getWeek()
        {
            auto week = std::chrono::duration_cast<std::chrono::weeks>(time.time_since_epoch());
            return week.count();
        }
    }
}
#include <Utils.hpp>

const char* monthName[12] = {
    "Jan",
    "Feb",
    "Mar",
    "Apr",
    "May",
    "Jun",
    "Jul",
    "Aug",
    "Sep",
    "Oct",
    "Nov",
    "Dez"
};

const char* weekDayName[7] = {
    "Mon",
    "Tue",
    "Wed",
    "Thu",
    "Fri",
    "Sat",
    "Sun"
};

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
        long long Date::getMiliseconds() const
        {
            return time;
        }
        long long Date::getSeconds() const
        {
            return time % 60;
        }
        int Date::getMinutes() const
        {
            return (time / 60) % 60;
        }
        int Date::getHours() const
        {
            return (time / 3600) % 24;
        }
        int Date::getYears() const
        {
            return 0;
        }
        int Date::getDay() const
        {
            return 0;
        }
        int Date::getMonth() const
        {
            return 0;
        }
        int Date::getWeek() const
        {
            return 0;
        }
        std::string Date::toTimeString() const
        {
            std::stringstream ss;
            auto h = getHours();
            auto m = getMinutes();
            auto s = getSeconds();
            if(h < 10) ss << '0';
            ss << h;
            ss << ':';
            if(m < 10) ss << '0';
            ss << m;
            ss << ':';
            if(s < 10) ss << '0';
            ss << s;
            return ss.str();
        }
        std::string Date::toDateString() const
        {
            return std::string(weekDayName[getWeek()]) + ' ' + std::string(monthName[getMonth()]) + ' ' + std::to_string(getYears());
        }
        std::string Date::toString() const
        {
            return toDateString() + " " + toTimeString();
        }
        std::ostream &KitsunEngine::Utils::operator<<(std::ostream &os, const Date &date)
        {
            os << date.toString();
            return os;
        }
    }
}
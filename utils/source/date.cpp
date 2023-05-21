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
    "Sun",
    "Mon",
    "Tue",
    "Wed",
    "Thu",
    "Fri",
    "Sat"
};

namespace KitsunEngine
{
    namespace Utils
    {
        Date::Date()
        {
            time = std::time(NULL);
            date = localtime(&time);
        }
        Date::Date(std::time_t t): time(t), date(localtime(&time))
        {
            
        }
        Date::operator time_t()
        {
            return time;
        }
        long long Date::getMiliseconds() const
        {
            return time;
        }
        long long Date::getSeconds() const
        {
            return date->tm_sec;
        }
        int Date::getMinutes() const
        {
            return date->tm_min;
        }
        int Date::getHours() const
        {
            return date->tm_hour;
        }
        int Date::getYears() const
        {
            return date->tm_year + 1900;
        }
        int Date::getDay() const
        {
            return date->tm_mday;
        }
        int Date::getMonth() const
        {
            return date->tm_mon;
        }
        int Date::getWeek() const
        {
            return date->tm_wday;
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
            return std::string(weekDayName[getWeek()]) + ' ' + std::string(monthName[getMonth()]) + ' ' + std::to_string(getDay()) + ' ' + std::to_string(getYears());
        }
        std::string Date::toString() const
        {
            return toDateString() + " " + toTimeString();
        }
        std::ostream &operator<<(std::ostream &os, const Date &date)
        {
            os << date.toString();
            return os;
        }
    }
}
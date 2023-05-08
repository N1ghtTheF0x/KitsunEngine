#include <Utils.hpp>

#include <iostream>

namespace KitsunEngine
{
    namespace Utils
    {
        class Date;
        const char* logger_time()
        {
            std::stringstream ss;
            Date date;
            auto h = date.getHours();
            auto m = date.getMinutes();
            auto s = date.getSeconds();
            ss << '[';
            if(h < 10) ss << '0';
            ss << h;
            ss << ':';
            if(m < 10) ss << '0';
            ss << m;
            ss << ':';
            if(s < 10) ss << '0';
            ss << s;
            ss << ']';
            static std::string str = ss.str();
            return str.c_str();
        }
        Logger::Logger(const char* l): label(l)
        {

        }
        void Logger::info(const char* message)
        {
            Date date;
            std::cout << '[' << date.toTimeString() << "] [" << label << "/INFO]: " << message << std::endl;
        }
        void Logger::info(std::string message)
        {
            info(message.c_str());
        }
        void Logger::info(std::stringstream stream)
        {
            info(stream.str());
        }
        void Logger::error(const char* message)
        {
            Date date;
            std::cerr << '[' << date.toTimeString() << "] [" << label << "/ERROR]: " << message << std::endl;
        }
        void Logger::error(std::string message)
        {
            error(message.c_str());
        }
        void Logger::error(std::stringstream stream)
        {
            error(stream.str());
        }
    }
}
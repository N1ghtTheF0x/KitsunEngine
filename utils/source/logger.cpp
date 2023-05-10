#include <Utils.hpp>

#include <iostream>

namespace KitsunEngine
{
    namespace Utils
    {
        class Date;
        Logger::Logger(const char* l): label(l)
        {

        }
        Logger::Logger(std::string l): label(l.c_str())
        {

        }
        Logger::Logger(std::stringstream l): label(l.str().c_str())
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
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
        void Logger::info(const char* message) const
        {
            Date date;
            std::cout << '[' << date.toTimeString() << "] [" << label << "/INFO]: " << message << std::endl;
        }
        void Logger::info(std::string message) const
        {
            info(message.c_str());
        }
        void Logger::info(std::stringstream stream) const
        {
            info(stream.str());
        }
        void Logger::error(const char* message) const
        {
            Date date;
            std::cerr << '[' << date.toTimeString() << "] [" << label << "/ERROR]: " << message << std::endl;
        }
        void Logger::error(std::string message) const
        {
            error(message.c_str());
        }
        void Logger::error(std::stringstream stream) const
        {
            error(stream.str());
        }
        void Logger::printStacktrace()
        {
#ifdef OS_LINUX
            #define BUFFER_SIZE 256
            void* buffer[BUFFER_SIZE];
            auto addresses = backtrace(buffer,BUFFER_SIZE);
            auto symbols = backtrace_symbols(buffer,addresses);
            if(symbols != NULL)
                for(int index = 0;index < addresses;index++)
                    std::cout << symbols[index] << std::endl;
            free(symbols);
#endif
#ifdef OS_WINDOWS
            https://learn.microsoft.com/en-us/windows/win32/debug/capturestackbacktrace
#endif
        }
    }
}
#ifndef __N1GHTTHEF0X_KITSUNENGINE_UTILS_LOGGER_HPP
#define __N1GHTTHEF0X_KITSUNENGINE_UTILS_LOGGER_HPP

#include <ostream>

#include "String.hpp"

namespace N1ghtTheF0x
{
    namespace KitsunEngine
    {
        class Logger
        {
        public:
            enum struct Level
            {
                Info,
                Error,
                Warn,
                Debug
            };
        private:
            const String _label;
        public:
            Logger(const char* label);
            Logger(const std::string label);
            Logger(const std::stringstream &stream);
            Logger(const String label);
            std::ostream &print(Level level) const;
            std::ostream &print(Level level,std::ostream &stream) const;
            std::ostream &info() const;
            std::ostream &error() const;
            std::ostream &warn() const;
            std::ostream &debug() const;
            const String &label() const;
        };
    }
}

#endif
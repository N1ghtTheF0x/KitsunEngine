#ifndef __N1GHTTHEF0X_KITSUNENGINE_UTILS_STRING_HPP
#define __N1GHTTHEF0X_KITSUNENGINE_UTILS_STRING_HPP

#include <cstring>
#include <string>
#include <sstream>

#include "Types.hpp"

namespace N1ghtTheF0x
{
    namespace KitsunEngine
    {
        class String
        {
        private:
            char* _pointer;
            u64 _length;
        public:
            String(const char letter);
            String(const char* cstr);
            String(const std::string string);
            String(const std::stringstream &ss);
            ~String();

            operator const char*() const;
            operator const std::string() const;

            u64 length() const;
            char charAt(u64 index) const;
            String &append(const String &string);
        private:
            u64 _memory_length() const;
            void _resize(u64 size);
        };
    }
}

#endif
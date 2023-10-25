#include <N1ghtTheF0x/KitsunEngine/Utils/String.hpp>

#include <exception>

namespace N1ghtTheF0x
{
    namespace KitsunEngine
    {
        String::String(const char letter)
        {
            _length = 1;
            _pointer = new char[_memory_length()];
            _pointer[0] = letter;
            _pointer[_length] = '\0';
        }
        String::String(const char* cstr)
        {
            _length = strlen(cstr);
            _pointer = new char[_memory_length()];
            memcpy(_pointer,cstr,_memory_length());
        }
        String::String(const std::string string)
        {
            _length = string.size();
            _pointer = new char[_memory_length()];
            memcpy(_pointer,string.c_str(),_memory_length());
        }
        String::String(const std::stringstream &stream)
        {
            auto string = stream.str();
            _length = string.size();
            _pointer = new char[_memory_length()];
            memcpy(_pointer,string.c_str(),_memory_length());
        }
        String::~String()
        {
            delete _pointer;
        }
        String::operator const char *() const
        {
            return _pointer;
        }
        String::operator const std::string() const
        {
            return _pointer;
        }
        u64 String::length() const
        {
            return _length;
        }
        u64 String::_memory_length() const
        {
            return _length + 1;
        }
        char String::charAt(u64 index) const
        {
            if(index < 0 || index > _length)
                throw std::exception("Char out of bounds in string");
            return _pointer[index];
        }
        void String::_resize(u64 size)
        {
            char* current = new char[_memory_length()];
            u64 currentLength = _length;
            memcpy(current,_pointer,_length);
            delete _pointer;

            _length = size;
            _pointer = new char[_memory_length()];
            memcpy(_pointer,current,currentLength);
            _pointer[_length] = '\0';
        }
        String &String::append(const String &string)
        {
            u64 currentLength = _length;
            _resize(_length + string._length);
            memcpy(_pointer + currentLength,string._pointer,string._length);
            return *this;
        }
    }
}
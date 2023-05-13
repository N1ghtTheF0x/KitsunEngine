#ifndef KITSUNENGINE_UTILS_HPP
#define KITSUNENGINE_UTILS_HPP

#ifdef OS_WINDOWS
    #include <windows.h>
#endif

#ifdef OS_LINUX
    #include <X11/X.h>
    typedef Window X11Window;
#endif

#include <ctime>
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#define KITSUNENGINE_PI atan2(0,-1)

namespace KitsunEngine
{
    namespace Utils
    {
#ifdef OS_WINDOWS
        namespace Win32
        {
            void initConsole();
        }
#endif
        double rad2deg(double rad);
        double deg2rad(double deg);
        class Vector2
        {
        private:
            double x;
            double y;
        public:
            friend std::ostream& operator<<(std::ostream& os,const Vector2& vec);
            Vector2 operator=(const Vector2& other);
            Vector2 operator+(const Vector2& other);
            Vector2 operator-(const Vector2& other);
            Vector2 &operator+=(const Vector2& other);
            Vector2 &operator-=(const Vector2& other);
            double operator*(const Vector2& other);
            Vector2 operator*(const double& scalar);
            Vector2 &operator*=(const double& scalar);
            Vector2(double x,double y);
            void setX(double x);
            double getX() const;
            void setY(double y);
            double getY() const;
            double length() const;
            Vector2 toPolar() const;
            Vector2 toCartesian() const;
        };
        class Rectangle
        {
        public:
            struct BBox
            {
                double left;
                double right;
                double top;
                double bottom;
            };
        private:
            Vector2 position;
            Vector2 size;
        public:
#ifdef OS_WINDOWS
            Rectangle(RECT rect);
#endif
            Rectangle(double x,double y,double width,double height);
            Rectangle(Vector2 position,Vector2 size);
            Rectangle(BBox box);
            Vector2 &getPosition();
            Vector2 &getSize();
            void setPosition(Vector2 &pos);
            void setPosition(double x,double y);
            void setSize(Vector2 &size);
            void setSize(double width,double height);
            BBox getBBox();
        };
        class Vector3
        {
        private:
            double x;
            double y;
            double z;
        public:
            friend std::ostream& operator<<(std::ostream& os,const Vector3& vec);
            Vector3 operator=(const Vector3& other);
            Vector3 operator+(const Vector3& other);
            Vector3 operator-(const Vector3& other);
            Vector3 &operator+=(const Vector3& other);
            Vector3 &operator-=(const Vector3& other);
            double operator*(const Vector3& other);
            Vector3 operator*(const double& scalar);
            Vector3 &operator*=(const double& scalar);
            Vector3(double x,double y,double z);
            void setX(double x);
            double getX() const;
            void setY(double y);
            double getY() const;
            void setZ(double z);
            double getZ() const;
            double length() const;
            Vector3 cross(const Vector3& other) const;
        };
        class Color
        {
        private:
            unsigned char red;
            unsigned char green;
            unsigned char blue;
            unsigned char alpha;
        public:
            Color(const unsigned int value);
            Color(unsigned char r,unsigned char g,unsigned char b,unsigned char a = 255U);
            unsigned char getRed();
            unsigned char getGreen();
            unsigned char getBlue();
            unsigned char getAlpha();
            void setRed(unsigned char value);
            void setGreen(unsigned char value);
            void setBlue(unsigned char value);
            void setAlpha(unsigned char value);
            operator unsigned int();
        };
        class Date
        {
        private:
            std::time_t time;
        public:
            friend std::ostream& operator<<(std::ostream& os,const Date& vec);
            Date();
            Date(std::time_t time);
            operator time_t();
            // Time
            long long getMiliseconds() const;
            long long getSeconds() const;
            int getMinutes() const;
            int getHours() const;
            int getYears() const;
            // Day
            int getDay() const;
            int getMonth() const;
            int getWeek() const;
            // Strings
            std::string toTimeString() const;
            std::string toDateString() const;
            std::string toString() const;
        };
        class Logger
        {
        private:
            const char* label;
        public:
            Logger(const char* label);
            Logger(std::string label);
            Logger(std::stringstream label);
            void info(const char* message);
            void info(std::string message);
            void info(std::stringstream stream);
            void error(const char* message);
            void error(std::string message);
            void error(std::stringstream stream);
        };
        class File
        {
        private:
            std::fstream stream;
            std::string path;
            Logger logger;
        public:
            static const char* getCWD();
            File(const char* path,std::ios_base::openmode mode);
            File(std::string path,std::ios_base::openmode mode);
            File(std::stringstream path,std::ios_base::openmode mode);
            operator std::fstream&();
            operator std::streambuf*();
            ~File();
            bool canRead();
            bool canWrite();
            size_t size();
            void close();
            size_t read(char* buffer,size_t size);
            void write(const char* buffer,size_t size);
            size_t getWriteOffset();
            void setWriteOffset(size_t pos);
            size_t getReadOffset();
            void setReadOffset(size_t pos);
        };
        class Buffer
        {
        public:
            enum struct Endianess
            {
                Little,
                Big
            };
            static Endianess getSystemEndianess();
        private:
            Endianess endian = getSystemEndianess();
            char* buffer;
            size_t length;
            size_t readOffset = 0;
            size_t writeOffset = 0;
        public:
            operator char*();
            Buffer(char* buffer,size_t size);
            Buffer(File &file);
            Buffer(size_t size);
            size_t size();
            void clear();
            // Read
            void read(char* buffer,size_t size);
            size_t getReadOffset();
            void setReadOffset(size_t pos);
            char readInt8();char readChar();
            unsigned char readUInt8();
            short readInt16();short readShort();
            unsigned short readUInt16();
            int readInt32();int readInt();
            unsigned int readUInt32();
            long readInt64();long readLong();
            unsigned long readUInt64();
            float readFloat();
            double readDouble();
            long double readLongDouble();
            const char* readString();
            const char* readString(size_t length);
            // Write
            void write(char* buffer,size_t size);
            size_t getWriteOffset();
            void setWriteOffset(size_t pos);
            void writeInt8(char value);void writeChar(char value);
            void writeUInt8(unsigned char value);
            void writeInt16(short value);void writeShort(short value);
            void writeUInt16(unsigned short value);
            void writeInt32(int value);void writeInt(int value);
            void writeUInt32(unsigned int value);
            void writeInt64(long value);void writeLong(long value);
            void writeUInt64(unsigned long value);
            void writeFloat(float value);
            void writeDouble(double value);
            void writeLongDouble(long double value);
            void writeString(const char* value);
        };
    }
}

#endif
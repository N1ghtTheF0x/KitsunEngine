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
        private:
            Vector2 position;
            Vector2 size;
        public:
#ifdef OS_WINDOWS
            Rectangle(RECT rect);
#endif
            Rectangle(double x,double y,double width,double height);
            Rectangle(Vector2 position,Vector2 size);
            Vector2 &getPosition();
            Vector2 &getSize();
            void setPosition(Vector2 &pos);
            void setPosition(double x,double y);
            void setSize(Vector2 &size);
            void setSize(double width,double height);
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
            ~File();
            bool canRead();
            bool canWrite();
            void close();
            size_t read(char* buffer,size_t size);
            void write(const char* buffer,size_t size);
            size_t getWriteOffset();
            void setWriteOffset(size_t pos);
            size_t getReadOffset();
            void setReadOffset(size_t pos);
        };
    }
}

#endif
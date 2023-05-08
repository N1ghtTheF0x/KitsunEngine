#ifndef KITSUNENGINE_UTILS_HPP
#define KITSUNENGINE_UTILS_HPP

#include <ctime>
#include <iostream>
#include <string>
#include <sstream>

namespace KitsunEngine
{
    namespace Utils
    {
        class Vector2
        {
        private:
            double x;
            double y;
        public:
            friend std::ostream& operator<<(std::ostream& os,const Vector2& vec);
            Vector2(double x,double y);
            void setX(double x);
            double getX() const;
            void setY(double y);
            double getY() const;
        };
        class Vector3
        {
        private:
            double x;
            double y;
            double z;
        public:
            friend std::ostream& operator<<(std::ostream& os,const Vector3& vec);
            Vector3(double x,double y,double z);
            void setX(double x);
            double getX() const;
            void setY(double y);
            double getY() const;
            void setZ(double z);
            double getZ() const;
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
        };
        class Date
        {
        private:
            std::time_t time;
        public:
            friend std::ostream& operator<<(std::ostream& os,const Date& vec);
            Date();
            Date(std::time_t time);
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
    }
}

#endif
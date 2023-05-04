#ifndef KITSUNENGINE_UTILS_HPP
#define KITSUNENGINE_UTILS_HPP

#include <chrono>
#include <string>

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
            Vector2(double x,double y);
            void setX(double x);
            double getX();
            void setY(double y);
            double getY();
        };
        class Vector3
        {
        private:
            double x;
            double y;
            double z;
        public:
            Vector3(double x,double y,double z);
            void setX(double x);
            double getX();
            void setY(double y);
            double getY();
            void setZ(double z);
            double getZ();
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
            std::chrono::steady_clock::time_point time;
        public:
            Date();
            Date(std::chrono::steady_clock::time_point time);
            // Time
            long long getMiliseconds();
            long long getSeconds();
            int getMinutes();
            int getHours();
            int getYears();
            // Day
            int getDay();
            int getMonth();
            int getWeek();
        };
        class Logger
        {
        private:
            const char* label;
        public:
            Logger(const char* label);
            void info(const char* message);
            void info(std::string message);
            void error(const char* message);
            void error(std::string message);
        };
    }
}

#endif
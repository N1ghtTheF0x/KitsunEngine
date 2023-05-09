#include <Utils.hpp>

namespace KitsunEngine
{
    namespace Utils
    {
        double rad2deg(double rad)
        {
            return rad * 180/KITSUNENGINE_PI;
        }
        double deg2rad(double deg)
        {
            return deg * KITSUNENGINE_PI/180;
        }
    }
}
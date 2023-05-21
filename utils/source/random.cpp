#include <Utils.hpp>

namespace KitsunEngine::Utils
{
    Random::Random():
        seed(time(0))
    {

    }
    Random::Random(const unsigned int seed):
        seed(seed)
    {
        
    }
    Random::operator int()
    {
        srand(seed);
        return rand();
    }
    int Random::range(int max)
    {
        return *this % max;
    }
    int Random::range(int min,int max)
    {
        
    }
}
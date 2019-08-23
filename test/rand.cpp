#include "rand.hpp"
#include <random>
float randinrange(float min, float max)
{
    return (rand() / ((float)RAND_MAX) * (max - min)) + min;
}
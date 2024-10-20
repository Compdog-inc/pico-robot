#include <pico/rand.h>
#include <cstring>
#include "math/random.h"

float Random::rand_float()
{
    return (((float)get_rand_32()) / (float)(UINT32_MAX));
}

double Random::rand_double()
{
    return (((double)get_rand_64()) / (double)(UINT64_MAX));
}

int Random::rand_int(int min, int max)
{
    return min + (int)(rand_float() * (float)(max - min));
}

void Random::rand_bytes(uint8_t *bytes, size_t length)
{
    size_t segments = length >> 4;
    rng_128_t rng;
    for (size_t i = 0; i < segments; i++)
    {
        get_rand_128(&rng);
        std::memcpy(&bytes[i << 4], &rng, sizeof(rng_128_t));
    }

    size_t endLength = length - (segments << 4);
    if (endLength > 0)
    {
        get_rand_128(&rng);
        std::memcpy(&bytes[segments << 4], &rng, endLength);
    }
}
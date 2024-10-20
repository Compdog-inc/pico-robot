#ifndef _RANDOM_H
#define _RANDOM_H

#include <stdlib.h>
#include <stdint.h>

namespace Random
{
    float rand_float();
    double rand_double();
    int rand_int(int min, int max);
    void rand_bytes(uint8_t *bytes, size_t length);
};

#endif
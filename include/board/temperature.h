#ifndef _TEMPERATURE_H_
#define _TEMPERATURE_H_

#include <stdlib.h>

namespace Temperature
{
    void init();
    void deinit();
    float read_cpu();
};

#endif
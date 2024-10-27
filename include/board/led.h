#ifndef _BOARD_LED_H_
#define _BOARD_LED_H_

#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>

namespace BoardLed
{
    void init();
    void deinit();
    void set(uint16_t level);

    bool isPWM();
};

#endif
#include <pico/stdlib.h>
#include <pico/cyw43_arch.h>

#include "board/led.h"

void BoardLed::init()
{
}

void BoardLed::deinit()
{
}

static uint8_t ledOn = 255;

void BoardLed::set(uint16_t level)
{
    bool on = level >= 0x7FFF;
    if (ledOn != (on ? 1 : 0))
    {
        ledOn = (on ? 1 : 0);
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, on);
    }
}

bool BoardLed::isPWM()
{
    return false;
}
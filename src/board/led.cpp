#include <pico/stdlib.h>
#include <hardware/pwm.h>

#include "board/led.h"

void BoardLed::init()
{
#ifndef PICO_DEFAULT_LED_PIN
#error PICO_DEFAULT_LED_PIN not defined. This should never happen.
#else
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, true);
    gpio_set_function(PICO_DEFAULT_LED_PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(PICO_DEFAULT_LED_PIN);
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 4.f);
    pwm_init(slice_num, &config, true);
#endif
}

void BoardLed::deinit()
{
#ifndef PICO_DEFAULT_LED_PIN
#error PICO_DEFAULT_LED_PIN not defined. This should never happen.
#else
    gpio_deinit(PICO_DEFAULT_LED_PIN);
#endif
}

void BoardLed::set(uint16_t level)
{
#ifndef PICO_DEFAULT_LED_PIN
#error PICO_DEFAULT_LED_PIN not defined. This should never happen.
#else
    pwm_set_gpio_level(PICO_DEFAULT_LED_PIN, level);
#endif
}

bool BoardLed::isPWM()
{
    return true;
}
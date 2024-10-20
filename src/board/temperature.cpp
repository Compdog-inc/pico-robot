#include <hardware/adc.h>
#include "board/temperature.h"

void Temperature::init()
{
    adc_init();
    adc_set_temp_sensor_enabled(true);
}

void Temperature::deinit()
{
    adc_set_temp_sensor_enabled(false);
}

float Temperature::read_cpu()
{
    /* 12-bit conversion, assume max value == ADC_VREF == 3.3 V */
    constexpr float conversionFactor = 3.3f / (1 << 12);

    float adc = (float)adc_read() * conversionFactor;
    float temp = 27.0f - (adc - 0.706f) / 0.001721f;
    return temp;
}

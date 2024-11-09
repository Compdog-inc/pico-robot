#ifndef _UNITS_H_
#define _UNITS_H_

#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <concepts>

template <typename T>
concept arithmetic = std::integral<T> or std::floating_point<T>;

template <typename T>
    requires arithmetic<T>
struct Units
{
private:
    static constexpr T METER_TO_INCH = 39.3701;
    static constexpr T RADIANS_TO_DEGREES = 180.0 / M_PI;

    T value;

    constexpr Units(const T value) : value(value)
    {
    }

public:
    constexpr Units() : value(0)
    {
    }

    constexpr T meters() const
    {
        return value;
    }

    constexpr T radians() const
    {
        return value;
    }

    constexpr T inches() const
    {
        return value * METER_TO_INCH;
    }

    constexpr T degrees() const
    {
        return value * RADIANS_TO_DEGREES;
    }

    static constexpr Units<T> meters(const T value)
    {
        return Units<T>(value);
    }

    static constexpr Units<T> radians(const T value)
    {
        return Units<T>(value);
    }

    static constexpr Units<T> inches(const T value)
    {
        return Units<T>(value / METER_TO_INCH);
    }

    static constexpr Units<T> degrees(const T value)
    {
        return Units<T>(value / RADIANS_TO_DEGREES);
    }

    constexpr bool equals(const Units<T> &other) const
    {
        return other.value == value;
    }

    template <class T0>
    void pack(T0 &pack)
    {
        pack(value);
    }

    inline constexpr bool operator==(const Units<T> &other) { return equals(other); }
    inline constexpr bool operator!=(const Units<T> &other) { return !equals(other); }
};

#endif
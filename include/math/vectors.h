#ifndef _VECTORS_H_
#define _VECTORS_H_

#include <stdlib.h>
#include "gcem/sqrt.hpp"
#include <stdint.h>
#include "math/units.h"

template <typename T>
    requires arithmetic<T>
struct vec2
{
    Units<T> x;
    Units<T> y;

    constexpr vec2() : vec2(Units<T>::meters(0), Units<T>::meters(0))
    {
    }

    constexpr vec2(Units<T> x, Units<T> y) : x(x), y(y)
    {
    }

    constexpr Units<T> length() const
    {
        return Units<T>::meters(gcem::sqrt(x.meters() * x.meters() + y.meters() * y.meters()));
    }

    constexpr void normalize()
    {
        Units<T> l = length();
        x = Units<T>::meters(x.meters() / l.meters());
        y = Units<T>::meters(y.meters() / l.meters());
    }

    constexpr vec2<T> normalized() const
    {
        vec2<T> c = vec2<T>(x, y);
        c.normalize();
        return c;
    }

    constexpr bool equals(const vec2<T> &other) const
    {
        return other.x == x && other.y == y;
    }

    inline constexpr bool operator==(const vec2<T> &other) { return equals(other); }
    inline constexpr bool operator!=(const vec2<T> &other) { return !equals(other); }
};

template <typename T>
    requires arithmetic<T>
struct vec3
{
    Units<T> x;
    Units<T> y;
    Units<T> z;

    constexpr vec3() : vec3(Units<T>::meters(0), Units<T>::meters(0), Units<T>::meters(0))
    {
    }

    constexpr vec3(Units<T> x, Units<T> y, Units<T> z) : x(x), y(y), z(z)
    {
    }

    constexpr vec3(Units<T> x, Units<T> y) : vec3(x, y, Units<T>::meters(0))
    {
    }

    constexpr vec3(vec2<T> vec) : vec3(vec.x, vec.y)
    {
    }

    constexpr Units<T> length() const
    {
        return Units<T>::meters(gcem::sqrt(x.meters() * x.meters() + y.meters() * y.meters() + z.meters() * z.meters()));
    }

    constexpr void normalize()
    {
        Units<T> l = length();
        x = Units<T>::meters(x.meters() / l.meters());
        y = Units<T>::meters(y.meters() / l.meters());
        z = Units<T>::meters(z.meters() / l.meters());
    }

    constexpr vec3<T> normalized() const
    {
        vec3<T> c = vec3<T>(x, y, z);
        c.normalize();
        return c;
    }

    constexpr bool equals(const vec3<T> &other) const
    {
        return other.x == x && other.y == y && other.z == z;
    }

    inline constexpr bool operator==(const vec3<T> &other) { return equals(other); }
    inline constexpr bool operator!=(const vec3<T> &other) { return !equals(other); }
};

template <typename T>
    requires arithmetic<T>
struct vec4
{
    Units<T> x;
    Units<T> y;
    Units<T> z;
    Units<T> w;

    constexpr vec4() : vec4(Units<T>::meters(0), Units<T>::meters(0), Units<T>::meters(0), Units<T>::meters(0))
    {
    }

    constexpr vec4(Units<T> x, Units<T> y, Units<T> z, Units<T> w) : x(x), y(y), z(z), w(w)
    {
    }

    constexpr vec4(Units<T> x, Units<T> y, Units<T> z) : vec4(x, y, z, Units<T>::meters(0))
    {
    }

    constexpr vec4(Units<T> x, Units<T> y) : vec4(x, y, Units<T>::meters(0), Units<T>::meters(0))
    {
    }

    constexpr Units<T> length() const
    {
        return Units<T>::meters(gcem::sqrt(x.meters() * x.meters() + y.meters() * y.meters() + z.meters() * z.meters() + w.meters() * w.meters()));
    }

    constexpr void normalize()
    {
        Units<T> l = length();
        x = Units<T>::meters(x.meters() / l.meters());
        y = Units<T>::meters(y.meters() / l.meters());
        z = Units<T>::meters(z.meters() / l.meters());
        w = Units<T>::meters(w.meters() / l.meters());
    }

    constexpr vec4<T> normalized() const
    {
        vec4<T> c = vec4<T>(x, y, z, w);
        c.normalize();
        return c;
    }

    constexpr bool equals(const vec4<T> &other) const
    {
        return other.x == x && other.y == y && other.z == z && other.w == w;
    }

    inline constexpr bool operator==(const vec4<T> &other) { return equals(other); }
    inline constexpr bool operator!=(const vec4<T> &other) { return !equals(other); }
};

#endif
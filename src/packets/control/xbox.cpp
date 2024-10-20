#include <cstring>
#include "packets/control/xbox.h"

ssize_t Control::Xbox::fromBytes(const uint8_t *bytes, size_t length)
{
    if (length >= size)
    {
        *this = Xbox(((Xbox *)bytes)[0]);
        return size;
    }

    return -1;
}

ssize_t Control::Xbox::toBytes(uint8_t *bytes, size_t length)
{
    if (length >= size)
    {
        std::memcpy(bytes, this, size);
        return size;
    }

    return -1;
}
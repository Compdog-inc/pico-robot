#include <cstring>
#include "packets/control/xbox.h"

static uint32_t latestPacketTimestamp = 0;

ssize_t Control::Xbox::deserializePacket(const uint8_t *bytes, size_t length, const Header &header)
{
    if (header.timestamp >= latestPacketTimestamp && length >= size)
    {
        latestPacketTimestamp = header.timestamp;

        std::memcpy(&buttons_u8, &bytes[0], 1);
        std::memcpy(&axis_X, &bytes[1], sizeof(axis_X));
        std::memcpy(&axis_Y, &bytes[3], sizeof(axis_Y));
        std::memcpy(&axis_3, &bytes[5], sizeof(axis_3));
        std::memcpy(&axis_4, &bytes[7], sizeof(axis_4));
        std::memcpy(&pov, &bytes[9], sizeof(pov));
        std::memcpy(&axis_LT, &bytes[10], sizeof(axis_LT));
        std::memcpy(&axis_RT, &bytes[12], sizeof(axis_RT));
        return size;
    }

    return -1;
}

ssize_t Control::Xbox::serializePacket(uint8_t *bytes, size_t length, const Header &header)
{
    if (length >= size)
    {
        std::memcpy(bytes, this, size);
        return size;
    }

    return -1;
}
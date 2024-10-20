#ifndef _XBOX_CONTROL_PACKET_H
#define _XBOX_CONTROL_PACKET_H

#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>

#include "packets/serializedpacket.h"

namespace Control
{
    struct Xbox : public SerializedPacket
    {
    public:
        enum class POVAngle : uint8_t
        {
            None = 0,
            Deg_0 = 1,
            Deg_45 = 2,
            Deg_90 = 3,
            Deg_135 = 4,
            Deg_180 = 5,
            Deg_225 = 6,
            Deg_270 = 7,
            Deg_315 = 8
        };

        virtual ssize_t fromBytes(const uint8_t *bytes, size_t length);
        virtual ssize_t toBytes(uint8_t *bytes, size_t length);

        // byte 0
        uint8_t button_A : 1;
        uint8_t button_B : 1;
        uint8_t button_X : 1;
        uint8_t button_Y : 1;
        uint8_t button_LB : 1;
        uint8_t button_RB : 1;
        uint8_t button_6 : 1;
        uint8_t button_7 : 1;

        // byte 1-2
        int16_t axis_X;
        // byte 3-4
        int16_t axis_Y;
        // byte 5-6
        int16_t axis_3;
        // byte 7-8
        int16_t axis_4;
        // byte 9
        POVAngle pov;
        // byte 10-11
        int16_t axis_LT;
        // byte 12-13
        int16_t axis_RT;

        static constexpr size_t size = 14;

        static constexpr float getAxis(int16_t axis)
        {
            return (float)axis / (float)INT16_MAX;
        }
    };
}

#endif
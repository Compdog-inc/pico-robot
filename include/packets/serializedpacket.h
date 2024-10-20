#ifndef _SERIALIZED_PACKET_H
#define _SERIALIZED_PACKET_H

#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>

struct SerializedPacket
{
public:
    virtual ssize_t fromBytes(const uint8_t *bytes, size_t length) = 0;
    virtual ssize_t toBytes(uint8_t *bytes, size_t length) = 0;
};

#endif
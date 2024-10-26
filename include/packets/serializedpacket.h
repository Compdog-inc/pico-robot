#ifndef _SERIALIZED_PACKET_H
#define _SERIALIZED_PACKET_H

#include <stdlib.h>
#include <stdint.h>
#include <cstring>
#include <sys/types.h>

struct SerializedPacket
{
public:
    struct Header
    {
        uint8_t session;
        uint32_t timestamp;
    };

protected:
    virtual ssize_t deserializePacket(const uint8_t *bytes, size_t length, const Header &header) = 0;
    virtual ssize_t serializePacket(uint8_t *bytes, size_t length, const Header &header) = 0;

public:
    static constexpr size_t HEADER_SIZE = 5;

    static bool readHeader(const uint8_t *bytes, size_t length, Header *header);
    static bool writeHeader(uint8_t *bytes, size_t length, const Header &header);

    ssize_t deserialize(const uint8_t *bytes, size_t length);
    ssize_t serialize(uint8_t *bytes, size_t length);
};

#endif
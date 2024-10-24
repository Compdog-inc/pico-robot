#include "packets/serializedpacket.h"

bool SerializedPacket::readHeader(const uint8_t *bytes, size_t length, Header *header)
{
    if (length < HEADER_SIZE)
        return false;
    *header = {};
    std::memcpy(&header->timestamp, &bytes[0], sizeof(header->timestamp));
    return true;
}

bool SerializedPacket::writeHeader(uint8_t *bytes, size_t length, const Header &header)
{
    if (length < HEADER_SIZE)
        return false;
    std::memcpy(&bytes[0], &header, HEADER_SIZE);
    return true;
}

ssize_t SerializedPacket::deserialize(const uint8_t *bytes, size_t length)
{
    Header header;
    if (!readHeader(bytes, length, &header))
        return -1;
    bytes += HEADER_SIZE;
    length -= HEADER_SIZE;
    return deserializePacket(bytes, length, header);
}

static uint32_t packet_timestamp = 0;

ssize_t SerializedPacket::serialize(uint8_t *bytes, size_t length)
{
    Header header = {};
    header.timestamp = packet_timestamp++;

    if (!writeHeader(bytes, length, header))
        return -1;
    bytes += HEADER_SIZE;
    length -= HEADER_SIZE;
    return deserializePacket(bytes, length, header);
}
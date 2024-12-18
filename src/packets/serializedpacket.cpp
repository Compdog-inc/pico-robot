#include "packets/serializedpacket.h"
#include <pico/time.h>

bool SerializedPacket::readHeader(const uint8_t *bytes, size_t length, Header *header)
{
    if (length < HEADER_SIZE)
        return false;
    *header = {};
    std::memcpy(&header->session, &bytes[0], sizeof(header->session));
    std::memcpy(&header->timestamp, &bytes[1], sizeof(header->timestamp));
    return true;
}

bool SerializedPacket::writeHeader(uint8_t *bytes, size_t length, const Header &header)
{
    if (length < HEADER_SIZE)
        return false;
    std::memcpy(&bytes[0], &header.session, sizeof(header.session));
    std::memcpy(&bytes[1], &header.timestamp, sizeof(header.timestamp));
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

ssize_t SerializedPacket::serialize(uint8_t *bytes, size_t length)
{
    Header header = {};
    header.session = 255; /* host session */
    header.timestamp = get_absolute_time();

    if (!writeHeader(bytes, length, header))
        return -1;
    bytes += HEADER_SIZE;
    length -= HEADER_SIZE;
    return deserializePacket(bytes, length, header);
}
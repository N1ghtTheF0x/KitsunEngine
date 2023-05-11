#include <Utils.hpp>

#include <bit>
#include <cstring>

#define SWAP(v) std::byteswap(v)

namespace KitsunEngine::Utils
{
    Buffer::Endianess Buffer::getSystemEndianess()
    {
        switch(std::endian::native)
        {
            case std::endian::little:
            default:
                return Buffer::Endianess::Little;
            case std::endian::big:
                return Buffer::Endianess::Big;
        }
        return Buffer::Endianess::Little;
    }
    Buffer::Buffer(char* buf,size_t s): buffer(buf), length(s)
    {

    }
    Buffer::Buffer(File &file)
    {
        length = file.size();
        buffer = new char[length];
        std::streambuf* sbuf = file;
        sbuf->sgetn(buffer,length);
    }
    Buffer::Buffer(size_t size): length(size)
    {
        buffer = new char[length];
    }
    Buffer::operator char *()
    {
        return buffer;
    }
    size_t Buffer::size()
    {
        return length;
    }
    void Buffer::clear()
    {
        memset(buffer,0,size());
    }
    size_t Buffer::getReadOffset()
    {
        return readOffset;
    }
    size_t Buffer::getWriteOffset()
    {
        return writeOffset;
    }
    void Buffer::setReadOffset(size_t pos)
    {
        readOffset = pos;
    }
    void Buffer::setWriteOffset(size_t pos)
    {
        writeOffset = pos;
    }
    void Buffer::read(char* output,size_t size)
    {
        auto pos = buffer + readOffset;
        memcpy(output,pos,size);
        readOffset += size;
    }
    void Buffer::write(char* input,size_t size)
    {
        auto pos = buffer + writeOffset;
        memcpy(pos,input,size);
        writeOffset += size;
    }
    char Buffer::readInt8()
    {
        auto pos = buffer + readOffset;
        char value = *pos;
        readOffset += sizeof(char);
        return getSystemEndianess() == endian ? value : SWAP(value);
    }
    void Buffer::writeInt8(char value)
    {
        auto pos = buffer + writeOffset;
        *pos = value;
        writeOffset += sizeof(char);
    }
    char Buffer::readChar()
    {
        return readInt8();
    }
    void Buffer::writeChar(char value)
    {
        return writeInt8(value);
    }
    unsigned char Buffer::readUInt8()
    {
        auto pos = (unsigned char*)(buffer + readOffset);
        unsigned char value = *pos;
        readOffset += sizeof(unsigned char);
        return getSystemEndianess() == endian ? value : SWAP(value);
    }
    void Buffer::writeUInt8(unsigned char value)
    {
        auto pos = (unsigned char*)(buffer + writeOffset);
        *pos = value;
        writeOffset += sizeof(unsigned char);
    }
    short Buffer::readInt16()
    {
        auto pos = (short*)(buffer + readOffset);
        short value = *pos;
        readOffset += sizeof(short);
        return getSystemEndianess() == endian ? value : SWAP(value);
    }
    void Buffer::writeInt16(short value)
    {
        auto pos = (short*)(buffer + writeOffset);
        *pos = value;
        writeOffset += sizeof(short);
    }
    short Buffer::readShort()
    {
        return readInt16();
    }
    void Buffer::writeShort(short value)
    {
        return writeInt16(value);
    }
    unsigned short Buffer::readUInt16()
    {
        auto pos = (unsigned short*)(buffer + readOffset);
        unsigned short value = *pos;
        readOffset += sizeof(unsigned short);
        return getSystemEndianess() == endian ? value : SWAP(value);
    }
    void Buffer::writeUInt16(unsigned short value)
    {
        auto pos = (unsigned short*)(buffer + writeOffset);
        *pos = value;
        writeOffset += sizeof(value);
    }
    int Buffer::readInt32()
    {
        auto pos = (int*)(buffer + readOffset);
        int value = *pos;
        readOffset += sizeof(int);
        return getSystemEndianess() == endian ? value : SWAP(value);
    }
    void Buffer::writeInt32(int value)
    {
        auto pos = (int*)(buffer + writeOffset);
        *pos = value;
        writeOffset += sizeof(value);
    }
    int Buffer::readInt()
    {
        return readInt32();
    }
    void Buffer::writeInt(int value)
    {
        return writeInt32(value);
    }
    unsigned int Buffer::readUInt32()
    {
        auto pos = (unsigned int*)(buffer + readOffset);
        unsigned int value = *pos;
        readOffset += sizeof(unsigned int);
        return getSystemEndianess() == endian ? value : SWAP(value);
    }
    void Buffer::writeUInt32(unsigned int value)
    {
        auto pos = (unsigned int*)(buffer + writeOffset);
        *pos = value;
        writeOffset += sizeof(value);
    }
    long Buffer::readInt64()
    {
        auto pos = (long*)(buffer + readOffset);
        long value = *pos;
        readOffset += sizeof(long);
        return getSystemEndianess() == endian ? value : SWAP(value);
    }
    void Buffer::writeInt64(long value)
    {
        auto pos = (long*)(buffer + writeOffset);
        *pos = value;
        writeOffset += sizeof(value);
    }
    long Buffer::readLong()
    {
        return readInt64();
    }
    void Buffer::writeLong(long value)
    {
        return writeInt64(value);
    }
    unsigned long Buffer::readUInt64()
    {
        auto pos = (unsigned long*)(buffer + readOffset);
        unsigned long value = *pos;
        readOffset += sizeof(unsigned long);
        return getSystemEndianess() == endian ? value : SWAP(value);
    }
    void Buffer::writeUInt64(unsigned long value)
    {
        auto pos = (unsigned long*)(buffer + writeOffset);
        *pos = value;
        writeOffset += sizeof(value);
    }
    float Buffer::readFloat()
    {
        auto pos = (float*)(buffer + readOffset);
        float value = *pos;
        readOffset += sizeof(float);
        return value;
    }
    void Buffer::writeFloat(float value)
    {
        auto pos = (float*)(buffer + writeOffset);
        *pos = value;
        writeOffset += sizeof(value);
    }
    double Buffer::readDouble()
    {
        auto pos = (double*)(buffer + readOffset);
        double value = *pos;
        readOffset += sizeof(double);
        return value;
    }
    void Buffer::writeDouble(double value)
    {
        auto pos = (double*)(buffer + writeOffset);
        *pos = value;
        writeOffset += sizeof(value);
    }
    long double Buffer::readLongDouble()
    {
        auto pos = (long double*)(buffer + readOffset);
        long double value = *pos;
        readOffset += sizeof(long double);
        return value;
    }
    void Buffer::writeLongDouble(long double value)
    {
        auto pos = (long double*)(buffer + writeOffset);
        *pos = value;
        writeOffset += sizeof(value);
    }
    const char* Buffer::readString()
    {
        auto str = (const char*)(buffer + readOffset);
        readOffset += strlen(str);
        return str;
    }
    const char* Buffer::readString(size_t length)
    {
        return "TODO";
    }
    void Buffer::writeString(const char* value)
    {
        auto pos = buffer + writeOffset;
        memcpy(pos,value,strlen(value));
        writeOffset += strlen(value);
    }
}
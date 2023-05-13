#ifndef KITSUNENGINE_IMAGE_HPP
#define KITSUNENGINE_IMAGE_HPP

#include <Utils.hpp>

#include <GL/gl.h>
#include <GL/glu.h>

namespace KitsunEngine
{
    namespace ImageFormats
    {
        struct PNG
        {

        };
        struct BMP
        {
            struct Header
            {
                char signature[2];
                unsigned int fileSize;
                char reserved[4];
                unsigned int dataOffset;
            } header;
            struct InfoHeader
            {
                enum struct BitCount : unsigned short
                {
                    Monochrome = 1,
                    Bit4 = 4,
                    Bit8 = 8,
                    Bit16 = 16,
                    Bit24 = 24
                };
                enum struct Compression : unsigned int
                {
                    RedGreenBlue,
                    RLE8,
                    RLE4
                };
                unsigned int size;
                unsigned int width;
                unsigned int height;
                unsigned short planes;
                BitCount bitCount;
                Compression compression;
                unsigned int imageSize;
                unsigned int XpixelsPerM;
                unsigned int YpixelsPerM;
                unsigned int colorsUsed;
                unsigned int colorsImported;
            } info;
        };
    }
    class Image
    {
    private:
        size_t width;
        size_t height;
    };
}

#endif
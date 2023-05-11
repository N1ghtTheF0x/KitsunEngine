#ifndef KITSUNENGINE_AUDIO_HPP
#define KITSUNENGINE_AUDIO_HPP

#include <Utils.hpp>

namespace KitsunEngine
{
    namespace AudioFormats
    {
        struct Wave
        {
            static void parse(Utils::Buffer &buf,Wave* input);
            struct Chunk
            {
                char ckID[4];
                unsigned int ckSize;
            };
            struct RiffHeader : public Chunk
            {
                char waveID[4];
            } riff;
            struct fmtChunk : public Chunk
            {
                unsigned short wFormatTag;
                unsigned short nChannels;
                unsigned int nSamplePerSec;
                unsigned int nAvgBytesPerSec;
                unsigned short nBlockAlign;
                unsigned short nBitsPerSample;
                struct Ext
                {
                    unsigned short cbSize;
                    unsigned short wValidBitsPerSample;
                    unsigned int dwChannelMask;
                    char SubFormat[16];
                };
            };
        };
    }
};

#endif
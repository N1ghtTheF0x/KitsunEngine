#ifndef KITSUNENGINE_AUDIO_HPP
#define KITSUNENGINE_AUDIO_HPP

namespace KitsunEngine
{
    namespace AudioFormats
    {
        struct Wave
        {
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
                
            };
        };
    }
};

#endif
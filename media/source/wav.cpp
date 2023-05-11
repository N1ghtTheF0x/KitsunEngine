#include <Audio.hpp>

#include <cstring>

namespace KitsunEngine::AudioFormats
{
    void Wave::parse(Utils::Buffer &buf,Wave* input)
    {
        auto ckID = buf.readString(4);

        if(ckID == "RIFF")
        {
            auto riff = &input->riff;
            memcpy(riff->ckID,ckID,4);
            riff->ckSize = buf.readUInt32();
            auto waveID = buf.readString(4);
            memcpy(riff->waveID,waveID,4);
        }
    }
}
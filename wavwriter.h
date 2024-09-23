#ifndef WAVWRITER_H
#define WAVWRITER_H

#include "WavHeader.h"
#include <string>

class WavWriter
{
    public:
        void writeSineWave(const std::string& filename, int sampleRate, int frequency, int duration, int amplitude = 32767);
};

#endif

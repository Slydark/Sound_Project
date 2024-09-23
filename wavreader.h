#ifndef WAVREADER_H
#define WAVREADER_H

#include "WavHeader.h"
#include <string>
#include <vector>

class WavReader
{
    private:
        WavHeader header;
        std::string filename;
        std::vector<int16_t> audioData;

    public:
        WavReader(const std::string& file);
        bool read();
        void displayHeaderInfo();
        const std::vector<int16_t>& getAudioData() const;
        const WavHeader& getHeader() const;
};

#endif

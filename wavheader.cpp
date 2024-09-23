#include "WavHeader.h"

void WavHeader::display()
{
    std::cout << "Sample Rate: " << sampleRate << " Hz" << "\n";
    std::cout << "Number of Channels: " << numChannels << "\n";
    std::cout << "Bits Per Sample: " << bitsPerSample << "\n";
}

double WavHeader::getDuration()
{
    return static_cast<double>(subchunk2Size) / (sampleRate * numChannels * (bitsPerSample / 8));
}

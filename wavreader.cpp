#include "WavReader.h"
#include <fstream>
#include <iostream>

WavReader::WavReader(const std::string& file) : filename(file) {}

bool WavReader::read()
{
    std::ifstream fileStream(filename, std::ios::binary);
    if (!fileStream)
    {
        std::cerr << "Failed to open file: " << filename << "\n";
        return false;
    }

    fileStream.read(reinterpret_cast<char*>(&header), sizeof(WavHeader));

    // Lire les données audio
    audioData.resize(header.subchunk2Size / sizeof(int16_t));
    fileStream.read(reinterpret_cast<char*>(audioData.data()), header.subchunk2Size);

    fileStream.close();
    return true;
}

void WavReader::displayHeaderInfo()
{
    header.display();
    std::cout << "Duration: " << header.getDuration() << " seconds" << "\n";
}

const std::vector<int16_t>& WavReader::getAudioData() const
{
    return audioData;
}

const WavHeader& WavReader::getHeader() const
{
    return header;
}

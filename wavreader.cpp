#include "WavReader.h"
#include <fstream>
#include <iostream>
#include <QDebug>

WavReader::WavReader(const std::string& file) : filename(file) {}

// bool WavReader::read()
// {
//     std::ifstream fileStream(filename, std::ios::binary);
//     if (!fileStream)
//     {
//         std::cerr << "Failed to open file: " << filename << "\n";
//         return false;
//     }

//     fileStream.read(reinterpret_cast<char*>(&header), sizeof(WavHeader));

//     // Lire les données audio
//     audioData.resize(header.subchunk2Size / sizeof(int16_t));
//     fileStream.read(reinterpret_cast<char*>(audioData.data()), header.subchunk2Size);

//     fileStream.close();
//     return true;
// }

bool WavReader::read()
{
    std::ifstream fileStream(filename, std::ios::binary);
    if (!fileStream)
    {
        std::cerr << "Failed to open file: " << filename << "\n";
        return false;
    }

    fileStream.read(reinterpret_cast<char*>(&header), sizeof(WavHeader));

    // Debugging: Afficher les informations du header
    qDebug() << "Chunk ID:" << QString::fromStdString(std::string(header.chunkID, 4));
    qDebug() << "Chunk Size:" << header.chunkSize;
    qDebug() << "Format:" << QString::fromStdString(std::string(header.format, 4));
    qDebug() << "Subchunk1 ID:" << QString::fromStdString(std::string(header.subchunk1ID, 4));
    qDebug() << "Subchunk1 Size:" << header.subchunk1Size;
    qDebug() << "Audio Format:" << header.audioFormat;
    qDebug() << "Number of Channels:" << header.numChannels;
    qDebug() << "Sample Rate:" << header.sampleRate;
    qDebug() << "Byte Rate:" << header.byteRate;
    qDebug() << "Block Align:" << header.blockAlign;
    qDebug() << "Bits Per Sample:" << header.bitsPerSample;
    qDebug() << "Subchunk2 ID:" << QString::fromStdString(std::string(header.subchunk2ID, 4));
    qDebug() << "Subchunk2 Size:" << header.subchunk2Size;

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

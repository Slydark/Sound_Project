#include "WavWriter.h"
#include <fstream>
#include <cmath>
#include <iostream>

void WavWriter::writeSineWave(const std::string& filename, int sampleRate, int frequency, int duration, int amplitude)
{
    WavHeader header;
    std::ofstream outFile(filename, std::ios::binary);

    // Remplir le header WAV
    header.chunkSize = 36 + sampleRate * duration * 2;  // 2 octets par échantillon (16 bits)
    header.subchunk1Size = 16;
    header.audioFormat = 1;
    header.numChannels = 1;
    header.sampleRate = sampleRate;
    header.byteRate = sampleRate * 2;
    header.blockAlign = 2;
    header.bitsPerSample = 16;
    header.subchunk2Size = sampleRate * duration * 2;

    // Ecrire le header
    outFile.write("RIFF", 4);
    outFile.write(reinterpret_cast<const char*>(&header.chunkSize), 4);
    outFile.write("WAVE", 4);
    outFile.write("fmt ", 4);
    outFile.write(reinterpret_cast<const char*>(&header.subchunk1Size), 4);
    outFile.write(reinterpret_cast<const char*>(&header.audioFormat), 2);
    outFile.write(reinterpret_cast<const char*>(&header.numChannels), 2);
    outFile.write(reinterpret_cast<const char*>(&header.sampleRate), 4);
    outFile.write(reinterpret_cast<const char*>(&header.byteRate), 4);
    outFile.write(reinterpret_cast<const char*>(&header.blockAlign), 2);
    outFile.write(reinterpret_cast<const char*>(&header.bitsPerSample), 2);
    outFile.write("data", 4);
    outFile.write(reinterpret_cast<const char*>(&header.subchunk2Size), 4);

    // Générer et écrire les données audio sinusoïdales
    for (int i = 0; i < sampleRate * duration; ++i)
    {
        double t = static_cast<double>(i) / sampleRate;
        int16_t sample = static_cast<int16_t>(amplitude * std::sin(2 * M_PI * frequency * t));
        outFile.write(reinterpret_cast<const char*>(&sample), sizeof(int16_t));
    }

    outFile.close();
    std::cout << "Sine wave file created: " << filename << "\n";
}

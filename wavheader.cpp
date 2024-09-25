#include "WavHeader.h"
#include <QDebug>

void WavHeader::display()
{
    qDebug() << "Sample Rate: " << sampleRate << " Hz" << "\n";
    qDebug() << "Number of Channels: " << numChannels << "\n";
    qDebug() << "Bits Per Sample: " << bitsPerSample << "\n";
}

double WavHeader::getDuration()
{
    return static_cast<double>(subchunk2Size) / (sampleRate * numChannels * (bitsPerSample / 8));
}

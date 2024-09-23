#ifndef WAVDFT_H
#define WAVDFT_H

#include <vector>
#include <complex>

class WavDFT
{
    private:
        std::vector<double> magnitudes;
        std::vector<double> frequencies;

    public:
        void computeDFT(const std::vector<int16_t>& audioData, int sampleRate);
        void displayMagnitudeAndFrequency();
        const std::vector<double>& getFrequencies() const {return frequencies;}
        const std::vector<double>& getMagnitudes() const {return magnitudes;}
};

#endif

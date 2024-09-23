#include "WavDFT.h"
#include <iostream>
#include <cmath>

void WavDFT::computeDFT(const std::vector<int16_t>& audioData, int sampleRate)
{
    int N = audioData.size();
    magnitudes.resize(N / 2);
    frequencies.resize(N / 2);

    for (int k = 0; k < N / 2; ++k)
    {
        std::complex<double> sum(0, 0);
        for (int n = 0; n < N; ++n)
        {
            double angle = 2 * M_PI * k * n / N;
            sum += std::polar(static_cast<double>(audioData[n]), -angle);
        }
        magnitudes[k] = std::abs(sum) / N;
        frequencies[k] = k * static_cast<double>(sampleRate) / N;
    }
}

void WavDFT::displayMagnitudeAndFrequency()
{
    for (size_t i = 0; i < magnitudes.size(); ++i)
    {
        // std::cout << "Frequency: " << frequencies[i] << " Hz, Magnitude: " << magnitudes[i] << "\n";
    }
}

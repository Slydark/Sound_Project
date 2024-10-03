#ifndef WAVFFT_H
#define WAVFFT_H

#include <vector>
#include <string>

class WavFFT
{
    public:
        std::vector<double>readWavFile(const char *filename, int &sampleRate, int &numSample);
        void prepareFFTData(const std::vector<double> &sample, double *real, double *imag, int n);
        int FFT(int dir, int m, double *x, double *y);

        // Récupérer les fréquences et magnitudes après FFT
        const std::vector<double>& getFrequencies() const;
        const std::vector<double>& getMagnitudes() const;
};

#endif // WAVFFT_H



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
        void printFFTMagnitude(double *real, double *imag, int n);

// public:
//     WavFFT();

//     // Méthode pour lire le fichier WAV et préparer la FFT
//     bool computeFFT(const std::string& filename);

        // Récupérer les fréquences et magnitudes après FFT
        const std::vector<double>& getFrequencies() const;
        const std::vector<double>& getMagnitudes() const;

// private:
//     int sampleRate;
//     int numSamples;
//     std::vector<double> frequencies;
//     std::vector<double> magnitudes;

//     // Fonction FFT
//     void performFFT(std::vector<double>& samples);

//     // Méthode interne pour lire le fichier WAV
//     std::vector<double> readWavFile(const std::string& filename, int& sampleRate, int& numSamples);

//     // Préparer les données pour la FFT
//     void prepareFFTData(const std::vector<double>& samples, double* real, double* imag, int n);

//     // Implémentation de l'algorithme FFT
//     int FFT(int dir, int m, double* x, double* y);
};

#endif // WAVFFT_H



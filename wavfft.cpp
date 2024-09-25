#include "wavfft.h"
#include "wavheader.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdint>
#include <QDebug>

std::vector<double> WavFFT::readWavFile(const char *filename, int &sampleRate, int &numSample)
{
    std::ifstream file(filename, std::ios::binary);
    if(!file.is_open())
    {
        qDebug() << "Error opening WAV file : " << filename;
        exit(1);
    }

    // Lire l'en-tête WAV
    WavHeader header;
    file.read(reinterpret_cast<char*>(&header), sizeof(WavHeader));

    // Vérification de l'en-tête WAV
    if(std::string(header.format, 4) != "RIFF" || std::string(header.subchunk1ID, 4) != "WAVE")
    {
        qDebug() << "Invalid WAV file format !";
        exit(1);
    }

    // Récupérer les informations de l'en-tête
    sampleRate = header.sampleRate;
    // Nombre d'échantillons
    numSample = header.subchunk2Size / (header.bitsPerSample / 8);

    // Lire les données audio
    std::vector<double> samples(numSample);
    if(header.bitsPerSample == 16)
    {
        // Si les échantillons sont sur 16 Bits
        int16_t sample;
        for(int i = 0; i < numSample; i++)
        {
            file.read(reinterpret_cast<char*>(&sample), sizeof(int16_t));
            samples[i] = sample / 32768.0;
        }
    }
    else if(header.bitsPerSample == 8)
    {
        // Si les échantillons sont sur 8 Bits
        uint8_t sample;
        for(int i = 0; i < numSample; i++)
        {
            file.read(reinterpret_cast<char*>(&sample), sizeof(uint8_t));
            samples[i] = (sample - 128) / 128.0;
        }
    }
    else
    {
        qDebug() << "Unsupported bit depth : " << header.bitsPerSample;
        exit(1);
    }

    file.close();
    return samples;
}

void WavFFT::prepareFFTData(const std::vector<double> &samples, double *real, double *imag, int n)
{
    int sampleSize = samples.size();
    for(int i = 0; i < n; i++)
    {
        if(i < sampleSize)
        {
            // Partie réelle (échantillons audio)
            real[i] = samples[i];
            imag[i] = 0.0;
        }
        else
        {
            real[i] = 0.0;
            imag[i] = 0.0;
        }
    }
}

int WavFFT::FFT(int dir, int m, double *x, double *y)
{
    int n,i,i1,j,k,i2,l,l1,l2;
    double c1,c2,tx,ty,t1,t2,u1,u2,z;

    /* Calculate the number of points */
    n = 1;
    for(i = 0; i < m; i++)
    {
        n *= 2;
    }

    /* Do the bit reversal */
    i2 = n >> 1;
    j = 0;
    for(i = 0; i < n - 1; i++)
    {
        if(i < j)
        {
            tx = x[i];
            ty = y[i];
            x[i] = x[j];
            y[i] = y[j];
            x[j] = tx;
            y[j] = ty;
        }
        k = i2;
        while(k <= j)
        {
            j -= k;
            k >>= 1;
        }
        j += k;
    }

    /* Compute the FFT */
    c1 = -1.0;
    c2 = 0.0;
    l2 = 1;
    for(l = 0; l < m; l++)
    {
        l1 = l2;
        l2 <<= 1;
        u1 = 1.0;
        u2 = 0.0;
        for(j = 0; j < l1; j++)
        {
            for(i = j; i < n; i += l2)
            {
                i1 = i + l1;
                t1 = u1 * x[i1] - u2 * y[i1];
                t2 = u1 * y[i1] + u2 * x[i1];
                x[i1] = x[i] - t1;
                y[i1] = y[i] - t2;
                x[i] += t1;
                y[i] += t2;
            }
            z =  u1 * c1 - u2 * c2;
            u2 = u1 * c2 + u2 * c1;
            u1 = z;
        }
        c2 = sqrt((1.0 - c1) / 2.0);
        if(dir == 1)
        {
            c2 = -c2;
        }
        c1 = sqrt((1.0 + c1) / 2.0);
    }

    /* Scaling for forward transform */
    if(dir == 1)
    {
        for(i = 0; i < n; i++)
        {
            x[i] /= n;
            y[i] /= n;
        }
    }

    return(1);
}

void WavFFT::printFFTMagnitude(double *real, double *imag, int n)
{
    for(int i = 0; i < 10; i++)
    {
        double magnitude = sqrt(real[i] * real[i] + imag[i] * imag[i]);
    }
}

// WavFFT::WavFFT() : sampleRate(0), numSamples(0) {}

// bool WavFFT::computeFFT(const std::string& filename) {
//     qDebug() << "Computing FFT for file:" << QString::fromStdString(filename);
//     std::vector<double> samples = readWavFile(filename, sampleRate, numSamples);
//     if (samples.empty()) {
//         qDebug() << "Failed to read samples from file:" << QString::fromStdString(filename);
//         return false;
//     }

//     qDebug() << "Successfully read samples from file:" << QString::fromStdString(filename);
//     performFFT(samples);
//     return true;
// }


// std::vector<double> WavFFT::readWavFile(const std::string& filename, int& sampleRate, int& numSamples) {
//     std::ifstream file(filename, std::ios::binary);
//     if (!file.is_open()) {
//         std::cerr << "Error opening WAV file: " << filename << std::endl;
//         return {};
//     }

//     WavHeader header;
//     file.read(reinterpret_cast<char*>(&header), sizeof(WavHeader));

//     if (std::string(header.chunkID, 4) != "RIFF" || std::string(header.format, 4) != "WAVE") {
//         std::cerr << "Invalid WAV file format!" << std::endl;
//         return {};
//     }

//     sampleRate = header.sampleRate;
//     numSamples = header.subchunk2Size / (header.bitsPerSample / 8);

//     std::vector<double> samples(numSamples);
//     if (header.bitsPerSample == 16) {
//         int16_t sample;
//         for (int i = 0; i < numSamples; ++i) {
//             file.read(reinterpret_cast<char*>(&sample), sizeof(int16_t));
//             samples[i] = sample / 32768.0;  // Normalisation entre -1 et 1
//             // qDebug() << "Sample[" << i << "]:" << samples[i];
//         }
//     } else {
//         std::cerr << "Unsupported bit depth: " << header.bitsPerSample << std::endl;
//         return {};
//     }

//     file.close();
//     return samples;
// }

// void WavFFT::performFFT(std::vector<double>& samples) {
//     int m = 1;
//     while ((1 << m) < numSamples) {
//         m++;
//     }
//     int n = 1 << m;

//     double* real = new double[n];
//     double* imag = new double[n];

//     prepareFFTData(samples, real, imag, n);
//     FFT(1, m, real, imag);

//     frequencies.resize(n / 2);
//     magnitudes.resize(n / 2);

//     for (int i = 0; i < n / 2; ++i) {
//         frequencies[i] = i * (double(sampleRate) / n);
//         magnitudes[i] = sqrt(real[i] * real[i] + imag[i] * imag[i]);
//         // qDebug() << "Frequency bin" << frequencies[i] << ": Magnitude =" << magnitudes[i];
//     }

//     delete[] real;
//     delete[] imag;
// }


// // void WavFFT::performFFT(std::vector<double>& samples) {
// //     int m = 1;
// //     while ((1 << m) < numSamples) {
// //         m++;
// //     }
// //     int n = 1 << m;

// //     double* real = new double[n];
// //     double* imag = new double[n];

// //     prepareFFTData(samples, real, imag, n);
// //     FFT(1, m, real, imag);

// //     frequencies.resize(n / 2);
// //     magnitudes.resize(n / 2);

// //     for (int i = 0; i < n / 2; ++i) {
// //         frequencies[i] = i * (double(sampleRate) / n);
// //         magnitudes[i] = sqrt(real[i] * real[i] + imag[i] * imag[i]);
// //         // qDebug() << "Frequency bin" << frequencies[i] << ": Magnitude =" << magnitudes[i];
// //     }

// //     delete[] real;
// //     delete[] imag;
// // }



// void WavFFT::prepareFFTData(const std::vector<double>& samples, double* real, double* imag, int n) {
//     for (int i = 0; i < n; ++i) {
//         if (i < samples.size()) {
//             real[i] = samples[i];
//         } else {
//             real[i] = 0.0;
//         }
//         imag[i] = 0.0;
//     }
// }

// int WavFFT::FFT(int dir, int m, double* x, double* y) {
//     int n = 1 << m;
//     int i, j = 0, k, i1, i2, l, l1, l2;
//     double c1, c2, tx, ty, t1, t2, u1, u2, z;

//     i2 = n >> 1;
//     for (i = 0; i < n - 1; i++) {
//         if (i < j) {
//             tx = x[i];
//             ty = y[i];
//             x[i] = x[j];
//             y[i] = y[j];
//             x[j] = tx;
//             y[j] = ty;
//         }
//         k = i2;
//         while (k <= j) {
//             j -= k;
//             k >>= 1;
//         }
//         j += k;
//     }

//     c1 = -1.0;
//     c2 = 0.0;
//     l2 = 1;
//     for (l = 0; l < m; l++) {
//         l1 = l2;
//         l2 <<= 1;
//         u1 = 1.0;
//         u2 = 0.0;
//         for (j = 0; j < l1; j++) {
//             for (i = j; i < n; i += l2) {
//                 i1 = i + l1;
//                 t1 = u1 * x[i1] - u2 * y[i1];
//                 t2 = u1 * y[i1] + u2 * x[i1];
//                 x[i1] = x[i] - t1;
//                 y[i1] = y[i] - t2;
//                 x[i] += t1;
//                 y[i] += t2;
//             }
//             z = u1 * c1 - u2 * c2;
//             u2 = u1 * c2 + u2 * c1;
//             u1 = z;
//         }
//         c2 = sqrt((1.0 - c1) / 2.0);
//         if (dir == 1) {
//             c2 = -c2;
//         }
//         c1 = sqrt((1.0 + c1) / 2.0);
//     }

//     if (dir == 1) {
//         for (i = 0; i < n; i++) {
//             x[i] /= n;
//             y[i] /= n;
//         }
//     }

//     return 1;
// }

// // void WavFFT::performFFT(std::vector<double>& samples) {
// //     int m = 1;
// //     while ((1 << m) < numSamples) {
// //         m++;
// //     }
// //     int n = 1 << m;

// //     double* real = new double[n];
// //     double* imag = new double[n];

// //     prepareFFTData(samples, real, imag, n);
// //     FFT(1, m, real, imag);

// //     frequencies.resize(n / 2);
// //     magnitudes.resize(n / 2);

// //     for (int i = 0; i < n / 2; ++i) {
// //         frequencies[i] = i * (double(sampleRate) / n);
// //         magnitudes[i] = sqrt(real[i] * real[i] + imag[i] * imag[i]);
// //         std::cout << "Frequency bin " << frequencies[i] << ": Magnitude = " << magnitudes[i] << std::endl;
// //     }


// //     delete[] real;
// //     delete[] imag;
// // }

// const std::vector<double>& WavFFT::getFrequencies() const {
//     return frequencies;
// }

// const std::vector<double>& WavFFT::getMagnitudes() const {
//     return magnitudes;
// }


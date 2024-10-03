#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <fstream>
#include <QVector>
#include <QString>
#include <cstring>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    // , reader("sin400hz.wav")
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::plotDFT(const std::vector<double>& frequencies, const std::vector<double>& magnitudes)
{
    std::fstream CSVFile;
    // Open or create a new csv
    remove("CSVData.csv");
    CSVFile.open("CSVData.csv", std::ios::app);

    const int maxPoints = 500;
    int step = std::max(1, static_cast<int>(frequencies.size() / maxPoints));

    for (size_t i = 0; i < frequencies.size(); i += step) {
        double magnitude = magnitudes[i] > 0 ? 20 * log10(magnitudes[i]) : 0;
        // series->append(frequencies[i], magnitude);
        // qDebug() << "Frequency:" << frequencies[i] << "Magnitude:" << magnitude;
        CSVFile << frequencies[i] << ", " << magnitude << "\n";
    }

    for (size_t i = 0; i < frequencies.size(); i += step) {
        // Save a CSV File

    }

    QVector<double> qFrequencies(frequencies.begin(), frequencies.end());
    QVector<double> qMagnitudes(magnitudes.begin(), magnitudes.end());

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(qFrequencies, qMagnitudes);
    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("Frequencies");
    ui->customPlot->yAxis->setLabel("Magnitudes");
    // let the ranges scale themselves so graph 0 fits perfectly in the visible area:
    ui->customPlot->graph(0)->rescaleAxes();
    ui->customPlot->replot();
}

void MainWindow::on_btnLoadWav_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open WAV File"), "", tr("WAV Files (*.wav)"));
    if(filePath.isEmpty())
    {
        qDebug() << "No file selected.";
        return;
    }

    qDebug() << "Selected WAV file:" << filePath;

    QFile file(filePath);
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);

    const char* filePathChar = filePath.toStdString().c_str();

    // WavFFT fft;
    int sampleRate, numSample;
    std::vector<double> samples = fft.readWavFile(filePathChar, sampleRate, numSample);

    int m = static_cast<int>(std::log2(numSample));
    int n = 1 << m;

    double *real = new double[n];
    double *imag = new double[n];

    fft.prepareFFTData(samples, real, imag, n);
    fft.FFT(1, m, real, imag);

    qDebug() << "FFT computed successfully.";

    // Convertir les tableaux en vecteurs
    std::vector<double> realVec(real, real + n);
    std::vector<double> imagVec(imag, imag + n);
    // Afficher le plot
    plotDFT(realVec, imagVec);
    // Afficher les données du header WAV
    in.readRawData(header.chunkID, 4);
    QString chunkIDString = QString(header.chunkID);
    ui->lbl_chunkId->setText(chunkIDString.left(4));

    in >> header.chunkSize;
    std::string chunkSizeString = std::to_string(header.chunkSize);
    ui->lbl_chunkSize->setText(QString::fromStdString(std::string(chunkSizeString)));

    in.readRawData(header.format, 4);
    QString formatString = QString(header.format);
    ui->lbl_format->setText(formatString.left(4));

    in.readRawData(header.subchunk1ID, 4);
    QString subChunk1IDString = QString(header.subchunk1ID);
    ui->lbl_subChunk1ID->setText(subChunk1IDString.left(4));

    in >> header.subchunk1Size;
    std::string subChunk1SizeString = std::to_string(header.subchunk1Size);
    ui->lbl_subChunk1Size->setText(QString::fromStdString(std::string(subChunk1SizeString)));

    in >> header.audioFormat;
    std::string audioFormatString = std::to_string(header.audioFormat);
    ui->lbl_audioFormat->setText(QString::fromStdString(std::string(audioFormatString)));

    in >> header.numChannels;
    std::string numChannelsString = std::to_string(header.numChannels);
    ui->lbl_numChannels->setText(QString::fromStdString(std::string(numChannelsString)));

    in >> header.sampleRate;
    std::string sampleRateString = std::to_string(header.sampleRate);
    ui->lbl_sampleRate->setText(QString::fromStdString(std::string(sampleRateString)));

    // in >> header.byteRate;
    // std::string byteRateString = std::to_string(std::string(header.byteRate));
    // ui->lbl_byteRate->setText(QString::fromStdString(std::string(byteRateString)));

    in >> header.blockAlign;
    std::string blockAlignString = std::to_string(header.blockAlign);
    ui->lbl_blockAlign->setText(QString::fromStdString(std::string(blockAlignString)));

    in >> header.bitsPerSample;
    std::string bitsPerSampleString = std::to_string(header.bitsPerSample);
    ui->lbl_bitsPerSample->setText(QString::fromStdString(std::string(bitsPerSampleString)));

    in.readRawData(header.subchunk2ID, 4);
    QString subChunk2IDString = QString(header.subchunk2ID);
    ui->lbl_subChunk2ID->setText(subChunk2IDString.left(4));

    in >> header.subchunk2Size;
    std::string subChunk2Size = std::to_string(header.subchunk2Size);
    ui->lbl_subChunk2Size->setText(QString::fromStdString(std::string(subChunk2Size)));

    delete[] real;
    delete[] imag;
}

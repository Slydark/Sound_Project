#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , chart(new QChart())
    , series(new QLineSeries())
{
    ui->setupUi(this);
    setupChart();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupChart()
{
    chart->addSeries(series);
    chart->legend()->hide();
    chart->setTitle("DFT du fichier WAV");

    axisX = new QValueAxis;
    axisX->setTitleText("Fréquence (Hz)");
    axisX->setLabelFormat("%.1f");
    axisX->setTickCount(10);

    axisY = new QValueAxis;
    axisY->setTitleText("Amplitude");
    axisY->setLabelFormat("%.1f");
    axisY->setTickCount(0.001);

    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisX);
    series->attachAxis(axisY);

    ui->chartView->setChart(chart);
    ui->chartView->setRenderHint(QPainter::Antialiasing);

    ui->chartView->setVisible(true);
}

void MainWindow::plotDFT(const std::vector<double>& frequencies, const std::vector<double>& magnitudes)
{
    std::fstream CSVFile;
    // Open or create a new csv
    remove("CSVData.csv");
    CSVFile.open("CSVData.csv", std::ios::app);

    series->clear();
    const int maxPoints = 500;
    int step = std::max(1, static_cast<int>(frequencies.size() / maxPoints));

    for (size_t i = 0; i < frequencies.size(); i += step) {
        double magnitude = magnitudes[i] > 0 ? 20 * log10(magnitudes[i]) : 0;
        series->append(frequencies[i], magnitude);
    }

    if (!frequencies.empty() && !magnitudes.empty()) {
        axisX->setRange(0, frequencies.back());
        double maxMag = *std::max_element(magnitudes.begin(), magnitudes.end());
        axisY->setRange(0, maxMag * 1.1);
    }

    for (size_t i = 0; i < frequencies.size(); i += step) {
        // Save a CSV File
        CSVFile << frequencies[i] << ", " << magnitudes[i] << "\n";
        // qDebug() << "Frequency:" << frequencies[i] << "Magnitude:" << magnitudes[i];
    }
}

// void MainWindow::plotDFT(const std::vector<double>& frequencies, const std::vector<double>& magnitudes)
// {
//     qDebug() << "Plotting DFT...";
//     series->clear();
//     const int maxPoints = 500;
//     int step = std::max(1, static_cast<int>(frequencies.size() / maxPoints));

//     for (size_t i = 0; i < frequencies.size(); i += step) {
//         double magnitude = magnitudes[i] > 0 ? 20 * log10(magnitudes[i]) : 0;
//         series->append(frequencies[i], magnitude);
//     }

//     if (!frequencies.empty() && !magnitudes.empty()) {
//         axisX->setRange(0, frequencies.back());
//         double maxMag = *std::max_element(magnitudes.begin(), magnitudes.end());
//         axisY->setRange(0, maxMag * 1.1);
//     }

//     qDebug() << "DFT plotted successfully.";
// }

void MainWindow::on_btnLoadWav_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open WAV File"), "", tr("WAV Files (*.wav)"));
    if(filePath.isEmpty())
    {
        qDebug() << "No file selected.";
        return;
    }

    qDebug() << "Selected WAV file:" << filePath;

    const char* filePathChar = filePath.toStdString().c_str();

    WavFFT fft;
    int sampleRate, numSample;
    std::vector<double> samples = fft.readWavFile(filePathChar, sampleRate, numSample);

    int m = static_cast<int>(std::log2(numSample));
    int n = 1 << m;

    double *real = new double[n];
    double *imag = new double[n];

    fft.prepareFFTData(samples, real, imag, n);
    fft.FFT(1, m, real, imag);

    qDebug() << "FFT computed successfully.";

    std::vector<double> frequencies(n), magnitudes(n);
    for (int i = 0; i < n; ++i) {
        frequencies[i] = i * sampleRate / n;
        magnitudes[i] = std::sqrt(real[i] * real[i] + imag[i] * imag[i]);
    }

    // Convertir les tableaux en vecteurs
    std::vector<double> realVec(real, real + n);
    std::vector<double> imagVec(imag, imag + n);

    plotDFT(frequencies, magnitudes);

    delete[] real;
    delete[] imag;
}



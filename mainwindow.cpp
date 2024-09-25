#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>

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
    axisX->setTitleText("Fréquencey (Hz)");
    axisX->setLabelFormat("%.1f");
    axisX->setTickCount(10);

    axisY = new QValueAxis;
    axisY->setTitleText("Amplitude");
    axisY->setLabelFormat("%.1f");
    axisY->setTickCount(10);

    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisX);
    series->attachAxis(axisY);

    ui->chartView->setChart(chart);
    ui->chartView->setRenderHint(QPainter::Antialiasing);
}

void MainWindow::plotDFT(const std::vector<double>& frequencies, const std::vector<double>& magnitudes)
{
    series->clear();

    // Pour des raisons de performance, limiter le nombre de points affichés
    const int maxPoints = 500;
    int step = std::max(1, static_cast<int>(frequencies.size() / maxPoints));

    for (size_t i = 0; i < frequencies.size(); i += step) {
        series->append(frequencies[i], magnitudes[i]);
    }

    // Ajuster les axes
    if (!frequencies.empty() && !magnitudes.empty()) {
        axisX->setRange(0, frequencies.back());
        double maxMag = *std::max_element(magnitudes.begin(), magnitudes.end());
        axisY->setRange(0, maxMag * 1.1); // Ajouter 10% de marge
    }


    // series->clear();
    // const int maxPoints = 500;
    // int step = std::max(1, static_cast<int>(frequencies.size() / maxPoints));

    // for (size_t i = 0; i < frequencies.size(); i += step) {
    //     // Utiliser le logarithme pour améliorer la visibilité
    //     double magnitude = magnitudes[i] > 0 ? 20 * log10(magnitudes[i]) : 0;
    //     series->append(frequencies[i], magnitude);
    // }

    // // Ajuster les axes
    // if (!frequencies.empty() && !magnitudes.empty()) {
    //     axisX->setRange(0, frequencies.back());
    //     double maxMag = *std::max_element(magnitudes.begin(), magnitudes.end());
    //     axisY->setRange(0, maxMag * 1.1); // Ajouter 10% de marge
    // }

    // for (size_t i = 0; i < frequencies.size(); i += step) {
    //     qDebug() << "Frequency:" << frequencies[i] << "Magnitude:" << magnitudes[i];
    // }

}

// void MainWindow::on_btnLoadWav_clicked()
// {
//     QString filePath = QFileDialog::getOpenFileName(this, tr("Open WAV File"), "", tr("WAV Files (*.wav)"));
//     if (filePath.isEmpty()) {
//         return;
//     }

//     WavReader reader(filePath.toStdString());
//     if (!reader.read()) {
//         QMessageBox::critical(this, tr("Error"), tr("Failed to read WAV file."));
//         return;
//     }

//     //reader.displayHeaderInfo();

//     dft.computeDFT(reader.getAudioData(), reader.getHeader().sampleRate);
//     plotDFT(dft.getFrequencies(), dft.getMagnitudes());
// }

void MainWindow::on_btnLoadWav_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open WAV File"), "", tr("WAV Files (*.wav)"));
    if (filePath.isEmpty()) {
        qDebug() << "No file selected.";
        return;
    }

    qDebug() << "Selected WAV file:" << filePath;

    WavFFT fft;
    // if (!fft.computeFFT(filePath.toStdString())) {
    //     QMessageBox::critical(this, tr("Error"), tr("Failed to read WAV file or perform FFT."));
    //     return;
    // }

    qDebug() << "FFT computed successfully.";
    plotDFT(fft.getFrequencies(), fft.getMagnitudes());
}



#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts>
#include "wavreader.h"
#include "wavdft.h"
#include "wavfft.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private slots:
        void on_btnLoadWav_clicked();

    private:
        Ui::MainWindow *ui;
        WavDFT dft;
        WavFFT fft;
        QChart *chart;
        QLineSeries *series;
        QValueAxis *axisX;
        QValueAxis *axisY;

        void setupChart();
        void plotDFT(const std::vector<double>& frequencies, const std::vector<double>& magnitudes);
};
#endif // MAINWINDOW_H

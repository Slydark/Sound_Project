#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDataStream>
#include <QFile>
#include "wavreader.h"
#include "wavdft.h"
#include "wavfft.h"
#include "qcustomplot.h"
#include "wavheader.h"

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
        void loadWavFile(const QString &filePath);

    private slots:
        void on_btnLoadWav_clicked();

    private:
        Ui::MainWindow *ui;
        WavDFT dft;
        WavFFT fft;
        WavHeader header;
        void plotDFT(const std::vector<double>& frequencies, const std::vector<double>& magnitudes);
};
#endif // MAINWINDOW_H

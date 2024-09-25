#include "mainwindow.h"
#include "wavwriter.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WavWriter weavy;
    weavy.writeSineWave("sin400hz.wav", 44100, 400, 1);
    MainWindow w;
    w.show();
    return a.exec();
}

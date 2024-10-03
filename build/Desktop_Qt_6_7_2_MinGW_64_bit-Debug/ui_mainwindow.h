/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QCustomPlot *customPlot;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *btnLoadWav;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_chunk_size;
    QLabel *label_chunk_id;
    QLabel *label_format;
    QLabel *lbl_chunkId;
    QLabel *lbl_chunkSize;
    QLabel *lbl_format;
    QLabel *label;
    QLabel *lbl_subChunk1ID;
    QLabel *label_3;
    QLabel *lbl_subChunk1Size;
    QLabel *label_5;
    QLabel *lbl_audioFormat;
    QLabel *label_7;
    QLabel *lbl_numChannels;
    QLabel *label_9;
    QLabel *lbl_sampleRate;
    QLabel *label_11;
    QLabel *lbl_byteRate;
    QLabel *label_2;
    QLabel *lbl_blockAlign;
    QLabel *label_4;
    QLabel *lbl_bitsPerSample;
    QLabel *label_6;
    QLabel *lbl_subChunk2ID;
    QLabel *label_8;
    QLabel *lbl_subChunk2Size;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1003, 615);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(60, 30, 671, 471));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        customPlot = new QCustomPlot(verticalLayoutWidget);
        customPlot->setObjectName("customPlot");

        verticalLayout->addWidget(customPlot);

        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(560, 500, 172, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        btnLoadWav = new QPushButton(horizontalLayoutWidget);
        btnLoadWav->setObjectName("btnLoadWav");

        horizontalLayout->addWidget(btnLoadWav);

        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(740, 30, 251, 351));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_chunk_size = new QLabel(formLayoutWidget);
        label_chunk_size->setObjectName("label_chunk_size");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_chunk_size);

        label_chunk_id = new QLabel(formLayoutWidget);
        label_chunk_id->setObjectName("label_chunk_id");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_chunk_id);

        label_format = new QLabel(formLayoutWidget);
        label_format->setObjectName("label_format");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_format);

        lbl_chunkId = new QLabel(formLayoutWidget);
        lbl_chunkId->setObjectName("lbl_chunkId");

        formLayout->setWidget(0, QFormLayout::FieldRole, lbl_chunkId);

        lbl_chunkSize = new QLabel(formLayoutWidget);
        lbl_chunkSize->setObjectName("lbl_chunkSize");

        formLayout->setWidget(1, QFormLayout::FieldRole, lbl_chunkSize);

        lbl_format = new QLabel(formLayoutWidget);
        lbl_format->setObjectName("lbl_format");

        formLayout->setWidget(2, QFormLayout::FieldRole, lbl_format);

        label = new QLabel(formLayoutWidget);
        label->setObjectName("label");

        formLayout->setWidget(3, QFormLayout::LabelRole, label);

        lbl_subChunk1ID = new QLabel(formLayoutWidget);
        lbl_subChunk1ID->setObjectName("lbl_subChunk1ID");

        formLayout->setWidget(3, QFormLayout::FieldRole, lbl_subChunk1ID);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_3);

        lbl_subChunk1Size = new QLabel(formLayoutWidget);
        lbl_subChunk1Size->setObjectName("lbl_subChunk1Size");

        formLayout->setWidget(4, QFormLayout::FieldRole, lbl_subChunk1Size);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName("label_5");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_5);

        lbl_audioFormat = new QLabel(formLayoutWidget);
        lbl_audioFormat->setObjectName("lbl_audioFormat");

        formLayout->setWidget(5, QFormLayout::FieldRole, lbl_audioFormat);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName("label_7");

        formLayout->setWidget(6, QFormLayout::LabelRole, label_7);

        lbl_numChannels = new QLabel(formLayoutWidget);
        lbl_numChannels->setObjectName("lbl_numChannels");

        formLayout->setWidget(6, QFormLayout::FieldRole, lbl_numChannels);

        label_9 = new QLabel(formLayoutWidget);
        label_9->setObjectName("label_9");

        formLayout->setWidget(7, QFormLayout::LabelRole, label_9);

        lbl_sampleRate = new QLabel(formLayoutWidget);
        lbl_sampleRate->setObjectName("lbl_sampleRate");

        formLayout->setWidget(7, QFormLayout::FieldRole, lbl_sampleRate);

        label_11 = new QLabel(formLayoutWidget);
        label_11->setObjectName("label_11");

        formLayout->setWidget(8, QFormLayout::LabelRole, label_11);

        lbl_byteRate = new QLabel(formLayoutWidget);
        lbl_byteRate->setObjectName("lbl_byteRate");

        formLayout->setWidget(8, QFormLayout::FieldRole, lbl_byteRate);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(9, QFormLayout::LabelRole, label_2);

        lbl_blockAlign = new QLabel(formLayoutWidget);
        lbl_blockAlign->setObjectName("lbl_blockAlign");

        formLayout->setWidget(9, QFormLayout::FieldRole, lbl_blockAlign);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName("label_4");

        formLayout->setWidget(10, QFormLayout::LabelRole, label_4);

        lbl_bitsPerSample = new QLabel(formLayoutWidget);
        lbl_bitsPerSample->setObjectName("lbl_bitsPerSample");

        formLayout->setWidget(10, QFormLayout::FieldRole, lbl_bitsPerSample);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName("label_6");

        formLayout->setWidget(11, QFormLayout::LabelRole, label_6);

        lbl_subChunk2ID = new QLabel(formLayoutWidget);
        lbl_subChunk2ID->setObjectName("lbl_subChunk2ID");

        formLayout->setWidget(11, QFormLayout::FieldRole, lbl_subChunk2ID);

        label_8 = new QLabel(formLayoutWidget);
        label_8->setObjectName("label_8");

        formLayout->setWidget(12, QFormLayout::LabelRole, label_8);

        lbl_subChunk2Size = new QLabel(formLayoutWidget);
        lbl_subChunk2Size->setObjectName("lbl_subChunk2Size");

        formLayout->setWidget(12, QFormLayout::FieldRole, lbl_subChunk2Size);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1003, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Lire Audio", nullptr));
        btnLoadWav->setText(QCoreApplication::translate("MainWindow", "Ouvrir", nullptr));
        label_chunk_size->setText(QCoreApplication::translate("MainWindow", "ChunkSize : ", nullptr));
        label_chunk_id->setText(QCoreApplication::translate("MainWindow", "ChunkID : ", nullptr));
        label_format->setText(QCoreApplication::translate("MainWindow", "Format : ", nullptr));
        lbl_chunkId->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        lbl_chunkSize->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        lbl_format->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "SubChunk1ID :", nullptr));
        lbl_subChunk1ID->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "SubChunk1Size :", nullptr));
        lbl_subChunk1Size->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "AudioFormat :", nullptr));
        lbl_audioFormat->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "NumChannels :", nullptr));
        lbl_numChannels->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "SampleRate :", nullptr));
        lbl_sampleRate->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "ByteRate :", nullptr));
        lbl_byteRate->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "BlockAlign :", nullptr));
        lbl_blockAlign->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "BitsPerSample :", nullptr));
        lbl_bitsPerSample->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "SubChunk2ID :", nullptr));
        lbl_subChunk2ID->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "SubChunk2Size :", nullptr));
        lbl_subChunk2Size->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

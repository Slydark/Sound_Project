/********************************************************************************
** Form generated from reading UI file 'PlayerWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYERWINDOW_H
#define UI_PLAYERWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QSlider *slideHDuration;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnPlay;
    QPushButton *btnPause;
    QPushButton *btnStop;
    QLabel *label;
    QSlider *horizontalSlider;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(false);
        MainWindow->resize(600, 200);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        slideHDuration = new QSlider(centralwidget);
        slideHDuration->setObjectName("slideHDuration");
        slideHDuration->setGeometry(QRect(10, 20, 580, 40));
        slideHDuration->setStyleSheet(QString::fromUtf8("QSlider|::groove:horizental\n"
"{\n"
"	height : 10px;\n"
"	width : 500px;\n"
"	background : red;\n"
"	border-radius : 10px;\n"
"}\n"
"\n"
"Qslider::handle:horizental\n"
"{\n"
"	background : rgb(52, 50, 64);\n"
"	width : 20px;\n"
"	height : 20px;\n"
"}\n"
""));
        slideHDuration->setOrientation(Qt::Orientation::Horizontal);
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(20, 70, 256, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnPlay = new QPushButton(horizontalLayoutWidget);
        btnPlay->setObjectName("btnPlay");
        QIcon icon;
        icon.addFile(QString::fromUtf8("Play_logo.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnPlay->setIcon(icon);

        horizontalLayout->addWidget(btnPlay);

        btnPause = new QPushButton(horizontalLayoutWidget);
        btnPause->setObjectName("btnPause");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("Pause_logo.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnPause->setIcon(icon1);

        horizontalLayout->addWidget(btnPause);

        btnStop = new QPushButton(horizontalLayoutWidget);
        btnStop->setObjectName("btnStop");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("Stop_logo.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnStop->setIcon(icon2);

        horizontalLayout->addWidget(btnStop);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(290, 60, 63, 20));
        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(290, 100, 301, 18));
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 600, 25));
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
        btnPlay->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
        btnPause->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        btnStop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Volume :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYERWINDOW_H

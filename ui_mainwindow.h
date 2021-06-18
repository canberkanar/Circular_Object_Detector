/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton_Pause;
    QLabel *lblOriginalImage;
    QLabel *lblProcessedImage;
    QPlainTextEdit *txtXYRadius;
    QPushButton *pushButton_Exit;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1281, 667);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton_Pause = new QPushButton(centralWidget);
        pushButton_Pause->setObjectName(QStringLiteral("pushButton_Pause"));
        pushButton_Pause->setGeometry(QRect(10, 510, 281, 131));
        lblOriginalImage = new QLabel(centralWidget);
        lblOriginalImage->setObjectName(QStringLiteral("lblOriginalImage"));
        lblOriginalImage->setGeometry(QRect(0, 20, 640, 480));
        lblOriginalImage->setAutoFillBackground(true);
        lblProcessedImage = new QLabel(centralWidget);
        lblProcessedImage->setObjectName(QStringLiteral("lblProcessedImage"));
        lblProcessedImage->setGeometry(QRect(640, 20, 640, 480));
        lblProcessedImage->setAutoFillBackground(true);
        lblProcessedImage->setFrameShape(QFrame::NoFrame);
        txtXYRadius = new QPlainTextEdit(centralWidget);
        txtXYRadius->setObjectName(QStringLiteral("txtXYRadius"));
        txtXYRadius->setGeometry(QRect(300, 510, 681, 130));
        txtXYRadius->setReadOnly(true);
        pushButton_Exit = new QPushButton(centralWidget);
        pushButton_Exit->setObjectName(QStringLiteral("pushButton_Exit"));
        pushButton_Exit->setGeometry(QRect(990, 510, 281, 131));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1281, 25));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButton_Pause->setText(QApplication::translate("MainWindow", "Pause", 0));
        lblOriginalImage->setText(QString());
        lblProcessedImage->setText(QString());
        pushButton_Exit->setText(QApplication::translate("MainWindow", "Exit", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

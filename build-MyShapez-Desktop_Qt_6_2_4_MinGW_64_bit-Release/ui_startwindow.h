/********************************************************************************
** Form generated from reading UI file 'startwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTWINDOW_H
#define UI_STARTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_startWindow
{
public:
    QPushButton *Start;
    QPushButton *ReadGame;
    QPushButton *Exit;
    QPushButton *Shop;

    void setupUi(QWidget *startWindow)
    {
        if (startWindow->objectName().isEmpty())
            startWindow->setObjectName(QString::fromUtf8("startWindow"));
        startWindow->resize(800, 600);
        Start = new QPushButton(startWindow);
        Start->setObjectName(QString::fromUtf8("Start"));
        Start->setGeometry(QRect(40, 120, 101, 31));
        ReadGame = new QPushButton(startWindow);
        ReadGame->setObjectName(QString::fromUtf8("ReadGame"));
        ReadGame->setGeometry(QRect(40, 160, 101, 31));
        Exit = new QPushButton(startWindow);
        Exit->setObjectName(QString::fromUtf8("Exit"));
        Exit->setGeometry(QRect(40, 240, 101, 31));
        Shop = new QPushButton(startWindow);
        Shop->setObjectName(QString::fromUtf8("Shop"));
        Shop->setGeometry(QRect(40, 200, 101, 31));

        retranslateUi(startWindow);

        QMetaObject::connectSlotsByName(startWindow);
    } // setupUi

    void retranslateUi(QWidget *startWindow)
    {
        startWindow->setWindowTitle(QCoreApplication::translate("startWindow", "startWindow", nullptr));
        Start->setText(QCoreApplication::translate("startWindow", "\345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
        ReadGame->setText(QCoreApplication::translate("startWindow", "\350\257\273\346\241\243", nullptr));
        Exit->setText(QCoreApplication::translate("startWindow", "\351\200\200\345\207\272", nullptr));
        Shop->setText(QCoreApplication::translate("startWindow", "\345\225\206\345\272\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class startWindow: public Ui_startWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H

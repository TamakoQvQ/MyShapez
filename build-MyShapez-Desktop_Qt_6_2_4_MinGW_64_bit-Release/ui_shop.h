/********************************************************************************
** Form generated from reading UI file 'shop.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOP_H
#define UI_SHOP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Shop
{
public:
    QPushButton *pushButton1;
    QPushButton *pushButton2;
    QPushButton *pushButton;

    void setupUi(QWidget *Shop)
    {
        if (Shop->objectName().isEmpty())
            Shop->setObjectName(QString::fromUtf8("Shop"));
        Shop->resize(400, 300);
        pushButton1 = new QPushButton(Shop);
        pushButton1->setObjectName(QString::fromUtf8("pushButton1"));
        pushButton1->setGeometry(QRect(10, 50, 221, 31));
        pushButton2 = new QPushButton(Shop);
        pushButton2->setObjectName(QString::fromUtf8("pushButton2"));
        pushButton2->setGeometry(QRect(10, 90, 221, 31));
        pushButton = new QPushButton(Shop);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 130, 221, 31));

        retranslateUi(Shop);

        QMetaObject::connectSlotsByName(Shop);
    } // setupUi

    void retranslateUi(QWidget *Shop)
    {
        Shop->setWindowTitle(QCoreApplication::translate("Shop", "Form", nullptr));
        pushButton1->setText(QCoreApplication::translate("Shop", "\350\212\261\350\264\27110\351\207\221\345\270\201\345\215\207\347\272\247\344\272\244\344\273\230\344\270\255\345\277\203\345\244\247\345\260\217", nullptr));
        pushButton2->setText(QCoreApplication::translate("Shop", "\350\212\261\350\264\27115\351\207\221\345\270\201\345\215\207\347\272\247\345\274\200\351\207\207\347\211\251\347\232\204\346\225\260\351\207\217", nullptr));
        pushButton->setText(QCoreApplication::translate("Shop", "\350\212\261\350\264\27120\351\207\221\345\270\201\345\215\207\347\272\247\346\257\217\346\254\241\345\276\227\345\210\260\347\232\204\351\207\221\345\270\201\346\225\260\351\207\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Shop: public Ui_Shop {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOP_H

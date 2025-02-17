#ifndef SHOP_H
#define SHOP_H

#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QTimer>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class Shop;
}

class Shop : public QWidget
{
    Q_OBJECT

public:
    explicit Shop(QWidget *parent = nullptr);
    ~Shop();
    void paintEvent(QPaintEvent *event);

private slots:
    void on_pushButton1_clicked();

    void on_pushButton2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Shop *ui;
};

#endif // SHOP_H

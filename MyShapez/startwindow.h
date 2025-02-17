#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QWidget>
#include <QTextStream>

#include "shop.h"

QT_BEGIN_NAMESPACE
namespace Ui { class startWindow; }
QT_END_NAMESPACE

class startWindow : public QWidget
{
    Q_OBJECT

private slots:

    //开始游戏
    void on_Start_clicked();
    //退出游戏
    void on_Exit_clicked();
    //打开商店
    void on_Shop_clicked();
    //存档
    void on_ReadGame_clicked();

public:
    startWindow(QWidget *parent = nullptr);
    ~startWindow();
    void paintEvent(QPaintEvent *event);

private:
    Ui::startWindow *ui;
};
#endif // STARTWINDOW_H

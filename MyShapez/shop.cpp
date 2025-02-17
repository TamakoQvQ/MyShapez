#include "shop.h"
#include "ui_shop.h"

#include "map.h"
#include "deliverycenter.h"

Shop::Shop(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Shop)
{
    ui->setupUi(this);
    setWindowTitle("商店");
    setFixedSize(500,240);
}

Shop::~Shop()
{
    delete ui;
}

void Shop::paintEvent(QPaintEvent * event)
{
    QPainter painter(this);
    painter.drawPixmap(rect(),QPixmap(":/main/Picture/shop_background.jpg"),QRect());
    QFont font;
    font.setPointSize(12);
    painter.setFont(font);
    painter.drawText(10, 20, "金币：" + QString::number(Map::coinsTotal));
}

void Shop::on_pushButton1_clicked()
{
    if(DeliveryCenter::DCsize == 4)
    {
        QMessageBox::information(NULL, " ", "已经升过级了", QMessageBox::Yes, QMessageBox::Yes);
    }
    else if(Map::coinsTotal < 10)
        QMessageBox::information(NULL, "糟糕", "金币不足，不可以升级（> <）", QMessageBox::Yes, QMessageBox::Yes);
    else{
        Map::coinsTotal -= 10;
        DeliveryCenter::DCsize = 4;
        QMessageBox::information(NULL, "你被强化了", "现在的交付中心大小是 4！（OvO）", QMessageBox::Yes, QMessageBox::Yes);
    }
    //qDebug()<<"money"<<Map::coinsTotal;
}


void Shop::on_pushButton2_clicked()
{
    if(Map::MinerralUP)
    {
        QMessageBox::information(NULL, " ", "已经升过级了", QMessageBox::Yes, QMessageBox::Yes);
    }
    else if(Map::coinsTotal < 15)
        QMessageBox::information(NULL, "糟糕", "金币不足，不可以升级（> <）", QMessageBox::Yes, QMessageBox::Yes);
    else{
        Map::coinsTotal -= 15;
        Map::MinerralUP = true;
        QMessageBox::information(NULL, "你被强化了", "开采物的数量增加了！重启游戏生效（OvO）", QMessageBox::Yes, QMessageBox::Yes);
    }
}


void Shop::on_pushButton_clicked()
{
    if(Map::CoinUP)
    {
        QMessageBox::information(NULL, " ", "已经升过级了", QMessageBox::Yes, QMessageBox::Yes);
    }
    else if(Map::coinsTotal < 20)
        QMessageBox::information(NULL, "糟糕", "金币不足，不可以升级（> <）", QMessageBox::Yes, QMessageBox::Yes);
    else{
        Map::coinsTotal -= 20;
        Map::coinPerTime = 5;
        Map::CoinUP = true;
        QMessageBox::information(NULL, "你被强化了", "现在你一次可以获得 5 个金币！（OvO）", QMessageBox::Yes, QMessageBox::Yes);
    }
}


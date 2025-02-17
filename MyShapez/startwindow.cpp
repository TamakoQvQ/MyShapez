#include "startwindow.h"
#include "ui_startwindow.h"
#include "gamewindow.h"

startWindow::startWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::startWindow)
{
    ui->setupUi(this);
    setWindowTitle("MyShapez");
    setFixedSize(500,400);

}

startWindow::~startWindow()
{
    delete ui;
}

void startWindow::paintEvent(QPaintEvent * event)
{
    QPainter painter(this);
    painter.drawPixmap(rect(),QPixmap(":/main/Picture/start_background.jpg"),QRect());
}

void startWindow::on_Start_clicked()
{
    gameWindow* gamewindow = new gameWindow();
    gamewindow->show();
}


void startWindow::on_Exit_clicked()
{
    this->close();
}


void startWindow::on_Shop_clicked()
{
    Shop *shop = new Shop;
    shop->show();
}


void startWindow::on_ReadGame_clicked()
{
    QString helper;
    QFile data("D:\\MyGame.txt");
    if (data.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QTextStream out(&data);
        helper = out.readLine();
        Map::MinerralUP = helper.toInt();
        helper = out.readLine();
        Map::CoinUP = helper.toInt();
        helper = out.readLine();
        Map::coinsTotal = helper.toInt();
        helper = out.readLine();
        DeliveryCenter::DCsize = helper.toInt();
        helper = out.readLine();
        Map::coinPerTime = helper.toInt();
        helper = out.readLine();
        Map::MinergoodsCreateTime = helper.toInt();
        helper = out.readLine();
        Map::CuttergoodsCreateTime = helper.toInt();
        helper = out.readLine();
        Map::speedBelt = helper.toInt();
        helper = out.readLine();
        BuildingCards::blueTotal = helper.toInt();
        helper = out.readLine();
        BuildingCards::redTotal = helper.toInt();
        helper = out.readLine();
        BuildingCards::blueLeftTotal = helper.toInt();
        helper = out.readLine();
        BuildingCards::blueRightTotal = helper.toInt();
        helper = out.readLine();
        qDebug()<<"读档成功";
        gameWindow* gamewindow = new gameWindow();
        gamewindow->show();
    }
    else
        qDebug()<<"读档失败";
    data.close();
}


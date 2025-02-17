#include "deliverycenter.h"
#include "map.h"

int DeliveryCenter::DCsize = 3;

DeliveryCenter::DeliveryCenter()
{
    //设置在场景中的起始坐标
    setPos(DCpos * blockSize, DCpos * blockSize);
    //设置显示优先级（10 只要保证最高）
    setZValue(10);
}

DeliveryCenter::~DeliveryCenter()
{

}

//记录交付中心大小的矩形
QRectF DeliveryCenter::boundingRect() const
{
    return QRectF(0, 0, blockSize*DCsize, blockSize*DCsize);
}

void DeliveryCenter::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QImage image(":/main/Picture/delivery_center.png");
    painter->drawImage(boundingRect(), image);
    //显示金币
    QFont font;
    font.setPointSize(10);
    painter->setFont(font);
    painter->drawText(55, 65, QString::number(Map::coinsTotal));
}

void DeliveryCenter::advance(int phase)
{
    if(!phase)
        return;
    update();
}



#include "bluemineral.h"

BlueMineral::BlueMineral(int x, int y):Mineral::Mineral(x,y)
{
    //设置初始属性
    value = 5;
    type = 0;
    canCut = true;
}

BlueMineral::~BlueMineral()
{

}

QRectF BlueMineral::boundingRect() const
{
    return QRectF(0, 0, blockSize, blockSize);
}


void BlueMineral::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QImage image(":/main/Picture/blue_mineral.png");
    painter->drawImage(boundingRect(), image);
}


#include "redmineral.h"

RedMineral::RedMineral(int x, int y):Mineral::Mineral(x,y)
{
    //设置初始属性
    value = 5;
    type = 1;
    canCut = false;
}

RedMineral::~RedMineral()
{

}

QRectF RedMineral::boundingRect() const
{
    return QRectF(0, 0, blockSize, blockSize);
}


void RedMineral::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QImage image(":/main/Picture/red_mineral.png");
    painter->drawImage(boundingRect(), image);
}


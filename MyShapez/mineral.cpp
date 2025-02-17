#include "mineral.h"

Mineral::Mineral(int x,int y)
{
    //设置在场景中的起始坐标
    xPos = x;
    yPos = y;
    setPos(xPos * blockSize, yPos * blockSize);
}

Mineral::~Mineral()
{

}

QRectF Mineral::boundingRect() const
{
    return QRectF(0, 0, blockSize, blockSize);
}


#include "rotater.h"

Rotater::Rotater(QPointF point, const int _direction)
{
    speed = 1;
    goodsCounter = 0;
    goodsCreateTime = 200;
    direction = _direction;
    goodsReceived = false;
    isWorking = true;
    name = "Rotater";
    xPos = point.x();
    yPos = point.y();
    setPos(xPos, yPos);
    setZValue(3);

}

Rotater::~Rotater()
{
    Map::BuildingMap[xPos / 40][yPos / 40] = nullptr;
}

void Rotater::advance(int phase)
{
    if(!phase)
        return;
    update();
    if(goodsReceived && isWorking)
    {
        if(goodsCounter < goodsCreateTime) //没到产出时间
            ++goodsCounter;
        if(goodsCounter == goodsCreateTime) //到时间
        {
            switch (direction) {
            case 0:
                goods = new Goods(QPointF(xPos, yPos - 21), 2);
                scene()->addItem(goods);
                goodsCounter = 0;
                goodsReceived = false;
                break;
            case 1:
                goods = new Goods(QPointF(xPos + 21, yPos), 2);
                scene()->addItem(goods);
                goodsCounter = 0;
                goodsReceived = false;
                break;
            case 2:
                goods = new Goods(QPointF(xPos, yPos + 21), 2);
                scene()->addItem(goods);
                goodsCounter = 0;
                goodsReceived = false;
                break;
            case 3:
                goods = new Goods(QPointF(xPos - 21, yPos), 3);
                scene()->addItem(goods);
                scene()->addItem(goods);
                goodsCounter = 0;
                goodsReceived = false;
                break;
            default:
                break;
            }
        }
    }
}

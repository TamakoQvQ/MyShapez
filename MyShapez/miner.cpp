#include "miner.h"

Miner::Miner(QPointF point, const int _direction, int _goodsCreateTime)
{
    speed = 1;
    goodsType = 0;
    goodsCounter = 0;
    goodsCreateTime = _goodsCreateTime;
    direction = _direction;
    isWorking = false;
    name = "Miner";
    xPos = point.x();
    yPos = point.y();
    setPos(xPos, yPos);
    setZValue(3);
    //若矿物地图当前位置不为空，说明开采器在矿物上
    if(Map::MineralMap[xPos / 40][yPos / 40]){
        //是红色矿物会改变类型
        if(Map::MineralMap[xPos / 40][yPos / 40]->type == 1)
            goodsType = 1;
        qDebug()<<"Miner is working.";
        isWorking = true;
    }
}

Miner::~Miner()
{
    Map::BuildingMap[xPos / 40][yPos / 40] = nullptr;
}

void Miner::advance(int phase)
{
    if(!phase)
        return;
    update();
    if(isWorking)
    {
        if(goodsCounter < goodsCreateTime) //没到产出时间
            ++goodsCounter;
        if(goodsCounter == goodsCreateTime) //到时间
        {
            goods = new Goods(QPointF(xPos, yPos), goodsType);
            scene()->addItem(goods);
            goodsCounter = 0;
        }
    }
}

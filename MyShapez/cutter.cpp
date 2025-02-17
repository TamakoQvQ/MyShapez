#include "cutter.h"

Cutter::Cutter(QPointF point, const int _direction, int _goodsCreateTime)
{
    speed = 1;
    goodsCounter = 0;
    goodsCreateTime = _goodsCreateTime;
    goodsReceived = false;
    direction = _direction;
    isWorking = false;
    name = "Cutter";
    xPos = point.x();
    yPos = point.y();
    setPos(xPos, yPos);
    setZValue(3);
}

Cutter::~Cutter()
{
    Map::BuildingMap[xPos / 40][yPos / 40] = nullptr;
}

void Cutter::advance(int phase)
{
    if(!phase)
        return;
    update();

    //切割机判断是否工作的条件有点复杂
    int i = xPos / 40;
    int j = yPos / 40;
    switch (direction) {
    case 0:
        if(Map::BuildingMap[i][j - 1] && Map::BuildingMap[i + 1][j - 1])
        {
            //左边必须是传送带
            //右边必须是传送带或者垃圾桶
            if((Map::BuildingMap[i][j - 1]->name == "Belt"|| Map::BuildingMap[i][j - 1]->name == "Belt_turn") &&
                (Map::BuildingMap[i + 1][j - 1]->name == "Trash" || Map::BuildingMap[i + 1][j - 1]->name == "Belt" || Map::BuildingMap[i + 1][j - 1]->name == "Belt_turn"))
            {
                //qDebug()<<"Cutter is working.";
                isWorking = true;
            }
        }
        break;
    case 1:
        if(Map::BuildingMap[i + 1][j] && Map::BuildingMap[i + 1][j + 1])
        {
            //左边必须是传送带
            //右边必须是传送带或者垃圾桶
            if((Map::BuildingMap[i + 1][j]->name == "Belt"|| Map::BuildingMap[i + 1][j]->name == "Belt_turn") &&
                (Map::BuildingMap[i + 1][j + 1]->name == "Trash" || Map::BuildingMap[i + 1][j + 1]->name == "Belt" || Map::BuildingMap[i + 1][j + 1]->name == "Belt_turn"))
            {
                //qDebug()<<"Cutter is working.";
                isWorking = true;
            }
        }
        break;
    //注意实际判定点
    case 2:
        if(Map::BuildingMap[i + 1][j + 1] && Map::BuildingMap[i][j + 1])
        {
            //左边必须是传送带
            //右边必须是传送带或者垃圾桶
            if((Map::BuildingMap[i + 1][j + 1]->name == "Belt"|| Map::BuildingMap[i + 1][j + 1]->name == "Belt_turn") &&
                (Map::BuildingMap[i][j + 1]->name == "Trash" || Map::BuildingMap[i][j + 1]->name == "Belt" || Map::BuildingMap[i][j + 1]->name == "Belt_turn"))
            {
                //qDebug()<<"Cutter is working.";
                isWorking = true;
            }
        }
        break;
    case 3:
        if(Map::BuildingMap[i - 1][j + 1] && Map::BuildingMap[i - 1][j])
        {
            //左边必须是传送带
            //右边必须是传送带或者垃圾桶
            if((Map::BuildingMap[i - 1][j + 1]->name == "Belt"|| Map::BuildingMap[i - 1][j + 1]->name == "Belt_turn") &&
                (Map::BuildingMap[i - 1][j]->name == "Trash" || Map::BuildingMap[i - 1][j]->name == "Belt" || Map::BuildingMap[i - 1][j]->name == "Belt_turn"))
            {
                //qDebug()<<"Cutter is working.";
                isWorking = true;
            }
        }
        break;
    default:
        isWorking = false;
        break;
    }
    if(goodsReceived && isWorking)
    {
        if(goodsCounter < goodsCreateTime) //没到产出时间
            ++goodsCounter;
        if(goodsCounter == goodsCreateTime) //到时间
        {
            switch (direction) {
            case 0:
                leftGoods = new Goods(QPointF(xPos, yPos - 21), 2);
                rightGoods = new Goods(QPointF(xPos + 40, yPos - 21), 3);
                scene()->addItem(leftGoods);
                scene()->addItem(rightGoods);
                goodsCounter = 0;
                goodsReceived = false;
                break;
            case 1:
                leftGoods = new Goods(QPointF(xPos + 21, yPos), 2);
                rightGoods = new Goods(QPointF(xPos + 21, yPos + 40), 3);
                scene()->addItem(leftGoods);
                scene()->addItem(rightGoods);
                goodsCounter = 0;
                goodsReceived = false;
                break;
            case 2:
                leftGoods = new Goods(QPointF(xPos + 40, yPos + 21), 2);
                rightGoods = new Goods(QPointF(xPos, yPos + 21), 3);
                scene()->addItem(leftGoods);
                scene()->addItem(rightGoods);
                goodsCounter = 0;
                goodsReceived = false;
                break;
            case 3:
                leftGoods = new Goods(QPointF(xPos - 21, yPos + 40), 2);
                rightGoods = new Goods(QPointF(xPos - 21, yPos), 3);
                scene()->addItem(leftGoods);
                scene()->addItem(rightGoods);
                goodsCounter = 0;
                goodsReceived = false;
                break;
            default:
                break;
            }
        }
    }
}

QRectF Cutter::boundingRect() const
{
    //朝上或朝下 方向为0或2
    if(direction % 2 == 0){
        return QRectF(0, 0, blockSize * 2, blockSize);
    }
    //朝左或朝右
    else {
        return QRectF(0, 0, blockSize, blockSize * 2);
    }
}

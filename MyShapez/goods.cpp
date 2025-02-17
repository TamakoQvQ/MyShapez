#include "goods.h"
#include "map.h"
#include "deliverycenter.h"
#include "gamewindow.h"

Goods::Goods(QPointF point, int _type)
{
    type = _type;
    speed = 5;
    xPos = point.x();
    yPos = point.y();
    setPos(xPos, yPos);
    setZValue(2);

}

Goods::~Goods()
{

}

QRectF Goods::boundingRect() const
{
    return QRectF(5, 5, 30, 30);
}

void Goods::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    switch (type) {
    case 0:
        painter->drawImage(boundingRect(), QImage(":/main/Picture/Goods/Blue.png"));
        break;
    case 1:
        painter->drawImage(boundingRect(), QImage(":/main/Picture/Goods/Red.png"));
        break;
    case 2:
        painter->drawImage(boundingRect(), QImage(":/main/Picture/Goods/BlueLeft.png"));
        break;
    case 3:
        painter->drawImage(boundingRect(), QImage(":/main/Picture/Goods/BlueRight.png"));
        break;
    default:
        break;
    }
}

void Goods::advance(int phase)
{
    if(!phase)
        return;
    update();

    //检查生成地的数组是什么类型的（处在什么建筑上方）
    int i = (x() + 20)/40;
    int j = (y() + 20)/40;

    //碰到交付中心完成传送 交付中心左上角坐标 10 10
    if(i >= 10 && i < 10 + DeliveryCenter::DCsize && j >= 10 && j < 10 + DeliveryCenter::DCsize)
    {
        //qDebug()<<"完成传送";
        switch (type) {
        case 0:
            if(BuildingCards::blueTotal < 20)
            {
                BuildingCards::blueTotal += 1;
            }
            Map::coinsTotal += Map::coinPerTime;
            break;
        case 1:
            if(BuildingCards::redTotal < 30)
            {
                BuildingCards::redTotal += 1;
            }
            Map::coinsTotal += Map::coinPerTime;
            break;
        case 2:
            if(BuildingCards::blueLeftTotal < 50)
            {
                BuildingCards::blueLeftTotal += 1;
            }
            Map::coinsTotal += Map::coinPerTime;
            break;
        case 3:
            if(BuildingCards::blueRightTotal < 50)
            {
                BuildingCards::blueRightTotal += 1;
            }
            Map::coinsTotal += Map::coinPerTime;
            break;
        default:
            break;
        }
        delete this;
        return;
    }

    //上边是切割机（另一种判断条件）且当前货物类型为0
    if(Map::BuildingMap[i][j - 1] && Map::BuildingMap[i][j - 1]->name == "Cutter" && type == 0)
    {
        Map::BuildingMap[i][j - 1]->goodsReceived = true;
        delete this;
        return;
    }
    //左边是切割机（另一种判断条件）且当前货物类型为0
    else if(Map::BuildingMap[i - 1][j] && Map::BuildingMap[i - 1][j]->name == "Cutter" && type == 0)
    {
        Map::BuildingMap[i - 1][j]->goodsReceived = true;
        delete this;
        return;
    }
    //无建筑
    if(Map::BuildingMap[i][j] == nullptr)
    {
        delete this;
        return;
    }
    //是切割机且当前货物类型为0
    if(Map::BuildingMap[i][j]->name == "Cutter" && type == 0)
    {
        Map::BuildingMap[i][j]->goodsReceived = true;
        delete this;
        return;
    }
    //是旋转器且当前货物类型为3
    if(Map::BuildingMap[i][j]->name == "Rotater" && type == 3)
    {
        Map::BuildingMap[i][j]->goodsReceived = true;
        delete this;
        return;
    }
    //下方是开采器或直传送带的方向
    else if(Map::BuildingMap[i][j]->name == "Miner" || Map::BuildingMap[i][j]->name == "Belt")
    {
        //看方向
        switch(Map::BuildingMap[i][j]->direction)
        {
        case 0:
            setY(y() - Map::BuildingMap[i][j]->speed);
            break;
        case 1:
            setX(x() + Map::BuildingMap[i][j]->speed);
            break;
        case 2:
            setY(y() + Map::BuildingMap[i][j]->speed);
            break;
        case 3:
            setX(x() - Map::BuildingMap[i][j]->speed);
            break;
        default:
            break;
        }
    }
    //是转弯传送带
    else if(Map::BuildingMap[i][j]->name == "Belt_turn")
    {
        //看方向
        switch(Map::BuildingMap[i][j]->direction)
        {
        case 0:
            //看它左边的传送带是什么方向
            if(Map::BuildingMap[i - 1][j] && Map::BuildingMap[i - 1][j]->direction == 1)
            {
                setX(x() + Map::BuildingMap[i][j]->speed);
                setY(y() + Map::BuildingMap[i][j]->speed);
                break;
            }
            //看它下边的传送带是什么方向
            else if(Map::BuildingMap[i][j + 1] && Map::BuildingMap[i][j + 1]->direction == 0)
            {
                setX(x() - Map::BuildingMap[i][j]->speed);
                setY(y() - Map::BuildingMap[i][j]->speed);
                break;
            }
        case 1:
            //看它左边的传送带是什么方向
            if(Map::BuildingMap[i - 1][j] && Map::BuildingMap[i - 1][j]->direction == 1)
            {
                setX(x() + Map::BuildingMap[i][j]->speed);
                setY(y() - Map::BuildingMap[i][j]->speed);
                break;
            }
            //看它上边的传送带是什么方向
            else if(Map::BuildingMap[i][j - 1] && Map::BuildingMap[i][j - 1]->direction == 2)
            {
                setX(x() - Map::BuildingMap[i][j]->speed);
                setY(y() + Map::BuildingMap[i][j]->speed);
                break;
            }
        case 2:
            //看它右边的传送带是什么方向
            if(Map::BuildingMap[i + 1][j] && Map::BuildingMap[i + 1][j]->direction == 3)
            {
                setX(x() - Map::BuildingMap[i][j]->speed);
                setY(y() - Map::BuildingMap[i][j]->speed);
                break;
            }
            //看它上边的传送带是什么方向
            else if(Map::BuildingMap[i][j - 1] && Map::BuildingMap[i][j - 1]->direction == 2)
            {
                setX(x() + Map::BuildingMap[i][j]->speed);
                setY(y() + Map::BuildingMap[i][j]->speed);
                break;
            }
        case 3:
            //看它右边的传送带是什么方向
            if(Map::BuildingMap[i + 1][j] && Map::BuildingMap[i + 1][j]->direction == 3)
            {
                setX(x() - Map::BuildingMap[i][j]->speed);
                setY(y() + Map::BuildingMap[i][j]->speed);
                break;
            }
            //看它下边的传送带是什么方向
            else if(Map::BuildingMap[i][j + 1] && Map::BuildingMap[i][j + 1]->direction == 0)
            {
                setX(x() + Map::BuildingMap[i][j]->speed);
                setY(y() - Map::BuildingMap[i][j]->speed);
                break;
            }
        default:
            break;
        }
    }

}

bool Goods::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode);
    Q_UNUSED(other);
    return false;
}


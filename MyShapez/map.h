#ifndef MAP_H
#define MAP_H

#include <QGraphicsItem>
#include <QPainter>
#include <QWidget>
#include <QMouseEvent>
#include <QDebug>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QVector>
#include <QPair>

#include "mineral.h"
#include "bluemineral.h"
#include "redmineral.h"
#include "buildingcards.h"
#include "building.h"
#include "miner.h"
#include "belt.h"
#include "belt_turn.h"
#include "cutter.h"
#include "trash.h"
#include "rotater.h"

class Map: public QGraphicsItem
{
public:
    Map();
    ~Map();

    //记录玩家点击了哪张卡牌
    static BuildingCards *PreparedBuilding;
    //记录玩家点击卡牌的方向
    static int PreparedBuildingDirection;
    //储存所有建筑
    static Building *BuildingMap[100][100];
    //储存所有开采物
    static Mineral *MineralMap[100][100];
    //记录开采物数量是否强化过
    static bool MinerralUP;
    //记录金币是否强化过
    static bool CoinUP;
    //记录鼠标是否被按下
    static bool mousePress;
    //金币总量
    static int coinsTotal;
    //交付一次货物得到的金币
    static int coinPerTime;
    //开采器速率（体现在产生货物时间）
    static int MinergoodsCreateTime;
    //切割机速率（体现在产生货物时间）
    static int CuttergoodsCreateTime;
    //传送带速率
    static int speedBelt;
    //记录已完成任务数
    static int taskDown;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int phase);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

private:
    const int blockSize = 40;//每个地块大小，为40，共100*100
};

#endif // MAP_H

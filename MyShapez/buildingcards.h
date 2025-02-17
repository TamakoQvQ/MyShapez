#ifndef BUILDINGCARDS_H
#define BUILDINGCARDS_H

//设备卡类 在选择框显示

#include <QGraphicsItem>
#include <QRect>
#include <QBrush>
#include <QPainter>
#include <QCursor>
#include <QMouseEvent>
#include <QDebug>
#include <QLabel>
#include <QApplication>
#include <QGraphicsSceneMouseEvent>
#include <QPixmap>
#include <QTransform>

class BuildingCards : public QGraphicsItem
{
public:
    int No;//编号
    QString name;

    //记录4种物品总量
    static int blueTotal;
    static int redTotal;
    static int blueLeftTotal;
    static int blueRightTotal;

    BuildingCards();
    ~BuildingCards();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void advance(int phase);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

protected:
    QString tip;
};

class miner : public BuildingCards
{
public:
    miner();
};

class belt : public BuildingCards
{
public:
    belt();
};

class belt_turn : public BuildingCards
{
public:
    belt_turn();
};

class cutter : public BuildingCards
{
public:
    cutter();
};

class trash : public BuildingCards
{
public:
    trash();
};

class rotater : public BuildingCards
{
public:
    rotater();
};

#endif // BUILDINGCARDS_H

#ifndef MINERAL_H
#define MINERAL_H

//总开采物类

#include <QGraphicsItem>
#include <QPainter>
#include <QDebug>

class Mineral:public QGraphicsItem
{
public:
    int value;//价值
    int type;//类型 0为蓝可切割 1为红不可切割
    bool canCut;//是否可以切割

    Mineral(int x, int y);
    ~Mineral();
    QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) = 0;

protected:
    const int blockSize = 40;//每个地块大小，为40
    int xPos;//横坐标
    int yPos;//纵坐标

};

#endif // MINERAL_H



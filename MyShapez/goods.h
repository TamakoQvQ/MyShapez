#ifndef GOODS_H
#define GOODS_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPointF>
#include <QDebug>
#include <QTime>

#include "deliverycenter.h"

//运送的货物类

class Goods : public QGraphicsItem
{
public:
    Goods(QPointF point, int _type);
    ~Goods();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int phase);
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const;

private:
    int xPos;//横坐标
    int yPos;//纵坐标
    int speed;
    //类型 0为蓝可切割 1为红不可切割
    int type;
};

#endif // GOODS_H

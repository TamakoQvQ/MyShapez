#ifndef DELIVERYCENTER_H
#define DELIVERYCENTER_H

#include <QGraphicsItem>
#include <QPainter>
#include <QDebug>

class DeliveryCenter:public QGraphicsItem
{
public:
    DeliveryCenter();
    ~DeliveryCenter();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int phase);

    const int blockSize = 40;//每个地块大小，为40，共100*100
    const static int DCpos = 10;//交付中心起始坐标，固定（xy一样）
    static int DCsize;//交付中心占的方格数，初始为3
};

#endif // DELIVERYCENTER_H

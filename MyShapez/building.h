#ifndef BUILDING_H
#define BUILDING_H

//总设备类

#include <QGraphicsView>
#include <QGraphicsItem>
#include <QPainter>
#include <QMovie>
#include <QMouseEvent>
#include <QDebug>
#include <QRectF>

class Building : public QGraphicsItem
{
public:
    QString name;//设备名
    int speed;//速度
    int direction;//四个方向
    bool isWorking;//是否在工作
    bool goodsReceived;//用于切割机和旋转器判断
    Building();
    ~Building();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int phase);

protected:
    const int blockSize = 40;//每个地块大小，为40
    int xPos, yPos;//坐标

};

#endif // BUILDING_H

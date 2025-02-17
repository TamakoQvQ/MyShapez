#ifndef BLUEMINERAL_H
#define BLUEMINERAL_H

//蓝色开采物 可以被切割 类型为0

#include "mineral.h"

class BlueMineral : public Mineral
{
public:
    BlueMineral(int x, int y);
    ~BlueMineral();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // BLUEMINERAL_H

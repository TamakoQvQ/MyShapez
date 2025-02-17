#ifndef REDMINERAL_H
#define REDMINERAL_H

//红色开采物 不可被切割 类型为1

#include "mineral.h"

class RedMineral : public Mineral
{
public:
    RedMineral(int x, int y);
    ~RedMineral();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // REDMINERAL_H

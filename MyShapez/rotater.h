#ifndef ROTATER_H
#define ROTATER_H

//旋转器类

#include "map.h"
#include "building.h"

class Rotater : public Building
{
public:
    Rotater(QPointF point, const int _direction);
    ~Rotater();
    void advance(int phase);

private:
    Goods *goods;
    int goodsCounter, goodsCreateTime;
};

#endif // ROTATER_H

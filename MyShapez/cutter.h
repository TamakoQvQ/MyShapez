#ifndef CUTTER_H
#define CUTTER_H

//切割机类

#include "map.h"
#include "building.h"

class Cutter : public Building
{
public:
    Cutter(QPointF point, const int _direction, int _goodsCreateTime);
    ~Cutter();
    void advance(int phase);

    //切割机占2个格子，绘图函数需要重写
    QRectF boundingRect() const;

private:
    Goods *leftGoods;
    Goods *rightGoods;
    int goodsCounter, goodsCreateTime;
};

#endif // CUTTER_H


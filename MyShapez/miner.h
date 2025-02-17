#ifndef MINER_H
#define MINER_H

//开采器类

#include "building.h"
#include "goods.h"
#include "map.h"

class Miner : public Building
{
public:
    Miner(QPointF point, const int _direction, int _goodsCreateTime);
    ~Miner();
    void advance(int phase);

private:
    Goods *goods;
    int goodsType;
    int goodsCounter, goodsCreateTime;
};

#endif // MINER_H

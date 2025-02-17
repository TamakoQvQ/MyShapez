#ifndef BELT_TURN_H
#define BELT_TURN_H

//转弯传送带类

#include "map.h"
#include "building.h"

class Belt_turn: public Building
{
public:
    Belt_turn(QPointF point, const int _direction, int _speed);
    ~Belt_turn();
    void advance(int phase);
};

#endif // BELT_TURN_H


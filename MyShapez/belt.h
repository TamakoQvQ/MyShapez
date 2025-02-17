#ifndef BELT_H
#define BELT_H

//传送带类

#include "map.h"
#include "building.h"

class Belt : public Building
{
public:
    Belt(QPointF point, const int _direction, int _speed);
    ~Belt();
    void advance(int phase);
};

#endif // BELT_H


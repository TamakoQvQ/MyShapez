#ifndef TRASH_H
#define TRASH_H

//垃圾桶类

#include "map.h"
#include "building.h"

class Trash : public Building
{
public:
    Trash(QPointF point, const int _direction);
    ~Trash();
    void advance(int phase);
};

#endif // TRASH_H



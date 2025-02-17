#include "trash.h"


Trash::Trash(QPointF point, const int _direction)
{
    speed = 1000;//垃圾桶的速率应该是无限的
    direction = _direction;
    isWorking = true;//不管怎么样垃圾桶都会工作
    name = "Trash";
    xPos = point.x();
    yPos = point.y();
    setPos(xPos, yPos);
    setZValue(3);
}

Trash::~Trash()
{
    Map::BuildingMap[xPos / 40][yPos / 40] = nullptr;
}

void Trash::advance(int phase)
{
    if(!phase)
        return;
    update();
}

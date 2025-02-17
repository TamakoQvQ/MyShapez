#include "belt.h"

Belt::Belt(QPointF point, const int _direction, int _speed)
{
    speed = _speed;
    direction = _direction;
    isWorking = false;
    name = "Belt";
    xPos = point.x();
    yPos = point.y();
    setPos(xPos, yPos);
    setZValue(1);
}

Belt::~Belt()
{
    Map::BuildingMap[xPos / 40][yPos / 40] = nullptr;
}

void Belt::advance(int phase)
{
    if(!phase)
        return;
    update();
}



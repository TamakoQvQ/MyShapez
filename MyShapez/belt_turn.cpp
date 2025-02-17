#include "belt_turn.h"

Belt_turn::Belt_turn(QPointF point, const int _direction, int _speed)
{
    speed = _speed;
    direction = _direction;
    isWorking = false;
    name = "Belt_turn";
    xPos = point.x();
    yPos = point.y();
    setPos(xPos, yPos);
}

Belt_turn::~Belt_turn()
{
    Map::BuildingMap[xPos / 40][yPos / 40] = nullptr;
}

void Belt_turn::advance(int phase)
{
    if(!phase)
        return;
    update();
}

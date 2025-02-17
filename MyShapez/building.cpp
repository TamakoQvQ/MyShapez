#include "building.h"
#include "gamewindow.h"

Building::Building()
{

}

Building::~Building()
{

}

QRectF Building::boundingRect() const
{
    return QRectF(0, 0, blockSize, blockSize);
}

void Building::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QImage image(":/main/Picture/" + name + ".png");
    //按方向旋转
    QTransform transform;
    transform.rotate(90.0 * direction);
    image = image.transformed(transform,Qt::FastTransformation);
    painter->drawImage(boundingRect(), image);
}

void Building::advance(int phase)
{
    if(!phase)
        return;
    update();
}

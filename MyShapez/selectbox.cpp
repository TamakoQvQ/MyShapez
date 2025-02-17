#include "selectbox.h"

SelectBox::SelectBox()
{

}

QRectF SelectBox::boundingRect() const
{
    return QRectF(0, 0, 800, 100);
}

void SelectBox::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //显示背景框
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QImage image(":/main/Picture/selectbox_background.png");
    painter->drawImage(boundingRect(), image);

    //显示4种货物总量
    QFont font;
    font.setPointSize(12);
    painter->setFont(font);
    //蓝色
    painter->drawText(400, 85, QString::number(BuildingCards::blueTotal));
    painter->drawText(422, 85, "/20");

    //红色
    //painter->drawText(472, 85, "20");
    painter->drawText(472, 85, QString::number(BuildingCards::redTotal));
    painter->drawText(492, 85, "/30");

    //蓝色left
    painter->drawText(552, 85, QString::number(BuildingCards::blueLeftTotal));
    painter->drawText(572, 85, "/50");

    //蓝色right
    painter->drawText(622, 85, QString::number(BuildingCards::blueRightTotal));
    painter->drawText(642, 85, "/50");

}

void SelectBox::advance(int phase)
{
    if(!phase)
        return;
    update();
}

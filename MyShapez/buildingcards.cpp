#include "buildingcards.h"
#include "gamewindow.h"
#include "map.h"

int BuildingCards::blueTotal = 0;
int BuildingCards::redTotal = 0;
int BuildingCards::blueLeftTotal = 0;
int BuildingCards::blueRightTotal = 0;

BuildingCards::BuildingCards()
{
    setCursor(Qt::PointingHandCursor);
    setToolTip(tip);
    setZValue(0);
}

BuildingCards::~BuildingCards()
{
    blueTotal = 0;
    redTotal = 0;
    blueLeftTotal = 0;
    blueRightTotal = 0;
}

void BuildingCards::advance(int phase)
{

}

QRectF BuildingCards::boundingRect() const
{
    //此处前两个参数是相对选框窗口的参数
    return QRectF(20 + 60*No, 20, 60, 60);
}

void BuildingCards::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    //QImage image(":/main/Picture/miner_select.jpg");
    QImage image(":/main/Picture/BuildingCards/" + name.toLower() + ".png");
    painter->drawImage(boundingRect(), image);
}

void BuildingCards::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //如果卡片被点击
    if(!Map::PreparedBuilding && event->button()==Qt::LeftButton)
    {
        Map::PreparedBuildingDirection = 0;//默认方向为0
        QCursor cursor(QPixmap(":/main/Picture/Blue/" + name.toLower() + QString::number(Map::PreparedBuildingDirection) +  ".png"));//改变鼠标光标为对应建筑光标
        QApplication::setOverrideCursor(cursor);
        Map::PreparedBuilding = this;//告诉地图接下来可能要布局该建筑
    }
    //右键旋转
    if(Map::PreparedBuilding  && event->button()==Qt::RightButton)
    {
        Map::PreparedBuildingDirection = (Map::PreparedBuildingDirection + 1) % 4;
        qDebug() << "当前预放置建筑方向：" << Map::PreparedBuildingDirection;
        QApplication::restoreOverrideCursor();
        QCursor cursor(QPixmap(":/main/Picture/Blue/" + name.toLower() + QString::number(Map::PreparedBuildingDirection) +  ".png"));
        QApplication::setOverrideCursor(cursor);
    }
}

void BuildingCards::keyPressEvent(QKeyEvent *event)
{

}


void BuildingCards::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
}

miner::miner()
{
    name = "Miner";
    No = 0;
    tip = "开采器";
}

belt::belt()
{
    name = "belt";
    No = 1;
    tip = "传送带";
}

belt_turn::belt_turn()
{
    name = "belt_turn";
    No = 2;
    tip = "转弯传送带";
}

cutter::cutter()
{
    name = "cutter";
    No = 3;
    tip = "切割机";
}

trash::trash()
{
    name = "trash";
    No = 4;
    tip = "垃圾桶";
}

rotater::rotater()
{
    name = "rotater";
    No = 5;
    tip = "旋转器";
}

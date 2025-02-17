#include "map.h"

BuildingCards* Map::PreparedBuilding = nullptr;
int Map::PreparedBuildingDirection = 0;
Building* Map::BuildingMap[100][100];
Mineral* Map::MineralMap[100][100];
bool Map::MinerralUP = false;
bool Map::CoinUP = false;
bool Map::mousePress = 0;
int Map::coinsTotal = 0;//记得改
int Map::coinPerTime = 2;
int Map::MinergoodsCreateTime = 100;
int Map::CuttergoodsCreateTime = 200;
int Map::speedBelt = 1;
int Map::taskDown = 0;

Map::Map()
{
    for(int i = 0; i < 100; ++i)
    {
        for(int j = 0; j < 100; ++j)
        {
            MineralMap[i][j] = nullptr;
            BuildingMap[i][j] = nullptr;
        }
    }
    this->setAcceptedMouseButtons(Qt::AllButtons);

}

Map::~Map()
{
    PreparedBuilding = nullptr;
    for(int i = 0; i < 100; ++i)
    {
        for(int j = 0; j < 100; ++j)
        {
            delete MineralMap[i][j];
            delete BuildingMap[i][j];
        }
    }
}

QRectF Map::boundingRect() const
{
    return QRectF(0, 0, 2000, 2000);
}

void Map::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Map::advance(int phase)
{
    if (!phase)
        return;
    update();
    if(BuildingCards::blueTotal == 20)
    {
        taskDown = 1;
        //qDebug()<< "taskDown="<<taskDown;
    }
    if(BuildingCards::redTotal == 30)
    {
        taskDown = 1;
    }
    if(BuildingCards::blueLeftTotal == 50)
    {
        taskDown = 1;
    }
}

void Map::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //左键执行放置
    if(PreparedBuilding && event->button()==Qt::LeftButton)
    {
        qDebug()<< "点击的坐标：" << (int)event->scenePos().x() << (int)event->scenePos().y();
        int i = ((int)event->scenePos().x()) / 40;
        int j = ((int)event->scenePos().y()) / 40;
        qDebug()<< "在数组中的坐标：" << i << j;
        //当前已有建筑 需删除原有建筑
        if(BuildingMap[i][j])
        {
            delete BuildingMap[i][j];
            BuildingMap[i][j] = nullptr;
            QApplication::restoreOverrideCursor();
        }
        //当前位置的上面或者左边有切割机也需要删除 因为切割机判定位置在左边和上面
        else if(BuildingMap[i - 1][j] && BuildingMap[i - 1][j]->name == "Cutter" && BuildingMap[i - 1][j]->direction % 2 == 0)
        {
            delete BuildingMap[i - 1][j];
            BuildingMap[i - 1][j] = nullptr;
            QApplication::restoreOverrideCursor();
        }
        else if(BuildingMap[i][j - 1] && BuildingMap[i][j - 1]->name == "Cutter" && BuildingMap[i][j - 1]->direction % 2 != 0)
        {
            delete BuildingMap[i][j - 1];
            BuildingMap[i][j - 1] = nullptr;
            QApplication::restoreOverrideCursor();
        }
        QPointF buildingPos(40 * i, 40 * j);
        switch(PreparedBuilding->No)
        {
        case 0: BuildingMap[i][j] = new Miner(buildingPos, PreparedBuildingDirection, MinergoodsCreateTime); break;
        case 1:
            BuildingMap[i][j] = new Belt(buildingPos, PreparedBuildingDirection, speedBelt);
            qDebug() << "传送带方向：" << BuildingMap[i][j]->direction;
            mousePress = true;
            break;
        case 2: BuildingMap[i][j] = new Belt_turn(buildingPos, PreparedBuildingDirection, speedBelt); break;
        case 3: BuildingMap[i][j] = new Cutter(buildingPos, PreparedBuildingDirection, CuttergoodsCreateTime); break;
        //垃圾桶的方向只能为0
        case 4: BuildingMap[i][j] = new Trash(buildingPos, 0); break;
        case 5: BuildingMap[i][j] = new Rotater(buildingPos, PreparedBuildingDirection); break;
        default: break;
        }
        scene()->addItem(BuildingMap[i][j]);
        PreparedBuilding = nullptr;
        QApplication::restoreOverrideCursor();
    }
    //右键执行删除
    if(event->button()==Qt::RightButton)
    {
        int i = ((int)event->scenePos().x()) / 40;
        int j = ((int)event->scenePos().y()) / 40;
        //当前已有建筑
        if(BuildingMap[i][j])
        {
            delete BuildingMap[i][j];
            BuildingMap[i][j] = nullptr;
            QApplication::restoreOverrideCursor();
        }
        //点击位置的上面或者左边有切割机也需要删除 因为切割机判定位置在左边和上面
        else if(BuildingMap[i - 1][j] && BuildingMap[i - 1][j]->name == "Cutter" && BuildingMap[i - 1][j]->direction % 2 == 0)
        {
            delete BuildingMap[i - 1][j];
            BuildingMap[i - 1][j] = nullptr;
            QApplication::restoreOverrideCursor();
        }
        else if(BuildingMap[i][j - 1] && BuildingMap[i][j - 1]->name == "Cutter" && BuildingMap[i][j - 1]->direction % 2 != 0)
        {
            delete BuildingMap[i][j - 1];
            BuildingMap[i][j - 1] = nullptr;
            QApplication::restoreOverrideCursor();
        }
    }
}

void Map::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(mousePress){
        qDebug()<< "点击的坐标：" << (int)event->scenePos().x() << (int)event->scenePos().y();
                                                                           int i = ((int)event->scenePos().x()) / 40;
        int j = ((int)event->scenePos().y()) / 40;
        qDebug()<< i << j;
        //当前已有建筑 需删除原有建筑
        if(BuildingMap[i][j])
        {
            delete BuildingMap[i][j];
            BuildingMap[i][j] = nullptr;
            QApplication::restoreOverrideCursor();
        }
        //当前位置的上面或者左边有切割机也需要删除 因为切割机判定位置在左边和上面
        else if(BuildingMap[i - 1][j] && BuildingMap[i - 1][j]->name == "Cutter" && BuildingMap[i - 1][j]->direction % 2 == 0)
        {
            delete BuildingMap[i - 1][j];
            BuildingMap[i - 1][j] = nullptr;
            QApplication::restoreOverrideCursor();
        }
        else if(BuildingMap[i][j - 1] && BuildingMap[i][j - 1]->name == "Cutter" && BuildingMap[i][j - 1]->direction % 2 != 0)
        {
            delete BuildingMap[i][j - 1];
            BuildingMap[i][j - 1] = nullptr;
            QApplication::restoreOverrideCursor();
        }
        QPointF buildingPos(40 * i, 40 * j);
        BuildingMap[i][j] = new Belt(buildingPos, PreparedBuildingDirection, speedBelt);
        scene()->addItem(BuildingMap[i][j]);
        PreparedBuilding = nullptr;
        QApplication::restoreOverrideCursor();
    }
}

void Map::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    mousePress = false;
    Q_UNUSED(event);
}



#include "gamewindow.h"
#include "map.h"
#include "deliverycenter.h"

gameWindow::gameWindow()
{

    timer = new QTimer;
    //游戏窗口大小 不可更改 1600 904
    setFixedSize(904,904);

    // 创建地图场景 4000 4000
    mapScene = new QGraphicsScene(this);
    mapScene->setSceneRect(0, 0, 1590, 795);

    // 创建视图 1600 800
    view = new QGraphicsView(mapScene, this);
    view->setFixedSize(1600,800);
    //view->setBackgroundBrush(QPixmap(":/main/Picture/map0.jpg"));
    view->show();

    //添加地图
    map = new Map;
    mapScene->addItem(map);

    //添加开采物
    //2个位置存在开采物 地图大小100 100 单位格
    Map::MineralMap[3][3] = new BlueMineral(3,3);
    mapScene->addItem(Map::MineralMap[3][3]);
    Map::MineralMap[4][3] = new BlueMineral(4,3);
    mapScene->addItem(Map::MineralMap[4][3]);
    Map::MineralMap[3][4] = new BlueMineral(3,4);
    mapScene->addItem(Map::MineralMap[3][4]);
    Map::MineralMap[4][4] = new BlueMineral(4,4);
    mapScene->addItem(Map::MineralMap[4][4]);

    Map::MineralMap[5][15] = new RedMineral(5,15);
    mapScene->addItem(Map::MineralMap[5][15]);
    Map::MineralMap[5][16] = new RedMineral(5,16);
    mapScene->addItem(Map::MineralMap[5][16]);
    Map::MineralMap[6][15] = new RedMineral(6,15);
    mapScene->addItem(Map::MineralMap[6][15]);
    Map::MineralMap[6][16] = new RedMineral(6,16);
    mapScene->addItem(Map::MineralMap[6][16]);

    //如果强化过开采物数量 就再添加一些
    if(Map::MinerralUP)
    {
        Map::MineralMap[15][8] = new RedMineral(15,8);
        mapScene->addItem(Map::MineralMap[15][8]);
        Map::MineralMap[15][9] = new RedMineral(15,9);
        mapScene->addItem(Map::MineralMap[15][9]);
        Map::MineralMap[16][8] = new RedMineral(16,8);
        mapScene->addItem(Map::MineralMap[16][8]);
        Map::MineralMap[16][9] = new RedMineral(16,9);
        mapScene->addItem(Map::MineralMap[16][9]);

        Map::MineralMap[17][17] = new BlueMineral(17,17);
        mapScene->addItem(Map::MineralMap[17][17]);
        Map::MineralMap[17][18] = new BlueMineral(17,18);
        mapScene->addItem(Map::MineralMap[17][18]);
        Map::MineralMap[18][17] = new BlueMineral(18,17);
        mapScene->addItem(Map::MineralMap[18][17]);
        Map::MineralMap[18][18] = new BlueMineral(18,18);
        mapScene->addItem(Map::MineralMap[18][18]);
    }

    //给窗口安装一个事件接收器
    installEventFilter(this);

    //添加交付中心
    DeliveryCenter *deliveryCenter = new DeliveryCenter();
    mapScene->addItem(deliveryCenter);

    //创建选框场景
    selectBoxScene = new QGraphicsScene(this);
    selectBoxScene->setSceneRect(0, 0, 1590, 100);

    //创建选框视图 比场景略大
    selectView = new QGraphicsView(selectBoxScene, this);
    selectView->setGeometry(0, 800, 1600, 104);
    //selectView->setBackgroundBrush(QPixmap(":/main/Picture/selectbox_background.png"));
    selectView->show();

    selectbox = new SelectBox;
    selectBoxScene->addItem(selectbox);

    BuildingCards *cards[6]={new miner, new belt, new belt_turn, new cutter, new trash, new rotater};
    for(int i = 0; i < 6; ++i)
    {
        selectBoxScene->addItem(cards[i]);
    }

    //添加提示文字
    QGraphicsTextItem *txtitem1 = new QGraphicsTextItem("完成任务后可以升级设备噢-3-\n按M/B/C升级开采器/传送带/切割机");
    txtitem1->setPos(QPointF(680, 0));//设置要放置的的位置
    selectBoxScene->addItem(txtitem1);//添加item到scene上
    QGraphicsTextItem *txtitem2 = new QGraphicsTextItem("按S保存游戏并退出");
    txtitem2->setPos(QPointF(680, 50));//设置要放置的的位置
    selectBoxScene->addItem(txtitem2);//添加item到scene上

    //放音乐
    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput );
    audioOutput->setVolume(0.5);  //调节音频音量
    player->setSource(QUrl("qrc:/main/Picture/bgm.mp3"));
    player->setLoops(-1); // -1 表示无限循环播放
    player->play();

    timer->start(20);

    connect(timer, &QTimer::timeout, mapScene, &QGraphicsScene::advance);
    connect(timer, &QTimer::timeout, selectBoxScene, &QGraphicsScene::advance);

}

gameWindow::~gameWindow()
{
    delete map;
    delete selectBoxScene;
    delete mapScene;
    delete player;
    delete audioOutput;
}

void gameWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
}

//事件接收器
bool gameWindow::eventFilter(QObject *obj, QEvent *event)
{
    // obj是这个事件来自于哪个对象 event表示事件类型
    if(obj == this && event->type() == QEvent::KeyPress)
    {
        auto keyEvent = dynamic_cast<QKeyEvent *>(event);
        if (keyEvent->key() == Qt::Key_M)
        {
            if(Map::taskDown == 0)
            {
                QMessageBox::information(NULL, "糟糕", "任务未完成，不可以升级（> <）", QMessageBox::Yes, QMessageBox::Yes);
            }
            else
            {
                Map::MinergoodsCreateTime = 50;
                Map::taskDown = 0;
                QMessageBox::information(NULL, "你被强化了", "开采器的速率增加了！（OvO）", QMessageBox::Yes, QMessageBox::Yes);
            }

        }
        if (keyEvent->key() == Qt::Key_B)
        {
            if(Map::taskDown == 0)
            {
                QMessageBox::information(NULL, "糟糕", "任务未完成，不可以升级（> <）", QMessageBox::Yes, QMessageBox::Yes);
            }
            else
            {
                Map::speedBelt = 2;
                Map::taskDown = 0;
                QMessageBox::information(NULL, "你被强化了", "传送带的速率增加了！（OvO）", QMessageBox::Yes, QMessageBox::Yes);

            }
            //qDebug()<<"333";
        }
        if (keyEvent->key() == Qt::Key_C)
        {
            if(Map::taskDown == 0)
            {
                QMessageBox::information(NULL, "糟糕", "任务未完成，不可以升级（> <）", QMessageBox::Yes, QMessageBox::Yes);
            }
            else
            {
                Map::CuttergoodsCreateTime = 100;
                Map::taskDown = 0;
                QMessageBox::information(NULL, "你被强化了", "切割机的速率增加了！（OvO）", QMessageBox::Yes, QMessageBox::Yes);

            }
            //qDebug()<<"333";
        }
        //存档
        if (keyEvent->key() == Qt::Key_S)
        {
            QFile data("D:\\MyGame.txt");
            if (data.open(QFile::WriteOnly | QFile::Truncate))
            {
                QTextStream out(&data);
                out << Map::MinerralUP << "\n";
                out << Map::CoinUP << "\n";
                out << Map::coinsTotal << "\n";
                out << DeliveryCenter::DCsize << "\n";
                out << Map::coinPerTime << "\n";
                out << Map::MinergoodsCreateTime << "\n";
                out << Map::CuttergoodsCreateTime << "\n";
                out << Map::speedBelt << "\n";
                out << BuildingCards::blueTotal << "\n";
                out << BuildingCards::redTotal << "\n";
                out << BuildingCards::blueLeftTotal << "\n";
                out << BuildingCards::blueRightTotal << "\n";
                qDebug() << "存档成功";
            }
            else
                qDebug() << "存档失败";
            data.close();
            this->close();
        }
    }
    return false;
}

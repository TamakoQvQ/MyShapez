#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QPainter>
#include <QMainWindow>
#include <QScrollArea>
#include <QMatrix2x2>
#include <QTime>
#include <QTimer>
#include <QMessageBox>
#include <QFile>
#include <QMediaPlayer>
#include <QAudioOutput>

#include "deliverycenter.h"
#include "mineral.h"
#include "map.h"
#include "selectbox.h"

class gameWindow : public QWidget
{
public:
    QGraphicsScene* mapScene;
    QGraphicsScene* selectBoxScene;
    QGraphicsView *view;
    QGraphicsView *selectView;
    QMediaPlayer *player = nullptr;
    QAudioOutput *audioOutput = nullptr;


    gameWindow();
    ~gameWindow();
    void paintEvent(QPaintEvent *event);
    //事件接收器的函数
    bool eventFilter(QObject *obj,QEvent *event);



private:
    Map *map;
    QTimer *timer;
    SelectBox *selectbox;

};

#endif // GAMEWINDOW_H

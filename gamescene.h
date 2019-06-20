#ifndef GAMESCENE_H
#define GAMESCENE_H
#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>
#include <QList>

#include <QDebug>

#include "pacman.h"
#include "ghost.h"
#include "oikake.h"
#include "machibuse.h"
#include "kimagure.h"
#include "otoboke.h"
#include "coin.h"
#include "wall.h"


class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GameScene(qreal x, qreal y, qreal width, qreal height, QObject *parent = nullptr);


private:
    QTimer *timer_1,*timer_2,*timer_3;
    Coin *coin[27][24];
    Wall *wall[27][24];
    QList<QPointF> map;
    QList<QPointF> inter;
    QList<QPointF> poi;
    PacMan pacMan;
    Oikake Akabei;
    Machibuse Pinky;
    Kimagure Aosuke;
    Otoboke Guzuta;

    Character *pacman = &pacMan;
    Character *blinky  = &Akabei;
    Character *pinky = &Pinky;
    Character *inky  = &Aosuke;
    Character *clyde = &Guzuta;

    int speed;
    int score;
    int rank;
    int time3;

    void startGame();
    void setMap();
    void setIntersection();
    void setPowerPellets();
    void eat();
    void haha(int);
    void keyPressEvent(QKeyEvent *event);

public slots:
    void timeOut_Move();
    void timeOut_Img();
    void timeOut_Power();
    void timePause();
    void timeResume();

signals:
    void changeScore(int);
    void win(int);
    void gg();

};

#endif // GAMESCENE_H

#include "gamescene.h"

GameScene::GameScene(qreal x, qreal y, qreal width, qreal height, QObject *parent) :
    QGraphicsScene(x,y,width,height,parent)
{
    rank = 1;
    startGame();
}

void GameScene::startGame()
{
    //set timer
    timer_1 = new QTimer(this);
    timer_1->start(200);
    connect(timer_1,SIGNAL(timeout()),this,SLOT(timeOut_Move()));

    timer_2 = new QTimer(this);
    timer_2->start(300);
    connect(timer_2,SIGNAL(timeout()),this,SLOT(timeOut_Img()));

    timer_3 = new QTimer(this);
    //timer_3->start(200);
    connect(timer_3,SIGNAL(timeout()),this,SLOT(timeOut_Power()));

    time3 = 0;

    score = 0;

    //set coins

    for(int i=0;i<27;++i){
        for(int j=0;j<24;++j){
            coin[i][j] = new Coin();
            coin[i][j]->alive = true;
            coin[i][j]->setPos(i*40,j*40);
            coin[i][j]->setImg();
            this->addItem(coin[i][j]);
        }
    }

    //set walls
    for(int i=0;i<27;++i){
        for(int j=0;j<24;++j){
            wall[i][j] = new Wall();
            wall[i][j]->exists = false;
            wall[i][j]->setImg();
            wall[i][j]->setPos(i*40,j*40);
            this->addItem(wall[i][j]);
        }
    }
    setMap();
    setIntersection();
    setPowerPellets();
    foreach(QPointF i ,map){
        int a = i.x();
        int b = i.y();
        wall[a][b]->exists = true;
        wall[a][b]->setImg();
    }

    pacMan.getMap(map);
    Akabei.getMap(map);
    Pinky.getMap(map);
    Aosuke.getMap(map);
    Guzuta.getMap(map);

    pacMan.getInter(inter);
    Akabei.getInter(inter);
    Pinky.getInter(inter);
    Aosuke.getInter(inter);
    Guzuta.getInter(inter);

    //delete coins that should be empty
    foreach(QPointF i,map){
        int a = i.x();
        int b = i.y();
        coin[a][b]->alive = false;
        coin[a][b]->setImg();
    }
    for(int j=0;j<2;++j){
        for(int i=0;i<5;++i){
            coin[i][j+8]->alive = false;
            coin[i][j+8]->setImg();
            coin[i][j+13]->alive = false;
            coin[i][j+13]->setImg();

            coin[i+22][j+8]->alive = false;
            coin[i+22][j+8]->setImg();
            coin[i+22][j+13]->alive = false;
            coin[i+22][j+13]->setImg();
        }
        for(int i=10;i<17;++i){
            coin[i][j+10]->alive = false;
            coin[i][j+10]->setImg();
        }
    }
    for(int i=0;i<3;++i){
        coin[i+12][9]->alive = false;
        coin[i+12][9]->setImg();
    }
    for(int i=0;i<6;++i){
        coin[i][11]->alive = false;
        coin[i][11]->setImg();
        coin[i+21][11]->alive = false;
        coin[i+21][11]->setImg();
        coin[8][i+8]->alive = false;
        coin[8][i+8]->setImg();
        coin[18][i+8]->alive = false;
        coin[18][i+8]->setImg();
    }
    for(int i=0;i<9;++i){
        coin[i+9][8]->alive = false;
        coin[i+9][8]->setImg();
        coin[i+9][13]->alive = false;
        coin[i+9][13]->setImg();
    }
    coin[7][11]->alive = false;
    coin[7][11]->setImg();
    coin[19][11]->alive = false;
    coin[19][11]->setImg();

    coin[13][18]->alive = false;
    coin[13][18]->setImg();

    //set power pellets
    foreach(QPointF i,poi){
        int a = i.x();
        int b = i.y();
        coin[a][b]->power = true;
        coin[a][b]->setImg();
    }

    //set items

    pacman->setPos(13*40,18*40);
    pacman->setImg();
    pacman->show();
    pacman->key = 0;
    this->addItem(pacman);

    //blinky->setPos(12*40,10*40);
    blinky->setPos(1*40,1*40);
    blinky->setImg();
    blinky->show();
    blinky->key = 0;
    this->addItem(blinky);

    //pinky->setPos(14*40,10*40);
    pinky->setPos(25*40,1*40);
    pinky->setImg();
    pinky->show();
    pinky->key = 0;
    this->addItem(pinky);

    //inky->setPos(12*40,11*40);
    inky->setPos(1*40,22*40);
    inky->setImg();
    inky->show();
    inky->key = 0;
    this->addItem(inky);

    //clyde->setPos(14*40,11*40);
    clyde->setPos(25*40,22*40);
    clyde->setImg();
    clyde->show();
    clyde->key = 0;
    this->addItem(clyde);
}

void GameScene::setMap()
{
    //out side
    for(int i=0;i<27;++i){
        map.append(QPointF(i,0));
        map.append(QPointF(i,23));
    }
    for(int i=0;i<8;++i){
        map.append(QPointF(0,i));
        map.append(QPointF(26,i));
    }
    for(int i=15;i<24;++i){
        map.append(QPointF(0,i));
        map.append(QPointF(26,i));
    }
    map.append(QPointF(0,10));
    map.append(QPointF(0,12));
    map.append(QPointF(26,10));
    map.append(QPointF(26,12));

    //inside
    for(int j=2;j<4;++j){
        for(int i=2;i<6;++i){
            map.append(QPointF(i,j));
            map.append(QPointF(i+19,j));
        }
        for(int i=7;i<12;++i){
            map.append(QPointF(i,j));
            map.append(QPointF(i+8,j));
        }
        for(int i=9;i<18;++i)
            map.append(QPointF(i,j+12));
    }
    //sort by length
    for(int i=0;i<2;++i){
        map.append(QPointF(13,i+6));
        map.append(QPointF(13,i+20));
        map.append(QPointF(13,i+16));
        map.append(QPointF(7,i+19));
        map.append(QPointF(19,i+19));
        map.append(QPointF(5,i+18));
        map.append(QPointF(21,i+18));
        map.append(QPointF(i+10,9));
        map.append(QPointF(i+15,9));
    }
    for(int i=0;i<3;++i){
        map.append(QPointF(13,i+1));
        map.append(QPointF(i+1,19));
        map.append(QPointF(i+23,19));
        map.append(QPointF(9,i+9));
        map.append(QPointF(17,i+9));
    }
    for(int i=0;i<4;++i){
        map.append(QPointF(i+2,5));
        map.append(QPointF(i+21,5));
        map.append(QPointF(5,i+7));
        map.append(QPointF(21,i+7));
        map.append(QPointF(5,i+12));
        map.append(QPointF(21,i+12));
        map.append(QPointF(i+1,7));
        map.append(QPointF(i+1,10));
        map.append(QPointF(i+1,12));
        map.append(QPointF(i+1,15));
        map.append(QPointF(i+22,7));
        map.append(QPointF(i+22,10));
        map.append(QPointF(i+22,12));
        map.append(QPointF(i+22,15));

        map.append(QPointF(i+8,7));
        map.append(QPointF(i+15,7));
        map.append(QPointF(7,i+12));
        map.append(QPointF(19,i+12));
        map.append(QPointF(i+2,17));
        map.append(QPointF(i+21,17));
    }
    for(int i=0;i<5;++i){
        map.append(QPointF(i+7,17));
        map.append(QPointF(i+15,17));
    }
    for(int i=0;i<6;++i){
        map.append(QPointF(7,i+5));
        map.append(QPointF(19,i+5));
    }
    for(int i=0;i<9;++i){
        map.append(QPointF(i+9,5));
        map.append(QPointF(i+9,12));
        map.append(QPointF(i+9,19));
    }
    for(int i=0;i<10;++i){
        map.append(QPointF(i+2,21));
        map.append(QPointF(i+15,21));
    }
}

void GameScene::setIntersection()
{
    inter.append(QPointF(1,1));
    inter.append(QPointF(1,4));
    inter.append(QPointF(1,6));
    inter.append(QPointF(1,16));
    inter.append(QPointF(1,18));
    inter.append(QPointF(1,20));
    inter.append(QPointF(1,22));

    inter.append(QPointF(4,18));
    inter.append(QPointF(4,20));

    inter.append(QPointF(6,1));
    inter.append(QPointF(6,4));
    inter.append(QPointF(6,6));
    inter.append(QPointF(6,11));
    inter.append(QPointF(6,16));
    inter.append(QPointF(6,20));

    inter.append(QPointF(8,4));
    inter.append(QPointF(8,6));
    inter.append(QPointF(8,8));
    inter.append(QPointF(8,11));
    inter.append(QPointF(8,13));
    inter.append(QPointF(8,16));
    inter.append(QPointF(8,18));
    inter.append(QPointF(8,20));

    inter.append(QPointF(12,1));
    inter.append(QPointF(12,4));
    inter.append(QPointF(12,6));
    inter.append(QPointF(12,8));
    inter.append(QPointF(12,16));
    inter.append(QPointF(12,18));
    inter.append(QPointF(12,20));
    inter.append(QPointF(12,22));

    inter.append(QPointF(14,1));
    inter.append(QPointF(14,4));
    inter.append(QPointF(14,6));
    inter.append(QPointF(14,8));
    inter.append(QPointF(14,16));
    inter.append(QPointF(14,18));
    inter.append(QPointF(14,20));
    inter.append(QPointF(14,22));

    inter.append(QPointF(18,4));
    inter.append(QPointF(18,6));
    inter.append(QPointF(18,8));
    inter.append(QPointF(18,11));
    inter.append(QPointF(18,13));
    inter.append(QPointF(18,16));
    inter.append(QPointF(18,18));
    inter.append(QPointF(18,20));

    inter.append(QPointF(20,1));
    inter.append(QPointF(20,4));
    inter.append(QPointF(20,6));
    inter.append(QPointF(20,11));
    inter.append(QPointF(20,16));
    inter.append(QPointF(20,18));
    inter.append(QPointF(20,20));

    inter.append(QPointF(22,18));
    inter.append(QPointF(22,20));

    inter.append(QPointF(25,1));
    inter.append(QPointF(25,4));
    inter.append(QPointF(25,6));
    inter.append(QPointF(25,16));
    inter.append(QPointF(25,18));
    inter.append(QPointF(25,20));
    inter.append(QPointF(25,22));
}

void GameScene::setPowerPellets()
{
    poi.append(QPointF(6,4));
    poi.append(QPointF(6,16));
    poi.append(QPointF(20,4));
    poi.append(QPointF(20,16));
    poi.append(QPointF(12,1));
    poi.append(QPointF(14,1));
    poi.append(QPointF(4,18));
    poi.append(QPointF(22,18));
}

void GameScene::eat()
{
    qDebug()<<"die!";
    pacman->isTouched = true;
    timer_1->stop();
    emit gg();
}

void GameScene::haha(int t)
{
    switch (t) {
    case 1:
        blinky->setPos(12*40,10*40);
        break;
    case 2:
        pinky->setPos(14*40,10*40);
        break;
    case 3:
        inky->setPos(12*40,11*40);
        break;
    case 4:
        clyde->setPos(14*40,11*40);
        break;
    }
    score+=200;
    emit changeScore(score);
}

void GameScene::keyPressEvent(QKeyEvent *event)
{
    pacman->changeDirect(event->key());
}

void GameScene::timeOut_Move()
{
    bool haveCoin = false;
    pacman->isTouched = false;
    blinky->isTouched = false;
    pinky->isTouched = false;
    inky->isTouched = false;
    clyde->isTouched = false;

    blinky->isPower = false;
    pinky->isPower = false;
    inky->isPower = false;
    clyde->isPower = false;
    for(int i=0;i<27;++i){
        for(int j=0;j<24;++j){
            if(pacman->collidesWithItem(coin[i][j])){
                if(coin[i][j]->alive == true){
                    if(coin[i][j]->power == false){
                        score+=10;
                        emit changeScore(score);
                    }
                    else{
                        score+=50;
                        emit changeScore(score);
                        qDebug()<<"power Time";
                        time3 = 0;
                        timer_1->stop();
                        timer_3->start(200);
                    }
                }
                coin[i][j]->alive = false;
                coin[i][j]->setImg();
            }
            if(pacman->collidesWithItem(wall[i][j])){
                pacman->isTouched = true;
            }
            if(blinky->collidesWithItem(wall[i][j])){
                blinky->isTouched = true;
            }
            if(pinky->collidesWithItem(wall[i][j])){
                pinky->isTouched = true;
            }
            if(inky->collidesWithItem(wall[i][j])){
                inky->isTouched = true;
            }
            if(clyde->collidesWithItem(wall[i][j])){
                clyde->isTouched = true;
            }
        }
    }

    if(pacman->collidesWithItem(blinky) || pacman->collidesWithItem(pinky) || pacman->collidesWithItem(inky) || pacman->collidesWithItem(clyde)){
        eat();
    }

    pacman->move();

    Akabei.getPac(pacman->pos());
    blinky->move();

    Pinky.getPac(pacman->pos());
    pinky->move();
    inky->move();
    clyde->move();

    blinky->setImg();
    pinky->setImg();
    inky->setImg();
    clyde->setImg();

    for(int i=0;i<27;++i){
        for(int j=0;j<24;++j){
            if(coin[i][j]->alive == true){
                haveCoin = true;
                break;
            }
        }
    }
    if(haveCoin == false){
        qDebug()<<"win";
        emit win(++rank);
        startGame();
    }
}

void GameScene::timeOut_Img()
{
    pacman->setImg();
}

void GameScene::timeOut_Power()
{
    if(time3 > 20){
        timer_3->stop();
        timer_1->start();
        blinky->isPower = false;
        pinky->isPower = false;
        inky->isPower = false;
        clyde->isPower = false;
    }
    time3++;

    bool haveCoin = false;

    pacman->move();
    blinky->isPower = true;
    pinky->isPower = true;
    inky->isPower = true;
    clyde->isPower = true;
    blinky->move();
    pinky->move();
    inky->move();
    clyde->move();

    blinky->setScare();
    pinky->setScare();
    inky->setScare();
    clyde->setScare();


    for(int i=0;i<27;++i){
        for(int j=0;j<24;++j){
            if(pacman->collidesWithItem(coin[i][j])){
                if(coin[i][j]->alive == true){
                    if(coin[i][j]->power == false){
                        score+=10;
                        emit changeScore(score);
                    }
                    else{
                        score+=50;
                        emit changeScore(score);
                        time3 = 0;
                    }
                }
                coin[i][j]->alive = false;
                coin[i][j]->setImg();
            }
            for(int i=0;i<27;++i){
                for(int j=0;j<24;++j){
                    if(coin[i][j]->alive == true){
                        haveCoin = true;
                        break;
                    }
                }
            }
            if(haveCoin == false){
                qDebug()<<"win";
                emit win(++rank);
                startGame();
            }
        }
    }
    if(pacman->collidesWithItem(blinky)){
        haha(1);
    }
    if(pacman->collidesWithItem(pinky)){
        haha(2);
    }
    if(pacman->collidesWithItem(inky)){
        haha(3);
    }
    if(pacman->collidesWithItem(clyde)){
        haha(4);
    }
}
void GameScene::timePause()
{
    timer_1->stop();
    timer_2->stop();
}

void GameScene::timeResume()
{
    timer_1->start();
    timer_2->start();
}

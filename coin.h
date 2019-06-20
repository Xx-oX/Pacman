#ifndef COIN_H
#define COIN_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Coin : public QGraphicsPixmapItem
{
public:
    Coin();

    bool alive;
    bool power;

    void setImg();

};

#endif // COIN_H

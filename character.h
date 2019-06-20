#ifndef CHARACTER_H
#define CHARACTER_H
#include <QGraphicsPixmapItem>

#include <QDebug>

class Character : public QGraphicsPixmapItem
{
public:
    Character();

    bool timeIsOdd;
    bool isTouched;
    bool AfTouched;
    bool isPower;
    int key;
    int s_key;
    int t_key;
    int f_key;
    QPointF previousPos;
    QList<QPointF> map;
    int wall[27][24];

    virtual void setImg();
    virtual void setScare();
    virtual void changeDirect(int);
    virtual void changeDirect(QPointF);
    virtual void powerDirect(QPointF);
    virtual void move();
    void getMap(QList<QPointF>);
    void getInter(QList<QPointF>);
    bool check(int,int);
    bool onRoad(double,double,int);
};

#endif // CHARACTER_H

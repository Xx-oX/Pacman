#include "character.h"

Character::Character()
{

}

void Character::setImg()
{

}

void Character::setScare()
{

}

void Character::changeDirect(int)
{

}

void Character::changeDirect(QPointF)
{

}

void Character::powerDirect(QPointF)
{

}

void Character::move()
{

}


bool Character::check(int a, int b)
{
    if(wall[a][b] == 1){
        return false;
    }
    else{
        return true;
    }
}

bool Character::onRoad(double x, double y,int nkey)
{
    if(nkey == 1 || nkey == 2){
        if((int)y%40 != 0)
            return false;
        else
            return true;
    }
    else if (nkey == 3 || nkey == 4) {
        if((int)x%40 != 0)
            return false;
        else
            return true;
    }
    else {
        return true;
    }
}

void Character::getMap(QList<QPointF> k)
{
    map = k;
    foreach (QPointF i,map){
        int a = i.x();
        int b = i.y();
        wall[a][b] = 1;
    }
}

void Character::getInter(QList<QPointF> inter)
{
    foreach (QPointF i,inter){
        int a = i.x();
        int b = i.y();
        wall[a][b] = 2;
    }
}

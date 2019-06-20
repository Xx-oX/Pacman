#include "otoboke.h"

Otoboke::Otoboke() : ghost (4)
{

}

void Otoboke::changeDirect(QPointF)
{
    int r = qrand() % ((4 + 1) - 1) + 1;
    switch(r){
    case 1:
        if(key == 1){
            key = 3;
        }
        else{
            key = 1;
        }
        break;
    case 2:
        if(key == 2){
            key = 4;
        }
        else{
            key = 2;
        }
        break;
    case 3:
        if(key == 3){
            key = 2;
        }
        else{
            key = 3;
        }
        break;
    case 4:
        if(key == 4){
            key = 1;
        }
        else{
            key = 4;
        }
        break;
    }
}

void Otoboke::powerDirect(QPointF k)
{
    double dx = k.x() - this->x();
    double dy = k.y() - this->y();
    if(dx > 0){
    if(dy > 0){
        if(dx > dy){
            key = 1;
            s_key = 3;
            t_key = 4;
            f_key = 2;
        }
        else {
            key = 3;
            s_key = 1;
            t_key = 2;
            f_key = 4;
        }
    }
    else {
        if(dx > -dy){
            key = 1;
            s_key = 4;
            t_key = 3;
            f_key = 2;
        }
        else {
            key = 4;
            s_key = 1;
            t_key = 2;
            f_key = 3;
        }
    }
}
    else {
    if(dy > 0){
        if(-dx > dy){
            key = 2;
            s_key = 3;
            t_key = 4;
            f_key = 1;
        }
        else {
            key = 3;
            s_key = 2;
            t_key = 1;
            f_key = 4;
        }
    }
    else {
        if(-dx > -dy){
            key = 2;
            s_key = 4;
            t_key = 3;
            f_key = 1;
        }
        else {
            key = 4;
            s_key = 2;
            t_key = 1;
            f_key = 3;
        }
    }
}
}

void Otoboke::move()
{
    int af = 0;
    int nx = (this->x())/40;
    int ny = (this->y())/40;
    if(wall[nx][ny] == 2){
        if(isPower)
            powerDirect(pac);
        else
            changeDirect(pac);
    }
    switch(key){
    case 0:
        break;
    case 1:
        af = this->x() - PIX_PER_TIME;
        if(check(nx-1,ny) && onRoad(af,this->y(),key)){
            if(af<-40)
                this->setX(1080 - 40);
            else
                this->setX(af);
        }
        break;
    case 2:
        af = this->x() + PIX_PER_TIME;
        if(check(nx+1,ny) && onRoad(af,this->y(),key)){
            if(af>1080-40)
                this->setX(0);
            else
                this->setX(af);
        }
        break;
    case 3:
        af = this->y() - PIX_PER_TIME;
        if(check(nx,ny-1) && onRoad(this->x(),af,key)){
            this->setY(af);
        }
        break;
    case 4:
        af = this->y() + PIX_PER_TIME;
        if(check(nx,ny+1) && onRoad(this->x(),af,key)){
            this->setY(af);
        }
        break;
    }
}

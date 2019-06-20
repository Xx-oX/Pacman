#include "machibuse.h"

Machibuse::Machibuse() : ghost(2)
{
}

void Machibuse::changeDirect(QPointF k)
{
    double dx = k.x() - this->x();
    double dy = k.y() - this->y();
    if(dx > 0){
        if(dy > 0){
            if(dx > dy){
                key = 4;
                s_key = 2;
                t_key = 3;
                f_key = 1;
            }
            else {
                key = 2;
                s_key = 4;
                t_key = 1;
                f_key = 3;
            }
        }
        else {
            if(dx > -dy){
                key = 3;
                s_key = 2;
                t_key = 4;
                f_key = 1;
            }
            else {
                key = 2;
                s_key = 3;
                t_key = 1;
                f_key = 4;
            }
        }
    }
    else {
        if(dy > 0){
            if(-dx > dy){
                key = 4;
                s_key = 1;
                t_key = 3;
                f_key = 2;
            }
            else {
                key = 1;
                s_key = 4;
                t_key = 2;
                f_key = 3;
            }
        }
        else {
            if(-dx > -dy){
                key = 3;
                s_key = 1;
                t_key = 4;
                f_key = 2;
            }
            else {
                key = 1;
                s_key = 3;
                t_key = 2;
                f_key = 4;
            }
        }
    }
}

void Machibuse::powerDirect(QPointF k)
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

void Machibuse::move()
{
    int af = 0;
    int nx = (this->x())/40;
    int ny = (this->y())/40;
    //qDebug()<<this->x()<<this->y()<<nx<<ny;
    bool ke = false,ske = false,tke = false;
    if(wall[nx][ny] == 2 || wall[nx][ny] == 0){
        if(isPower)
            powerDirect(pac);
        else
            changeDirect(pac);
        switch(key){
        case 1:
            ke = check(nx-1,ny) && onRoad(this->x()-PIX_PER_TIME,this->y(),key);
            break;
        case 2:
            ke = check(nx+1,ny) && onRoad(this->x()+PIX_PER_TIME,this->y(),key);
            break;
        case 3:
            ke = check(nx,ny-1) && onRoad(this->x(),this->y()-PIX_PER_TIME,key);
            break;
        case 4:
            ke = check(nx,ny+1) && onRoad(this->x(),this->y()+PIX_PER_TIME,key);
            break;
        }
        switch(s_key){
        case 1:
            ske = check(nx-1,ny) && onRoad(this->x()-PIX_PER_TIME,this->y(),s_key);
            break;
        case 2:
            ske = check(nx+1,ny) && onRoad(this->x()+PIX_PER_TIME,this->y(),s_key);
            break;
        case 3:
            ske = check(nx,ny-1) && onRoad(this->x(),this->y()-PIX_PER_TIME,s_key);
            break;
        case 4:
            ske = check(nx,ny+1) && onRoad(this->x(),this->y()+PIX_PER_TIME,s_key);
            break;
        }
        switch(t_key){
        case 1:
            tke = check(nx-1,ny) && onRoad(this->x()-PIX_PER_TIME,this->y(),t_key);
            break;
        case 2:
            tke = check(nx+1,ny) && onRoad(this->x()+PIX_PER_TIME,this->y(),t_key);
            break;
        case 3:
            tke = check(nx,ny-1) && onRoad(this->x(),this->y()-PIX_PER_TIME,t_key);
            break;
        case 4:
            tke = check(nx,ny+1) && onRoad(this->x(),this->y()+PIX_PER_TIME,t_key);
            break;
        }
        if(!ke){
            if(!ske){
                if(!tke){
                    key = f_key;
                }
                else {
                    key = t_key;
                }
            }
            else{
                key = s_key;
            }
        }
        else{
            key = key;
        }
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

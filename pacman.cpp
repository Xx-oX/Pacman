#include "pacman.h"

PacMan::PacMan()
{
    timeIsOdd = false;
    isTouched = false;
    key = 1;
    for(int i=0;i<27;++i){
        for(int j=0;j<24;++j){
            wall[i][j] = 0;
        }
    }
}

void PacMan::setImg()
{
    if(timeIsOdd){
        switch (key) {
            case 0:
                break;
            case 1:
                this->setPixmap(QPixmap(":/img/2D/res/img/2D/pacman_left_open.png"));
            break;
            case 2:
                this->setPixmap(QPixmap(":/img/2D/res/img/2D/pacman_right_open.png"));
            break;
            case 3:
                this->setPixmap(QPixmap(":/img/2D/res/img/2D/pacman_up_open.png"));
            break;
            case 4:
                this->setPixmap(QPixmap(":/img/2D/res/img/2D/pacman_down_open.png"));
            break;
        }
    }
    else{
        switch (key) {
            case 0:
                break;
            case 1:
                this->setPixmap(QPixmap(":/img/2D/res/img/2D/pacman_left_close.png"));
            break;
            case 2:
                this->setPixmap(QPixmap(":/img/2D/res/img/2D/pacman_right_close.png"));
            break;
            case 3:
                this->setPixmap(QPixmap(":/img/2D/res/img/2D/pacman_up_close.png"));
            break;
            case 4:
                this->setPixmap(QPixmap(":/img/2D/res/img/2D/pacman_down_close.png"));
            break;
        }
    }
    timeIsOdd = !timeIsOdd;
}

void PacMan::changeDirect(int k)
{
    switch (k) {
        case Qt::Key_Left:
            key = 1;
        break;
        case Qt::Key_Right:
            key = 2;
        break;
        case Qt::Key_Up:
            key = 3;
        break;
        case Qt::Key_Down:
            key = 4;
        break;
        case Qt::Key_A:
            key = 1;
        break;
        case Qt::Key_D:
            key = 2;
        break;
        case Qt::Key_W:
            key = 3;
        break;
        case Qt::Key_S:
            key = 4;
        break;
    }
}

void PacMan::move()
{
    int nx = (this->x())/40;
    int ny = (this->y())/40;
    int af = 0;
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
            if(af<-40)
                this->setY(960 - 40);
            else
                this->setY(af);
        }
        break;
    case 4:
        af = this->y() + PIX_PER_TIME;
        if(check(nx,ny+1) && onRoad(this->x(),af,key)){
            if(af<-960 - 40)
                this->setY(0);
            else
                this->setY(af);
        }
        break;
    }
}

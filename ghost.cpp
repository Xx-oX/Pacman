#include "ghost.h"

ghost::ghost(int t)
{
    type = t;
    timeIsOdd = false;
    isTouched = false;
    key = 1;
    for(int i=0;i<27;++i){
        for(int j=0;j<24;++j){
            wall[i][j] = 0;
        }
    }
}

void ghost::setImg()
{
    switch (type) {
    case 1:
        //oikake
        if(timeIsOdd){
            switch (key) {
                case 0:
                    break;
                case 1:
                    this->setPixmap(QPixmap(":/oikake/res/img/2D/Akabei/left_1.png"));
                break;
                case 2:
                    this->setPixmap(QPixmap(":/oikake/res/img/2D/Akabei/right_1.png"));
                break;
                case 3:
                    this->setPixmap(QPixmap(":/oikake/res/img/2D/Akabei/up_1.png"));
                break;
                case 4:
                    this->setPixmap(QPixmap(":/oikake/res/img/2D/Akabei/down_1.png"));
                break;
            }
        }
        else{
            switch (key) {
                case 0:
                    break;
                case 1:
                    this->setPixmap(QPixmap(":/oikake/res/img/2D/Akabei/left_2.png"));
                break;
                case 2:
                    this->setPixmap(QPixmap(":/oikake/res/img/2D/Akabei/right_2.png"));
                break;
                case 3:
                    this->setPixmap(QPixmap(":/oikake/res/img/2D/Akabei/up_2.png"));
                break;
                case 4:
                    this->setPixmap(QPixmap(":/oikake/res/img/2D/Akabei/down_2.png"));
                break;
            }
        }
        timeIsOdd = !timeIsOdd;
        break;
    case 2:
        //machibuse
        if(timeIsOdd){
            switch (key) {
                case 0:
                    break;
                case 1:
                    this->setPixmap(QPixmap(":/machibuse/res/img/2D/Pinky/left_1.png"));
                break;
                case 2:
                    this->setPixmap(QPixmap(":/machibuse/res/img/2D/Pinky/right_1.png"));
                break;
                case 3:
                    this->setPixmap(QPixmap(":/machibuse/res/img/2D/Pinky/up_1.png"));
                break;
                case 4:
                    this->setPixmap(QPixmap(":/machibuse/res/img/2D/Pinky/down_1.png"));
                break;
            }
        }
        else{
            switch (key) {
                case 0:
                    break;
                case 1:
                    this->setPixmap(QPixmap(":/machibuse/res/img/2D/Pinky/left_2.png"));
                break;
                case 2:
                    this->setPixmap(QPixmap(":/machibuse/res/img/2D/Pinky/right_2.png"));
                break;
                case 3:
                    this->setPixmap(QPixmap(":/machibuse/res/img/2D/Pinky/up_2.png"));
                break;
                case 4:
                    this->setPixmap(QPixmap(":/machibuse/res/img/2D/Pinky/down_2.png"));
                break;
            }
        }
        timeIsOdd = !timeIsOdd;
        break;
    case 3:
        //kimagure
        if(timeIsOdd){
            switch (key) {
                case 0:
                    break;
                case 1:
                    this->setPixmap(QPixmap(":/kimagure/res/img/2D/Aosuke/left_1.png"));
                break;
                case 2:
                    this->setPixmap(QPixmap(":/kimagure/res/img/2D/Aosuke/right_1.png"));
                break;
                case 3:
                    this->setPixmap(QPixmap(":/kimagure/res/img/2D/Aosuke/up_1.png"));
                break;
                case 4:
                    this->setPixmap(QPixmap(":/kimagure/res/img/2D/Aosuke/down_1.png"));
                break;
            }
        }
        else{
            switch (key) {
                case 0:
                    break;
                case 1:
                    this->setPixmap(QPixmap(":/kimagure/res/img/2D/Aosuke/left_2.png"));
                break;
                case 2:
                    this->setPixmap(QPixmap(":/kimagure/res/img/2D/Aosuke/right_2.png"));
                break;
                case 3:
                    this->setPixmap(QPixmap(":/kimagure/res/img/2D/Aosuke/up_2.png"));
                break;
                case 4:
                    this->setPixmap(QPixmap(":/kimagure/res/img/2D/Aosuke/down_2.png"));
                break;
            }
        }
        timeIsOdd = !timeIsOdd;
        break;
    case 4:
        //otoboke
        if(timeIsOdd){
            switch (key) {
                case 0:
                    break;
                case 1:
                    this->setPixmap(QPixmap(":/otoboke/res/img/2D/Guzuta/left_1.png"));
                break;
                case 2:
                    this->setPixmap(QPixmap(":/otoboke/res/img/2D/Guzuta/right_1.png"));
                break;
                case 3:
                    this->setPixmap(QPixmap(":/otoboke/res/img/2D/Guzuta/up_1.png"));
                break;
                case 4:
                    this->setPixmap(QPixmap(":/otoboke/res/img/2D/Guzuta/down_1.png"));
                break;
            }
        }
        else{
            switch (key) {
                case 0:
                    break;
                case 1:
                    this->setPixmap(QPixmap(":/otoboke/res/img/2D/Guzuta/left_2.png"));
                break;
                case 2:
                    this->setPixmap(QPixmap(":/otoboke/res/img/2D/Guzuta/right_2.png"));
                break;
                case 3:
                    this->setPixmap(QPixmap(":/otoboke/res/img/2D/Guzuta/up_2.png"));
                break;
                case 4:
                    this->setPixmap(QPixmap(":/otoboke/res/img/2D/Guzuta/down_2.png"));
                break;
            }
        }
        timeIsOdd = !timeIsOdd;
        break;
    }
}

void ghost::setScare()
{
    if(timeIsOdd){
        this->setPixmap(QPixmap(":/img/2D/res/img/2D/scared_1.png"));
    }
    else{
        this->setPixmap(QPixmap(":/img/2D/res/img/2D/scared_2.png"));
    }
    timeIsOdd = !timeIsOdd;
}

void ghost::getPac(QPointF k)
{
    pac = k;
}


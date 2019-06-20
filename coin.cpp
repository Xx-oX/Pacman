#include "coin.h"

Coin::Coin()
{
    power = false;
}

void Coin::setImg()
{
    if(alive){
        if(power)
        {
            this->setPixmap(QPixmap(":/img/2D/res/img/2D/power_pellets.png"));
            this->show();
        }
        else {
            this->setPixmap(QPixmap(":/img/2D/res/img/2D/coin.png"));
            this->show();
        }
    }
    else {
        this->hide();
    }
}

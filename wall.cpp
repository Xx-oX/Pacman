#include "wall.h"

Wall::Wall()
{

}

void Wall::setImg()
{
    if(exists){
        this->setPixmap(QPixmap(":/img/2D/res/img/2D/wall_inside.png"));
        this->show();
    }
    else {
        this->hide();
    }
}

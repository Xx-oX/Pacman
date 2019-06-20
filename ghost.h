#ifndef GHOST_H
#define GHOST_H

#include "character.h"

#define PIX_PER_TIME 40

class ghost : public Character
{
public:
    ghost(int);

    int type;
    QPointF pac;

    void setImg();
    void setScare();

    void getPac(QPointF);

};

#endif // GHOST_H

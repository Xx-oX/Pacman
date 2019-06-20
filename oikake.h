#ifndef OIKAKE_H
#define OIKAKE_H

#include "ghost.h"

#define PIX_PER_TIME 40

class Oikake : public ghost
{
public:
    explicit Oikake();

    void changeDirect(QPointF);
    void powerDirect(QPointF);
    void move();
};

#endif // OIKAKE_H

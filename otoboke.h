#ifndef OTOBOKE_H
#define OTOBOKE_H

#include "ghost.h"

#define PIX_PER_TIME 40

class Otoboke : public ghost
{
public:
    explicit Otoboke();

    void changeDirect(QPointF);
    void powerDirect(QPointF);
    void move();
};

#endif // OTOBOKE_H

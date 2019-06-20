#ifndef KIMAGURE_H
#define KIMAGURE_H

#include "ghost.h"

#define PIX_PER_TIME 40

class Kimagure : public ghost
{
public:
    explicit Kimagure();

    void changeDirect(QPointF);
    void powerDirect(QPointF);
    void move();
};

#endif // KIMAGURE_H

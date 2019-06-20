#ifndef MACHIBUSE_H
#define MACHIBUSE_H

#include "ghost.h"

#define PIX_PER_TIME 40

class Machibuse : public ghost
{
public:
    explicit Machibuse();

    void changeDirect(QPointF);
    void powerDirect(QPointF);
    void move();
};

#endif // MACHIBUSE_H

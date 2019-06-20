#ifndef PACMAN_H
#define PACMAN_H

#include "character.h"

#define PIX_PER_TIME 40

class PacMan : public Character
{
public:
    PacMan();

    void setImg();
    void changeDirect(int);
    void move();

};

#endif // PACMAN_H

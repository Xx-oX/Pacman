#ifndef WALL_H
#define WALL_H
#include <QGraphicsPixmapItem>

class Wall : public QGraphicsPixmapItem
{
public:
    Wall();

    bool exists;

    void setImg();

};

#endif // WALL_H

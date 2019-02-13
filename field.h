#ifndef FIELD_H
#define FIELD_H
#include <QGraphicsRectItem>

#include "destroyableblock.h"
#include "undestroyableblock.h"
#include "explosion.h"
#include "bomb.h"

class Field : public QGraphicsRectItem{
public:
    Field();
    Field(int x, int y);
    void setUnDestroyableBlock(UnDestroyableBlock * unDestroyableBlock);
    bool isClear();
private:
    int _x;
    int _y;
    DestroyableBlock * _destroyableBlock = nullptr;
    UnDestroyableBlock * _unDestroyableBlock = nullptr;
    Explosion * _explosion = nullptr;
    Bomb * _bomb = nullptr;
};

#endif // FIELD_H

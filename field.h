#ifndef FIELD_H
#define FIELD_H
#include <QGraphicsRectItem>

#include "destroyableblock.h"
#include "undestroyableblock.h"
#include "explosion.h"
#include "bomb.h"

class Field : public QGraphicsRectItem{
public:
    Field() = default;
    Field(int x, int y);
    ~Field();
    void setUnDestroyableBlock(UnDestroyableBlock * unDestroyableBlock);
    void setDestoryableBlock(DestroyableBlock * destroyableBlock);
    void setBomb(Bomb * bomb);
    void playerOn();
    void playerOut();
    bool isClear();

private:
    int _x;
    int _y;
    bool _isPlayerOn;
    DestroyableBlock * _destroyableBlock = nullptr;
    UnDestroyableBlock * _unDestroyableBlock = nullptr;
    Explosion * _explosion = nullptr;
    Bomb * _bomb = nullptr;
};

#endif // FIELD_H

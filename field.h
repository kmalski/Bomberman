#ifndef FIELD_H
#define FIELD_H
#include <QGraphicsRectItem>
#include <QObject>

#include "destroyableblock.h"
#include "undestroyableblock.h"
#include "explosion.h"
#include "bomb.h"

class Field : public QObject, public QGraphicsRectItem {

    Q_OBJECT

public:
    Field(int x, int y, QObject *parent = nullptr);
    ~Field();
    void setUnDestroyableBlock(UnDestroyableBlock * unDestroyableBlock);
    void setDestoryableBlock(DestroyableBlock * destroyableBlock);
    void setBomb(Bomb * bomb);
    void playerOn();
    void playerOut();
    bool isClear();

public slots:
//    void exploded(std::vector<std::vector<Field *> >& fields);

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

#ifndef FIELD_H
#define FIELD_H

#include <QGraphicsPixmapItem>
#include <QObject>

#include "destroyableblock.h"
#include "undestroyableblock.h"
#include "explosion.h"
#include "bomb.h"

class Player;

class Field : public QObject, public QGraphicsPixmapItem {

    Q_OBJECT

public:
    Field(int x, int y, QObject *parent = nullptr);
    ~Field();
    void setUnDestroyableBlock(UnDestroyableBlock * unDestroyableBlock);
    void setDestoryableBlock(DestroyableBlock * destroyableBlock);
    void setBomb(Bomb * bomb);
    void playerOn();
    void playerOut();
    bool isBomb() const;
    bool isClear() const;

public slots:
    void explosion();

signals:
    void decreaseHP();

private:
    void createPixmapItem(QGraphicsPixmapItem *item, QString path) const;
    void createExplosion();

    int _x;
    int _y;
    bool _isPlayerOn;
    DestroyableBlock * _destroyableBlock = nullptr;
    UnDestroyableBlock * _unDestroyableBlock = nullptr;
    Explosion * _explosion = nullptr;
    Bomb * _bomb = nullptr;
};

#endif // FIELD_H

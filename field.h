#ifndef FIELD_H
#define FIELD_H

#include <QGraphicsPixmapItem>
#include <QObject>

#include "destroyableblock.h"
#include "undestroyableblock.h"
#include "explosion.h"
#include "bomb.h"
#include "settings.h"
#include "healthpowerup.h"
#include "bombpowerup.h"
#include "explosionpowerup.h"

enum blockType {
    Destroyable,
    Undestroyable,
    Empty
};

class Player;

class Field : public QObject, public QGraphicsPixmapItem {

    Q_OBJECT

public:
    Field(int x, int y, QObject *parent = nullptr);
    ~Field();
    blockType isBlockOnField() const;
    void setUnDestroyableBlock(UnDestroyableBlock * unDestroyableBlock);
    void setDestoryableBlock(DestroyableBlock * destroyableBlock);
    void setBomb(Bomb * bomb);
    void playerOn(Player * player);
    void playerOut(Player * player);
    void getPowerUp(Player * player);
    bool isBomb() const;
    bool isUnDestroyableBlock() const;
    bool isClear() const;

public slots:
    void explosion();

private:
    void createPixmapItem(QGraphicsPixmapItem *item, QString path) const;
    void createExplosion();
    void randPowerUp();

    int _x;
    int _y;
    bool _isPlayerOn;
    DestroyableBlock * _destroyableBlock = nullptr;
    UnDestroyableBlock * _unDestroyableBlock = nullptr;
    Explosion * _explosion = nullptr;
    Bomb * _bomb = nullptr;
    Player * _players[sizes::Players];
    PowerUp * _powerUp = nullptr;
};

#endif // FIELD_H

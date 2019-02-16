#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsPixmapItem>

#include "field.h"

enum direction {
    Left,
    Right,
    Down,
    Up
};

class Player : public QObject, public QGraphicsPixmapItem
{

    Q_OBJECT

public:
    Player(int x, int y, QObject *parent = nullptr);
    ~Player();
    int getX() const;
    int getY() const;
    void move(direction dir, std::vector<std::vector<Field *>>& fields);
    void plantBomb(std::vector<std::vector<Field *>>& fields);
    void setX(int x);
    void setY(int y);
    void decreaseHP(Field * field);
    void addBomb();
    void increaseExplosionSize();
    void increaseHP();

signals:
    void playerDied();

private:
    Field *getField(int x, int y, std::vector<std::vector<Field *>>& fields) const;
    void connectBomb(int x, int y, Bomb *bomb, std::vector<std::vector<Field *> >& fields, bool& flag);

    int _x;
    int _y;
    int _health;
    int _maxBombs;
    int _explosionSize;

};

#endif // PLAYER_H

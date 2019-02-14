#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsRectItem>

#include "field.h"

enum direction {
    Left,
    Right,
    Down,
    Up
};

class Player : public QObject, public QGraphicsRectItem
{

    Q_OBJECT

public:
    Player(int x, int y, QColor color);
    ~Player() = default;
    void move(direction dir, std::vector<std::vector<Field *>>& fields);
    void plantBomb(std::vector<std::vector<Field *>>& fields);
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);

private:
    int _x;
    int _y;

};

#endif // PLAYER_H

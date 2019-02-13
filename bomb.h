#ifndef BOMB_H
#define BOMB_H

#include <QObject>
#include <QGraphicsRectItem>

class Bomb : public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    explicit Bomb(int x, int y);

private:
    int _x;
    int _y;
};

#endif // BOMB_H

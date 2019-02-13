#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsRectItem>

class Player : public QObject, public QGraphicsRectItem
{

    Q_OBJECT

public:
    Player(int x, int y);
    ~Player() = default;
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);

private:
    void plantBomb();
    int _x;
    int _y;

};

#endif // PLAYER_H

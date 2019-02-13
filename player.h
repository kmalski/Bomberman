#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsRectItem>

enum direction {
    Left,
    Right,
    Up,
    Down
};

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

//public slots:
//    void controlPlayer1(direction dir);
//    void controlPlayer2(direction dir);

private:
    void plantBomb();
    int _x;
    int _y;

};

#endif // PLAYER_H

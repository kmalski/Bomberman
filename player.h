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
    Player();
    ~Player() = default;
    void keyPressEvent(QKeyEvent *event);

signals:
    void controlPlayer(int& x, int& y, direction dir);

private:
    void plantBomb();
    int _x = 0;
    int _y = 0;

};

#endif // PLAYER_H

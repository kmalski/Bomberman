#include <QKeyEvent>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "player.h"
#include "bomb.h"
#include "settings.h"

Player::Player(int x, int y)
{
    _x = x;
    _y = y;
    setRect(x * sizes::FieldSize, y * sizes::FieldSize, sizes::FieldSize, sizes::FieldSize);
    setBrush(QColor(Qt::red));
}

int Player::getX() {
    return _x;
}

int Player::getY() {
    return _y;
}

void Player::setX(int x) {
    _x = x;
    setPos(_x * sizes::FieldSize, _y * sizes::FieldSize);
}

void Player::setY(int y) {
    _y = y;
    setPos(_x * sizes::FieldSize, _y * sizes::FieldSize);
}

//void Player::controlPlayer1(direction dir)
//{

//}

//void Player::controlPlayer2(direction dir)
//{

//}

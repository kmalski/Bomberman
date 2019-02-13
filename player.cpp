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
    setRect(0, 0, sizes::FieldSize, sizes::FieldSize);
    setPos(x * sizes::FieldSize, y * sizes::FieldSize);
    setBrush(QColor(Qt::red));
}

void Player::plantBomb(std::vector<std::vector<Field *> >& fields)
{
    fields[static_cast<size_t>(_y)][static_cast<size_t>(_x)]->setBomb(new Bomb());
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

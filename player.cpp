#include <QKeyEvent>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "player.h"
#include "bomb.h"
#include "settings.h"

Player::Player(int x, int y, QColor color) {
    _x = x;
    _y = y;
    setRect(0, 0, sizes::FieldSize, sizes::FieldSize);
    setPos(x * sizes::FieldSize, y * sizes::FieldSize);
    setBrush(color);
}

void Player::move(direction dir, std::vector<std::vector<Field *> > &fields) {
    if(dir == Left) {
        if (_x > 0 && fields[static_cast<size_t>(_y)][static_cast<size_t>(_x-1)]->isClear()) {
            fields[static_cast<size_t>(_y)][static_cast<size_t>(_x)]->playerOut();
            fields[static_cast<size_t>(_y)][static_cast<size_t>(_x-1)]->playerOn();
            --_x;
            setPos(_x * sizes::FieldSize, _y * sizes::FieldSize);
        }
    }
    else if (dir == Right) {
        if (_x < sizes::Columns - 1 && fields[static_cast<size_t>(_y)][static_cast<size_t>(_x+1)]->isClear()) {
            fields[static_cast<size_t>(_y)][static_cast<size_t>(_x)]->playerOut();
            fields[static_cast<size_t>(_y)][static_cast<size_t>(_x+1)]->playerOn();
            ++_x;
            setPos(_x * sizes::FieldSize, _y * sizes::FieldSize);
        }
    }
    else if (dir == Down) {
        if (_y < sizes::Rows - 1 && fields[static_cast<size_t>(_y+1)][static_cast<size_t>(_x)]->isClear()) {
            fields[static_cast<size_t>(_y)][static_cast<size_t>(_x)]->playerOut();
            fields[static_cast<size_t>(_y+1)][static_cast<size_t>(_x)]->playerOn();
            ++_y;
            setPos(_x * sizes::FieldSize, _y * sizes::FieldSize);
        }
    }
    else if (dir == Up) {
        if (_y > 0 && fields[static_cast<size_t>(_y-1)][static_cast<size_t>(_x)]->isClear()) {
            fields[static_cast<size_t>(_y)][static_cast<size_t>(_x)]->playerOut();
            fields[static_cast<size_t>(_y-1)][static_cast<size_t>(_x)]->playerOn();
            --_y;
            setPos(_x * sizes::FieldSize, _y * sizes::FieldSize);
        }
    }
}

void Player::plantBomb(std::vector<std::vector<Field *> >& fields) {
    Bomb *bomb = new Bomb();
    fields[static_cast<size_t>(_y)][static_cast<size_t>(_x)]->setBomb(bomb);
    //connect(this, SIGNAL(explode(fields)), fields[static_cast<size_t>(_y)][static_cast<size_t>(_x)], SLOT(exploded(fields)));
}

int Player::getX() {
    return _x;
}

int Player::getY() {
    return _y;
}

void Player::setX(int x) {
    _x = x;
}

void Player::setY(int y) {
    _y = y;
}

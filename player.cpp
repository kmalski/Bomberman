#include <QKeyEvent>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "player.h"
#include "bomb.h"
#include "settings.h"

Player::Player(int x, int y, QObject *parent)  : QObject (parent) {
    _x = x;
    _y = y;
    setPos(x * sizes::FieldSize, y * sizes::FieldSize);
    setPixmap(QPixmap(":/img/img/player_front.png"));
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
    if(fields[static_cast<size_t>(_y)][static_cast<size_t>(_x)]->isBomb() == false) {
        Bomb *bomb = new Bomb();
        fields[static_cast<size_t>(_y)][static_cast<size_t>(_x)]->setBomb(bomb);

        connect(bomb, SIGNAL(explode()), fields[static_cast<size_t>(_y)][static_cast<size_t>(_x)], SLOT(explosion())); //connect always
        if (_x + 1 < sizes::Columns) {
            connect(bomb, SIGNAL(explode()), fields[static_cast<size_t>(_y)][static_cast<size_t>(_x + 1)], SLOT(explosion())); //connect on right
        }
        if (_x - 1 > 0) {
            connect(bomb, SIGNAL(explode()), fields[static_cast<size_t>(_y)][static_cast<size_t>(_x - 1)], SLOT(explosion())); //connect on left
        }
        if (_y - 1 > 0) {
            connect(bomb, SIGNAL(explode()), fields[static_cast<size_t>(_y - 1)][static_cast<size_t>(_x)], SLOT(explosion())); //connect on up
        }
        if (_y + 1 < sizes::Rows) {
            connect(bomb, SIGNAL(explode()), fields[static_cast<size_t>(_y + 1)][static_cast<size_t>(_x)], SLOT(explosion())); //connect on down
        }

        QTimer::singleShot(2000, bomb, &Bomb::emitExplode);
    }
}

int Player::getX() const {
    return _x;
}

int Player::getY() const {
    return _y;
}

void Player::setX(int x) {
    _x = x;
}

void Player::setY(int y) {
    _y = y;
}

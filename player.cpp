#include <QKeyEvent>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>

#include "player.h"
#include "bomb.h"
#include "settings.h"

Player::Player(int x, int y, QObject *parent)  : QObject (parent) {
    _x = x;
    _y = y;
    _health = sizes::Health;
    _maxBombs = sizes::Bombs;
    _explosionSize = sizes::ExplosionRange;
    setPos(x * sizes::FieldSize, y * sizes::FieldSize);
    setPixmap(QPixmap(":/img/img/player_front.png"));
}

Player::~Player() {
    scene()->removeItem(this);
}

void Player::move(direction dir, std::vector<std::vector<Field *> > &fields) {
    if(dir == Left) {
        if (_x > 0 && getField(_x - 1, _y, fields)->isClear()) {
            getField(_x, _y, fields)->playerOut(this);
            getField(_x - 1, _y, fields)->playerOn(this);
            --_x;
            setPos(_x * sizes::FieldSize, _y * sizes::FieldSize);
            getField(_x, _y, fields)->getPowerUp(this);
        }
    }
    else if (dir == Right) {
        if (_x < sizes::Columns - 1 && getField(_x + 1, _y, fields)->isClear()) {
            getField(_x, _y, fields)->playerOut(this);
            getField(_x + 1, _y, fields)->playerOn(this);
            ++_x;
            setPos(_x * sizes::FieldSize, _y * sizes::FieldSize);
            getField(_x, _y, fields)->getPowerUp(this);
        }
    }
    else if (dir == Down) {
        if (_y < sizes::Rows - 1 && getField(_x, _y + 1, fields)->isClear()) {
            getField(_x, _y, fields)->playerOut(this);
            getField(_x, _y + 1, fields)->playerOn(this);
            ++_y;
            setPos(_x * sizes::FieldSize, _y * sizes::FieldSize);
            getField(_x, _y, fields)->getPowerUp(this);
        }
    }
    else if (dir == Up) {
        if (_y > 0 && getField(_x, _y - 1, fields)->isClear()) {
            getField(_x, _y, fields)->playerOut(this);
            getField(_x, _y - 1, fields)->playerOn(this);
            --_y;
            setPos(_x * sizes::FieldSize, _y * sizes::FieldSize);
            getField(_x, _y, fields)->getPowerUp(this);
        }
    }
}

void Player::plantBomb(std::vector<std::vector<Field *> >& fields) {
    if(_maxBombs > 0) {
        if(getField(_x, _y, fields)->isBomb() == false) {
            Bomb *bomb = new Bomb(&_maxBombs);
            getField(_x, _y, fields)->setBomb(bomb);

            connect(bomb, SIGNAL(explode()), getField(_x, _y, fields), SLOT(explosion())); //connect always
            bool flagLeft = true, flagRight = true, flagUp = true, flagDown = true;
            for(int i = 1; i <= _explosionSize; i++) {
                if (flagRight && _x + i < sizes::Columns) {
                    connectBomb(_x + i, _y, bomb, fields, flagRight);
                }

                if (flagLeft && _x - i >= 0) {
                    connectBomb(_x - i, _y, bomb, fields, flagLeft);
                }

                if (flagUp && _y - i >= 0) {
                    connectBomb(_x, _y - i, bomb, fields, flagUp);
                }

                if (flagDown && _y + i < sizes::Rows) {
                    connectBomb(_x, _y + i, bomb, fields, flagDown);
                }
            }

            _maxBombs--;

            QTimer::singleShot(2000, bomb, &Bomb::emitExplode);
        }
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

void Player::decreaseHP(Field * field)
{
    _health--;
    if(_health == 0) {
        field->playerOut(this);
        emit playerDied();
        delete this;
    }
}

void Player::addBomb() {
    _maxBombs++;
}

void Player::increaseExplosionSize() {
    _explosionSize++;
}

void Player::increaseHP() {
    _health++;
}

Field *Player::getField(int x, int y, std::vector<std::vector<Field *> > &fields) const {
    return fields[static_cast<size_t>(y)][static_cast<size_t>(x)];
}

void Player::connectBomb(int x, int y, Bomb *bomb, std::vector<std::vector<Field *> >& fields, bool& flag) {
    if (getField(x, y, fields)->isBlockOnField() != Undestroyable)
        connect(bomb, SIGNAL(explode()), getField(x, y, fields), SLOT(explosion()));
    else
        flag = false;
    if (getField(x, y, fields)->isBlockOnField() == Destroyable)
        flag = false;
}

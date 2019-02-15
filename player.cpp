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
    _health = 3;
    _maxBombs = 2;
    _explosionSize = 3;
    setPos(x * sizes::FieldSize, y * sizes::FieldSize);
    setPixmap(QPixmap(":/img/img/player_front.png"));
}

Player::~Player() {
    scene()->removeItem(this);
}

void Player::move(direction dir, std::vector<std::vector<Field *> > &fields) {
    if(dir == Left) {
        if (_x > 0 && fields[static_cast<size_t>(_y)][static_cast<size_t>(_x-1)]->isClear()) {
            fields[static_cast<size_t>(_y)][static_cast<size_t>(_x)]->playerOut();
            fields[static_cast<size_t>(_y)][static_cast<size_t>(_x-1)]->playerOn(this);
            --_x;
            setPos(_x * sizes::FieldSize, _y * sizes::FieldSize);
        }
    }
    else if (dir == Right) {
        if (_x < sizes::Columns - 1 && fields[static_cast<size_t>(_y)][static_cast<size_t>(_x+1)]->isClear()) {
            fields[static_cast<size_t>(_y)][static_cast<size_t>(_x)]->playerOut();
            fields[static_cast<size_t>(_y)][static_cast<size_t>(_x+1)]->playerOn(this);
            ++_x;
            setPos(_x * sizes::FieldSize, _y * sizes::FieldSize);
        }
    }
    else if (dir == Down) {
        if (_y < sizes::Rows - 1 && fields[static_cast<size_t>(_y+1)][static_cast<size_t>(_x)]->isClear()) {
            fields[static_cast<size_t>(_y)][static_cast<size_t>(_x)]->playerOut();
            fields[static_cast<size_t>(_y+1)][static_cast<size_t>(_x)]->playerOn(this);
            ++_y;
            setPos(_x * sizes::FieldSize, _y * sizes::FieldSize);
        }
    }
    else if (dir == Up) {
        if (_y > 0 && fields[static_cast<size_t>(_y-1)][static_cast<size_t>(_x)]->isClear()) {
            fields[static_cast<size_t>(_y)][static_cast<size_t>(_x)]->playerOut();
            fields[static_cast<size_t>(_y-1)][static_cast<size_t>(_x)]->playerOn(this);
            --_y;
            setPos(_x * sizes::FieldSize, _y * sizes::FieldSize);
        }
    }
}

void Player::plantBomb(std::vector<std::vector<Field *> >& fields) {
    if(_maxBombs > 0) {
        if(fields[static_cast<size_t>(_y)][static_cast<size_t>(_x)]->isBomb() == false) {
            Bomb *bomb = new Bomb(&_maxBombs);
            fields[static_cast<size_t>(_y)][static_cast<size_t>(_x)]->setBomb(bomb);

            connect(bomb, SIGNAL(explode()), fields[static_cast<size_t>(_y)][static_cast<size_t>(_x)], SLOT(explosion())); //connect always
            bool flagLeft = true, flagRight = true, flagUp = true, flagDown = true;
            for(int i = 1; i <= _explosionSize; i++) {
                if (flagRight && _x + i < sizes::Columns && !fields[static_cast<size_t>(_y)][static_cast<size_t>(_x + i)]->isUnDestroyableBlock()) {
                    connect(bomb, SIGNAL(explode()), fields[static_cast<size_t>(_y)][static_cast<size_t>(_x + i)], SLOT(explosion())); //connect on right
                }
                else {
                    flagRight = false;
                }

                if (flagLeft && _x - i >= 0 && !fields[static_cast<size_t>(_y)][static_cast<size_t>(_x - i)]->isUnDestroyableBlock()) {
                    connect(bomb, SIGNAL(explode()), fields[static_cast<size_t>(_y)][static_cast<size_t>(_x - i)], SLOT(explosion())); //connect on left
                }
                else {
                    flagLeft = false;
                }

                if (flagUp && _y - i >= 0 && !fields[static_cast<size_t>(_y - i)][static_cast<size_t>(_x)]->isUnDestroyableBlock()) {
                    connect(bomb, SIGNAL(explode()), fields[static_cast<size_t>(_y - i)][static_cast<size_t>(_x)], SLOT(explosion())); //connect on up
                }
                else {
                    flagUp = false;
                }

                if (flagDown && _y + i < sizes::Rows && !fields[static_cast<size_t>(_y + i)][static_cast<size_t>(_x)]->isUnDestroyableBlock()) {
                    connect(bomb, SIGNAL(explode()), fields[static_cast<size_t>(_y + i)][static_cast<size_t>(_x)], SLOT(explosion())); //connect on down
                }
                else {
                    flagDown = false;
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
    qDebug() << "Boom health: " << _health;
    if(_health == 0) {
        field->playerOut();
        delete this;
    }
}

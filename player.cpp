#include <QKeyEvent>
#include <QTimer>
#include <QGraphicsScene>

#include "player.h"
#include "bomb.h"
#include "settings.h"

Player::Player(int x, int y)
{
    _x = x;
    _y = y;
    setRect(x * sizes::FieldSize, y * sizes::FieldSize , sizes::FieldSize, sizes::FieldSize);
    setBrush(QColor(Qt::red));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left) {
        if (pos().x() > 0) {
            emit controlPlayer1(Left);
        }
    }
    else if (event->key() == Qt::Key_Right) {
        if (pos().x() + rect().width() < scene()->width()) {
            emit controlPlayer1(Right);
        }
    }
    else if (event->key() == Qt::Key_Down) {
        if (pos().y() + rect().height() < scene()->height()) {
            emit controlPlayer1(Down);
        }
    }
    else if (event->key() == Qt::Key_Up) {
        if (pos().y() > 0) {
            emit controlPlayer1(Up);
        }
    }
    else if (event->key() == Qt::Key_A) {
            emit controlPlayer2(Left);
    }
    else if (event->key() == Qt::Key_D) {
            emit controlPlayer2(Right);
    }
    else if (event->key() == Qt::Key_S) {
            emit controlPlayer2(Down);
    }
    else if (event->key() == Qt::Key_W) {
            emit controlPlayer2(Up);
    }
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

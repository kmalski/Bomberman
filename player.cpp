#include <QKeyEvent>

#include "player.h"

Player::Player()
{
    setRect(0, 0 , 100, 100);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left) {
        if (pos().x() > 0) {
            setPos(x() - 15, y());
        }
    }
    else if (event->key() == Qt::Key_Right) {
        if (pos().x() + 100 < 800) {
            setPos(x() + 15, y());
        }
    }
    else if (event->key() == Qt::Key_Down) {
        if (pos().y() + 100 < 600) {
            setPos(x(), y() + 15);
        }
    }
    else if (event->key() == Qt::Key_Up) {
        if (pos().y() > 0) {
            setPos(x(), y() - 15);
        }
    }

}

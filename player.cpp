#include <QKeyEvent>
#include <QTimer>
#include <QGraphicsScene>

#include "player.h"
#include "bomb.h"

Player::Player()
{
    setRect(0, 0 , 50, 50);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    setBrush(QColor(Qt::red));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left) {
        if (pos().x() > 0) {
            setPos(x() - 50, y());
        }
    }
    else if (event->key() == Qt::Key_Right) {
        if (pos().x() + rect().width() < scene()->width()) {
            setPos(x() + 50, y());
        }
    }
    else if (event->key() == Qt::Key_Down) {
        if (pos().y() + rect().height() < scene()->height()) {
            setPos(x(), y() + 50);
        }
    }
    else if (event->key() == Qt::Key_Up) {
        if (pos().y() > 0) {
            setPos(x(), y() - 50);
        }
    }
    else if (event->key() == Qt::Key_Up && event->key() == Qt::Key_Left ) {
            setPos(x() - 50, y() - 50);
    }

}

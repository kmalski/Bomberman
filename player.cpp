#include <QKeyEvent>
#include <QTimer>
#include <QGraphicsScene>

#include "player.h"
#include "bomb.h"
#include "settings.h"

Player::Player()
{
    setRect(0, 0 , sizes::FieldSize, sizes::FieldSize);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    setBrush(QColor(Qt::red));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left || event->key() == Qt::Key_A) {
        if (pos().x() > 0) {
            setPos(x() - sizes::FieldSize, y());
        }
    }
    else if (event->key() == Qt::Key_Right || event->key() == Qt::Key_D) {
        if (pos().x() + rect().width() < scene()->width()) {
            setPos(x() + sizes::FieldSize, y());
        }
    }
    else if (event->key() == Qt::Key_Down || event->key() == Qt::Key_S) {
        if (pos().y() + rect().height() < scene()->height()) {
            setPos(x(), y() + sizes::FieldSize);
        }
    }
    else if (event->key() == Qt::Key_Up || event->key() == Qt::Key_W) {
        if (pos().y() > 0) {
            setPos(x(), y() - sizes::FieldSize);
        }
    }
}

#ifndef BOMB_H
#define BOMB_H

#include <QObject>
#include <QGraphicsRectItem>

class Field;

class Bomb : public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    explicit Bomb() = default;
    ~Bomb();
    void emitExplode();

signals:
    void explode();

};

#endif // BOMB_H

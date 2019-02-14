#ifndef BOMB_H
#define BOMB_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Bomb : public QObject, public QGraphicsPixmapItem
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

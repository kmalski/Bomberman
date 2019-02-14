#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <QGraphicsRectItem>
#include <QObject>

class Explosion : public QGraphicsRectItem, public QObject  {
public:
    Explosion() = default;
    ~Explosion();
    void removeExplosion();
};

#endif // EXPLOSION_H

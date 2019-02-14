#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Explosion : public QGraphicsPixmapItem, public QObject  {
public:
    Explosion() = default;
    ~Explosion();
    void removeExplosion();
};

#endif // EXPLOSION_H

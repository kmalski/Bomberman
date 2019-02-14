#include <QGraphicsScene>

#include "bomb.h"
#include "settings.h"

Bomb::Bomb() {
}

Bomb::~Bomb()
{
    scene()->removeItem(this);
}

void Bomb::emitExplode()
{
    emit explode();
    delete this;
}

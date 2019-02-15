#include <QGraphicsScene>

#include "bomb.h"
#include "settings.h"

Bomb::Bomb(int *maxBombs) : _maxBombs(maxBombs){ }

Bomb::~Bomb() {
    scene()->removeItem(this);
}

void Bomb::emitExplode() {
    emit explode();
    (*_maxBombs)++;
    delete this;
}

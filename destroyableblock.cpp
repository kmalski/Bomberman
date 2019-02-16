#include <QGraphicsScene>

#include "destroyableblock.h"

DestroyableBlock::~DestroyableBlock() {
    scene()->removeItem(this);
}

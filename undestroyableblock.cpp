#include <QGraphicsScene>

#include "undestroyableblock.h"

UnDestroyableBlock::~UnDestroyableBlock() {
    scene()->removeItem(this);
}

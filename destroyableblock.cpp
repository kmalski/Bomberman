#include <QGraphicsScene>

#include "destroyableblock.h"

DestroyableBlock::DestroyableBlock() {

}

DestroyableBlock::~DestroyableBlock()
{
    scene()->removeItem(this);
}

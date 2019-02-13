#include<QGraphicsScene>

#include "field.h"
#include "settings.h"

Field::Field() {

}

Field::Field(int x, int y) : _x(x), _y(y) {
    setRect(x, y, sizes::FieldSize, sizes::FieldSize);
}

void Field::setUnDestroyableBlock(UnDestroyableBlock *unDestroyableBlock)
{
    unDestroyableBlock->setRect(_x, _y, 50, 50);
    unDestroyableBlock->setBrush(QColor(Qt::green));
    scene()->addItem(unDestroyableBlock);
    _unDestroyableBlock = unDestroyableBlock;
}

bool Field::isClear()
{
    if(_unDestroyableBlock == nullptr && _destroyableBlock == nullptr && _bomb==nullptr)
        return true;
    return false;
}

#include<QGraphicsScene>

#include "field.h"
#include "settings.h"

Field::Field(int x, int y) : _x(x), _y(y) {
    setRect(x, y, sizes::FieldSize, sizes::FieldSize);
}

Field::~Field()
{
    if(_destroyableBlock)
        delete _destroyableBlock;
    if(_unDestroyableBlock)
        delete _unDestroyableBlock;
    if(_explosion)
        delete _explosion;
    if(_bomb)
        delete _bomb;
}

void Field::setUnDestroyableBlock(UnDestroyableBlock *unDestroyableBlock)
{
    unDestroyableBlock->setRect(_x, _y, sizes::FieldSize, sizes::FieldSize);
    unDestroyableBlock->setBrush(QColor(Qt::green));
    scene()->addItem(unDestroyableBlock);
    _unDestroyableBlock = unDestroyableBlock;
}

bool Field::isClear()
{
    if(_unDestroyableBlock == nullptr && _destroyableBlock == nullptr && _bomb == nullptr)
        return true;
    return false;
}

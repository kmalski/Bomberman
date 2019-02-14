#include<QGraphicsScene>

#include "field.h"
#include "settings.h"

#include <QDebug>

Field::Field(int x, int y, QObject *parent) : QObject(parent), _x(x), _y(y), _isPlayerOn(false) {
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

void Field::setDestoryableBlock(DestroyableBlock *destroyableBlock) {
    destroyableBlock->setRect(_x, _y, sizes::FieldSize, sizes::FieldSize);
    destroyableBlock->setBrush(QColor(Qt::gray));
    scene()->addItem(destroyableBlock);
    _destroyableBlock = destroyableBlock;
}

void Field::setBomb(Bomb *bomb)
{
    if(_bomb == nullptr) {
        bomb->setRect(_x, _y, sizes::FieldSize, sizes::FieldSize);
        bomb->setBrush(QColor(Qt::black));
        scene()->addItem(bomb);
        _bomb = bomb;
    }
    else {
        delete bomb;
    }
}

void Field::playerOn()
{
    _isPlayerOn = true;
}

void Field::playerOut()
{
    _isPlayerOn = false;
}

bool Field::isClear()
{
    if(_unDestroyableBlock == nullptr && _destroyableBlock == nullptr && _bomb == nullptr)
        return true;
    return false;
}

//void Field::exploded(std::vector<std::vector<Field *> >& fields)
//{
//    qDebug() <<"Buuum";
//    scene()->removeItem(_bomb);
//    delete _bomb;
//}

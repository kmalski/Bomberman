#include <QGraphicsScene>
#include <QTimer>

#include "field.h"
#include "settings.h"

Field::Field(int x, int y, QObject *parent) : QObject(parent), _x(x), _y(y), _isPlayerOn(false) {
    setRect(x, y, sizes::FieldSize, sizes::FieldSize);
}

Field::~Field() {
    if(_destroyableBlock)
        delete _destroyableBlock;
    if(_unDestroyableBlock)
        delete _unDestroyableBlock;
    if(_explosion)
        delete _explosion;
    if(_bomb)
        delete _bomb;
}

void Field::setUnDestroyableBlock(UnDestroyableBlock *unDestroyableBlock) {
    createRectItem(unDestroyableBlock, QColor(Qt::green));
    _unDestroyableBlock = unDestroyableBlock;
}

void Field::setDestoryableBlock(DestroyableBlock *destroyableBlock) {
    createRectItem(destroyableBlock, QColor(Qt::gray));
    _destroyableBlock = destroyableBlock;
}

void Field::setBomb(Bomb *bomb) {
    if(_bomb == nullptr) {
        createRectItem(bomb, QColor(Qt::black));
        _bomb = bomb;
    }
    else {
        delete bomb;
    }
}

void Field::playerOn() {
    _isPlayerOn = true;
}

void Field::playerOut() {
    _isPlayerOn = false;
}

bool Field::isClear() const {
    if(_unDestroyableBlock == nullptr && _destroyableBlock == nullptr && _bomb == nullptr)
        return true;
    return false;
}

void Field::explosion() {
    _bomb = nullptr;
    if (_destroyableBlock) {
        delete _destroyableBlock;
        _destroyableBlock = nullptr;
        createExplosion();
    }
    else if (!_destroyableBlock && !_unDestroyableBlock) {
        createExplosion();
    }
}

void Field::createRectItem(QGraphicsRectItem *item, QColor color) const {
    item->setRect(_x, _y, sizes::FieldSize, sizes::FieldSize);
    item->setBrush(color);
    scene()->addItem(item);
}

void Field::createExplosion() {
    _explosion = new Explosion();
    createRectItem(_explosion, QColor(Qt::yellow));
    QTimer::singleShot(300, _explosion, &Explosion::removeExplosion);
}

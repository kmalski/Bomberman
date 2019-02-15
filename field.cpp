#include <QGraphicsScene>
#include <QTimer>

#include "field.h"
#include "settings.h"
#include "player.h"

Field::Field(int x, int y, QObject *parent) : QObject(parent), _x(x), _y(y), _isPlayerOn(false) {
    setPos(x, y);
    setPixmap(QPixmap(":/img/img/field.png"));
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
    createPixmapItem(unDestroyableBlock, ":/img/img/unDestroyableBlock.png");
    _unDestroyableBlock = unDestroyableBlock;
}

void Field::setDestoryableBlock(DestroyableBlock *destroyableBlock) {
    createPixmapItem(destroyableBlock, ":/img/img/destroyableBlock.png");
    _destroyableBlock = destroyableBlock;
}

void Field::setBomb(Bomb *bomb) {
    createPixmapItem(bomb, ":/img/img/bomb.png");
    _bomb = bomb;
}

void Field::playerOn(Player * player) {
    _player = player;
    _isPlayerOn = true;
}

void Field::playerOut() {
    _player = nullptr;
    _isPlayerOn = false;
}

bool Field::isBomb() const {
    if(_bomb == nullptr)
        return false;
    return true;
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

void Field::createPixmapItem(QGraphicsPixmapItem *item, QString path) const {
    item->setPos(_x, _y);
    item->setPixmap(QPixmap(path));
    scene()->addItem(item);
}

void Field::createExplosion() {
    _explosion = new Explosion();
    createPixmapItem(_explosion, ":/img/img/fire.png");
    if(_isPlayerOn == true)
        _player->decreaseHP(this);
    QTimer::singleShot(300, _explosion, &Explosion::removeExplosion);
    _explosion = nullptr;
}

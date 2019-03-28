#include <QGraphicsScene>
#include <QTimer>
#include <QRandomGenerator>
#include <QDebug>

#include "field.h"
#include "player.h"

Field::Field(int x, int y, QObject *parent) : QObject(parent), _x(x), _y(y), _isPlayerOn(false) {
    setPos(x, y);
    setPixmap(QPixmap(":/img/img/field.png"));
    for (int i = 0; i < sizes::Players; i++) {
        _players[i] = nullptr;
    }
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
    for (int i = 0; i < sizes::Players; i++) {
        if(!_players[i]) {
            _players[i] = player;
            break;
        }
    }
    _isPlayerOn = true;
}

void Field::playerOut(Player * player) {
    for (int i = 0; i < sizes::Players; i++) {
        if(_players[i] == player)
            _players[i] = nullptr;
        else if(_players[i])
            _isPlayerOn = false;
    }
}

bool Field::isBomb() const {
    if(_bomb == nullptr)
        return false;
    return true;
}

bool Field::isUnDestroyableBlock() const {
    if(_unDestroyableBlock == nullptr)
        return false;
    return true;
}

blockType Field::isBlockOnField() const
{
    if (_destroyableBlock)
        return Destroyable;
    else if (_unDestroyableBlock)
        return Undestroyable;
    else
        return Empty;
}

bool Field::isClear() const {
    if(_unDestroyableBlock == nullptr && _destroyableBlock == nullptr && _bomb == nullptr)
        return true;
    return false;
}

void Field::getPowerUp(Player * player)  {
    if(_powerUp != nullptr) {
        _powerUp->usePowerUp(player);
        scene()->removeItem(_powerUp);
        delete _powerUp;
        _powerUp = nullptr;
    }
}

void Field::explosion() {
    _bomb = nullptr;
    if (_destroyableBlock) {
        delete _destroyableBlock;
        _destroyableBlock = nullptr;
        randPowerUp();
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
    if(_isPlayerOn == true) {
        for (int i = 0; i < sizes::Players; i++) {
            if(_players[i])
                _players[i]->decreaseHP(this);
        }
    }
    QTimer::singleShot(300, _explosion, &Explosion::removeExplosion);
    _explosion = nullptr;
}

void Field::randPowerUp() {
    int randomNumber = QRandomGenerator::global()->bounded(20);
    if(randomNumber == 0 ) {
        HealthPowerUp * newPowerUp = new HealthPowerUp(_x, _y);
        _powerUp = newPowerUp;
        scene()->addItem(newPowerUp);
     }
    else if(randomNumber == 1 || randomNumber == 10) {
        ExplosionPowerUp * newPowerUp = new ExplosionPowerUp(_x, _y);
        _powerUp = newPowerUp;
        scene()->addItem(newPowerUp);
    }
    else if(randomNumber == 2 || randomNumber == 20) {
        BombPowerUp * newPowerUp = new BombPowerUp(_x, _y);
        _powerUp = newPowerUp;
        scene()->addItem(newPowerUp);
    }
}

#ifndef POWERUP_H
#define POWERUP_H

#include <QGraphicsPixmapItem>

class Player;

class PowerUp : public QGraphicsPixmapItem {
public:
    PowerUp();
    virtual ~PowerUp() = default;
    virtual void usePowerUp(Player * player) = 0;
};

#endif // POWERUP_H

#ifndef EXPLOSIONPOWERUP_H
#define EXPLOSIONPOWERUP_H

#include "powerup.h"

class Player;

class ExplosionPowerUp : public PowerUp {
public:
    ExplosionPowerUp(int x, int y);
    void usePowerUp(Player * player);
};

#endif // EXPLOSIONPOWERUP_H

#ifndef HEALTHPOWERUP_H
#define HEALTHPOWERUP_H

#include "powerup.h"

class Player;

class HealthPowerUp : public PowerUp {
public:
    HealthPowerUp(int x, int y);
    void usePowerUp(Player * player);
};

#endif // HEALTHPOWERUP_H

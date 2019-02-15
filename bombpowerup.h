#ifndef BOMBPOWERUP_H
#define BOMBPOWERUP_H

#include "powerup.h"

class Player;

class BombPowerUp : public PowerUp {
public:
    BombPowerUp(int x, int y);
    void usePowerUp(Player * player);
};

#endif // BOMBPOWERUP_H

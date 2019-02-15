#include "bombpowerup.h"
#include "player.h"

BombPowerUp::BombPowerUp(int x, int y) {
    setPos(x, y);
    setPixmap(QPixmap(":/img/img/bombPowerUp.png"));
}

void BombPowerUp::usePowerUp(Player * player) {
    player->addBomb();
}

#include "explosionpowerup.h"
#include "player.h"

ExplosionPowerUp::ExplosionPowerUp(int x, int y) {
    setPos(x, y);
    setPixmap(QPixmap(":/img/img/explosionPowerUp.png"));
}


void ExplosionPowerUp::usePowerUp(Player * player) {
    player->increaseExplosionSize();
}

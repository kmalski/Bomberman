#include "healthpowerup.h"
#include "player.h"

HealthPowerUp::HealthPowerUp(int x, int y) {
    setPos(x, y);
    setPixmap(QPixmap(":/img/img/healthPowerUp.png"));
}

void HealthPowerUp::usePowerUp(Player * player) {
    player->increaseHP();
}

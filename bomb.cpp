#include "bomb.h"
#include "settings.h"

Bomb::Bomb(int x, int y) : _x(x), _y(y)
{
    setRect(_x * sizes::FieldSize, _y * sizes::FieldSize,sizes::FieldSize, sizes::FieldSize);
}

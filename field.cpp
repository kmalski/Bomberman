#include "field.h"

Field::Field() {

}

Field::Field(int x, int y) : _x(x), _y(y) {
    setRect(x, y, 50, 50);
}

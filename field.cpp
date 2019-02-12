#include "field.h"
#include "settings.h"

Field::Field() {

}

Field::Field(int x, int y) : _x(x), _y(y) {
    setRect(x, y, sizes::FieldSize, sizes::FieldSize);
}

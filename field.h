#ifndef FIELD_H
#define FIELD_H
#include <QGraphicsRectItem>

class Field : public QGraphicsRectItem{
public:
    Field();
    Field(int x, int y);

private:
    int _x;
    int _y;
};

#endif // FIELD_H

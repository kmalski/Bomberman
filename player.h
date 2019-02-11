#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsRectItem>

class Player : public QObject, public QGraphicsRectItem
{

    Q_OBJECT

public:
    Player();
    ~Player() = default;
    void keyPressEvent(QKeyEvent *event);

private:
    void plantBomb();

};

#endif // PLAYER_H

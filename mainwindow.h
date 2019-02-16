#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QGraphicsItem>
#include <vector>

#include "player.h"
#include "field.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void playerDied();

private:
    void keyPressEvent(QKeyEvent *event);
    void initFields(int frequency);

    QGraphicsView *_view;
    QGraphicsScene *_scene;
    Player *_player1; //arrows
    Player *_player2; //wsad
    int _playersCount;
    std::vector<std::vector<Field *>> _fields;
};

#endif // MAINWINDOW_H

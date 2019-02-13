#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
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
    void controlPlayer1(direction dir);
    void controlPlayer2(direction dir);

private:
    QGraphicsView *_view;
    QGraphicsScene *_scene;
    Player *_player1, *_player2;
    std::vector<std::vector<Field *>> _fields;
};

#endif // MAINWINDOW_H

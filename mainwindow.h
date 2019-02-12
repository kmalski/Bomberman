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

private:
    QGraphicsView *_view;
    QGraphicsScene *_scene;
    Player *_player;
    std::vector<std::vector<Field *> > _fields;
};

#endif // MAINWINDOW_H

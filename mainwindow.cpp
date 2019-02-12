#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    _scene = new QGraphicsScene();
    _scene->setSceneRect(0, 0, 650, 550);

    _player = new Player();
    _scene->addItem(_player);

    _view = new QGraphicsView(_scene);
    _view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    _view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    _view->setFixedSize(650, 550);

    setCentralWidget(_view);
    setWindowTitle(tr("Bomberman"));

    for (int i=0; i<_scene->width(); i++) {
        _fields.push_back(std::vector<Field *>());
        for(int j=0; j<_scene->height(); j++) {
            Field *newField = new Field(i + 50, j + 50);
            _fields[i].push_back(newField);
            _scene->addItem(newField);
        }
    }
}

MainWindow::~MainWindow()
{
    delete _player;
    delete _scene;
    delete _view;
}

#include "mainwindow.h"
#include "settings.h"
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    _scene = new QGraphicsScene();
    _scene->setSceneRect(0, 0, 650, 550);

    _player = new Player();
    _scene->addItem(_player);
    QObject::connect(_player, SIGNAL(controlPlayer(int&, int&, direction)), this, SLOT(controlPlayer(int&, int&, direction)));

    _view = new QGraphicsView(_scene);
    _view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    _view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    _view->setFixedSize(650, 550);

    setCentralWidget(_view);
    setWindowTitle(tr("Bomberman"));

    for (int i = 0; i < sizes::Raws; i++) {
        _fields.push_back(std::vector<Field *>());
        for(int j = 0; j < sizes::Columns; j++) {
            Field *newField = new Field(j * sizes::FieldSize, i * sizes::FieldSize);
            _fields[static_cast<std::size_t>(i)].push_back(newField);
            _scene->addItem(newField);
            if (i % 2 && j % 2) {
                newField->setUnDestroyableBlock(new UnDestroyableBlock());
            }
        }
    }
}

MainWindow::~MainWindow()
{
    for (std::size_t i = 0; i < sizes::Raws; i++) {
        for(std::size_t j = 0; j < sizes::Columns; j++) {
          delete  _fields[i][j];
        }
    }

    delete _player;
    delete _scene;
    delete _view;

}

void MainWindow::controlPlayer(int& x, int& y, direction dir) {
    qDebug() << "tets";
        if (dir == Left && _fields[y][x-1]->isClear()) {
            x--;
            _player->setPos(x * sizes::FieldSize, y * sizes::FieldSize);
        }
        else if (dir == Right && _fields[y][x+1]->isClear()) {
            x++;
            _player->setPos(x * sizes::FieldSize, y * sizes::FieldSize);
        }
        else if (dir == Up && _fields[y-1][x]->isClear()) {
            y--;
            _player->setPos(x * sizes::FieldSize, y * sizes::FieldSize);
        }
        else if (dir == Down && _fields[y+1][x]->isClear()) {
            y++;
            _player->setPos(x * sizes::FieldSize, y * sizes::FieldSize);
        }


}

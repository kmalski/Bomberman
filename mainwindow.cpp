#include "mainwindow.h"
#include "settings.h"

#include<QtDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    _scene = new QGraphicsScene();
    _scene->setSceneRect(0, 0, 650, 550);
    _scene->clearFocus();

    _view = new QGraphicsView(_scene);
    _view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    _view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    _view->setFixedSize(650, 550);

    setCentralWidget(_view);
    setWindowTitle(tr("Bomberman"));

    for (int i = 0; i < sizes::Rows; i++) {
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

    _player1 = new Player(0, 0);
    _player2 = new Player(0, 0);
    _scene->addItem(_player1);
    _scene->addItem(_player2);

    setFocus();
}

MainWindow::~MainWindow()
{
    for (std::size_t i = 0; i < sizes::Rows; i++) {
        for(std::size_t j = 0; j < sizes::Columns; j++) {
          delete  _fields[i][j];
        }
    }

    delete _player1;
    delete _player2;
    delete _scene;
    delete _view;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    //player1 control
    if (event->key() == Qt::Key_Left) {
        int x = _player1->getX();
        int y = _player1->getY();
        qDebug() << "player1 left, before move x: " << x * sizes::FieldSize << " y: " << y * sizes::FieldSize;
        if (x > 0 && _fields[static_cast<size_t>(y)][static_cast<size_t>(x-1)]->isClear()) {
            _player1->setX(--x);
        }
    }
    else if (event->key() == Qt::Key_Right) {
        int x = _player1->getX();
        int y = _player1->getY();
        qDebug() << "player1 right, before move x: " << x * sizes::FieldSize << " y: " << y * sizes::FieldSize;
        if (x < sizes::Columns - 1 && _fields[static_cast<size_t>(y)][static_cast<size_t>(x+1)]->isClear()) {
            _player1->setX(++x);
        }
    }
    else if (event->key() == Qt::Key_Down) {
        int x = _player1->getX();
        int y = _player1->getY();
        qDebug() << "player1 down, before move x: " << x * sizes::FieldSize << " y: " << y * sizes::FieldSize;
        if (y < sizes::Rows - 1 && _fields[static_cast<size_t>(y+1)][static_cast<size_t>(x)]->isClear()) {
            _player1->setY(++y);
        }
    }
    else if (event->key() == Qt::Key_Up) {
        int x = _player1->getX();
        int y = _player1->getY();
        qDebug() << "player1 up, before move x: " << x * sizes::FieldSize << " y: " << y * sizes::FieldSize;
        if (y > 0 && _fields[static_cast<size_t>(y-1)][static_cast<size_t>(x)]->isClear()) {
            _player1->setY(--y);
        }
    }

    //player2 control
    if (event->key() == Qt::Key_A) {
        int x = _player2->getX();
        int y = _player2->getY();
        qDebug() << "player2 left, before move x: " << x * sizes::FieldSize << " y: " << y * sizes::FieldSize;
        if (x > 0 && _fields[static_cast<size_t>(y)][static_cast<size_t>(x-1)]->isClear()) {
            _player2->setX(--x);
        }
    }
    else if (event->key() == Qt::Key_D) {
        int x = _player2->getX();
        int y = _player2->getY();
        qDebug() << "player2 right, before move x: " << x * sizes::FieldSize << " y: " << y * sizes::FieldSize;
        if (x < sizes::Columns - 1 && _fields[static_cast<size_t>(y)][static_cast<size_t>(x+1)]->isClear()) {
            _player2->setX(++x);
        }
    }
    else if (event->key() == Qt::Key_S) {
        int x = _player2->getX();
        int y = _player2->getY();
        qDebug() << "player2 down, before move x: " << x * sizes::FieldSize << " y: " << y * sizes::FieldSize;
        if (y < sizes::Rows - 1 && _fields[static_cast<size_t>(y+1)][static_cast<size_t>(x)]->isClear()) {
            _player2->setY(++y);
        }
    }
    else if (event->key() == Qt::Key_W) {
        int x = _player2->getX();
        int y = _player2->getY();
        qDebug() << "player2 up, before move x: " << x * sizes::FieldSize << " y: " << y * sizes::FieldSize;
        if (y > 0 && _fields[static_cast<size_t>(y-1)][static_cast<size_t>(x)]->isClear()) {
            _player2->setY(--y);
        }
    }
}

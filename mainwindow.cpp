#include "mainwindow.h"
#include "settings.h"
#include<QtDebug>
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    _scene = new QGraphicsScene();
    _scene->setSceneRect(0, 0, 650, 550);

    _player1 = new Player(0, 0);
    _player2 = new Player(sizes::Columns-1, sizes::Rows-1);
    _scene->addItem(_player1);
    _scene->addItem(_player2);
    _player1->setFlag(QGraphicsItem::ItemIsFocusable);
    _player1->setFocus();

    QObject::connect(_player1, SIGNAL(controlPlayer1(direction)), this, SLOT(controlPlayer1(direction)));
    QObject::connect(_player1, SIGNAL(controlPlayer2(direction)), this, SLOT(controlPlayer2(direction)));

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

void MainWindow::controlPlayer1(direction dir) {
    int x = _player1->getX();
    int y = _player1->getY();
    qDebug() << "1 " << x << "  " << y;
        if (dir == Left && _fields[y][x-1]->isClear()) {
            _player1->setX(--x);
            _player1->setPos(x * sizes::FieldSize, y * sizes::FieldSize);
        }
        else if (dir == Right && _fields[y][x+1]->isClear()) {
            _player1->setX(++x);
            _player1->setPos(x * sizes::FieldSize, y * sizes::FieldSize);
        }
        else if (dir == Up && _fields[y-1][x]->isClear()) {
            _player1->setY(--y);
            _player1->setPos(x * sizes::FieldSize, y * sizes::FieldSize);
        }
        else if (dir == Down && _fields[y+1][x]->isClear()) {
            _player1->setY(++y);
            _player1->setPos(x * sizes::FieldSize, y * sizes::FieldSize);
        }
}

void MainWindow::controlPlayer2(direction dir) {
    int x = _player2->getX();
    int y = _player2->getY();
    qDebug() << "2 " << x << "  " << y;
        if (dir == Left && _fields[y][x-1]->isClear() && x > 0) {
            _player2->setX(--x);
            _player2->setPos(x * sizes::FieldSize, y * sizes::FieldSize);
        }
        else if (dir == Right && _fields[y][x+1]->isClear() && x < sizes::Columns) {
            _player2->setX(++x);
            _player2->setPos(x * sizes::FieldSize, y * sizes::FieldSize);
        }
        else if (dir == Up && _fields[y-1][x]->isClear() && y > 0) {
            _player2->setY(--y);
            _player2->setPos(x * sizes::FieldSize, y * sizes::FieldSize);
        }
        else if (dir == Down && _fields[y+1][x]->isClear() && y < sizes::Rows) {
            _player2->setY(++y);
            _player2->setPos(x * sizes::FieldSize, y * sizes::FieldSize);
        }

}

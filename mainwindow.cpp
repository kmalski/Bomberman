#include "mainwindow.h"
#include "settings.h"

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

    initUndestoryableBlocks();

    _player1 = new Player(0, 0, QColor(Qt::red));
    _player2 = new Player(12, 10, QColor(Qt::blue));
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
    setFocus();
    //player1 control
    if (event->key() == Qt::Key_A) {
        _player1->move(Left, _fields);
    }
    else if (event->key() == Qt::Key_D) {
        _player1->move(Right, _fields);
    }
    else if (event->key() == Qt::Key_S) {
        _player1->move(Down, _fields);
    }
    else if (event->key() == Qt::Key_W) {
        _player1->move(Up, _fields);
    }
    else if (event->key() == Qt::Key_Q) {
        _player1->plantBomb(_fields);
    }

    //player2 control
    if (event->key() == Qt::Key_Left) {
        _player2->move(Left, _fields);
    }
    else if (event->key() == Qt::Key_Right) {
        _player2->move(Right, _fields);
    }
    else if (event->key() == Qt::Key_Down) {
        _player2->move(Down, _fields);
    }
    else if (event->key() == Qt::Key_Up) {
        _player2->move(Up, _fields);
    }
    else if (event->key() == Qt::Key_Space) {
        _player2->plantBomb(_fields);
    }
}

void MainWindow::initUndestoryableBlocks()
{
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

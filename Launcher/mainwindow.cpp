#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    w = new Widget(this);
    w->setFixedSize(800,600);
}

MainWindow::~MainWindow()
{


}

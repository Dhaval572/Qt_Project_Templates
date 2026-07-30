#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    central = new QWidget(this);
    setCentralWidget(central);
    layout = new QVBoxLayout(central);
    btn = new QPushButton("Click me");
    layout->addWidget(btn);
}
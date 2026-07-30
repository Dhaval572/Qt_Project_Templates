#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:

private:

    QWidget *central;
    QVBoxLayout *layout;
    QPushButton *btn;
};

#endif // MAINWINDOW_H
#include <QApplication>
#include "mainwindow.h"
#include "stylemanager.h"

#include <QDirIterator>
#include <QDebug>
#include <QResource>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    StyleManager::load(app);

    window.show();
    return app.exec();
}
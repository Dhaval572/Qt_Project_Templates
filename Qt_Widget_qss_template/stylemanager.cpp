#include "stylemanager.h"
#include <QFile>

namespace StyleManager
{
    void load(QApplication &app)
    {
        QFile file(":/styles/style.qss");

        qInfo() << "Debug Info: \n";
        qInfo() << "Exists:" << file.exists();
        qInfo() << "Path:" << file.fileName();

        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qInfo() << file.errorString();
            return;
        }

        app.setStyleSheet(file.readAll());
    }
}
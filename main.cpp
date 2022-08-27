#include "mainwindow.h"
#include "QLabel"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(1024,768);
    w.show();
    return a.exec();
}

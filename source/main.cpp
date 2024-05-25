#include "mainwindow.h"
#include "kernel.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    Kernel kernel;

    return a.exec();
}

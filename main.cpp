#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::cout <<"Before create MainWindow" <<std::endl;
    MainWindow w;
    w.show();
    return a.exec();
}

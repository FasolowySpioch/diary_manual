#include "mainwindow.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Pamiętnik");
    qDebug()<< QString("HELLO WORLD!");
    w.show();
    return a.exec();
}

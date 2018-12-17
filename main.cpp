#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();







    return a.exec();
}



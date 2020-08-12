#include "mainwindow.h"
#include "inputcanvas.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    InputCanvas canvas;
//    canvas.show();

    MainWindow w;
    w.setGeometry(100, 100, 800, 500);
    w.show();

    return a.exec();
}

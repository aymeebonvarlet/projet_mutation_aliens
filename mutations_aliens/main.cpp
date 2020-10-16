#include "mainwindow.h"
#include "../../shared/qstd.h"
using namespace qstd;
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

#include "mainwindow.h"
#include "../../shared/qstd.h"
using namespace qstd;
#include <QApplication>
#include "evolutionnary_process.h"

int main(int argc, char *argv[])
{
    Evolutionnary_process::init();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

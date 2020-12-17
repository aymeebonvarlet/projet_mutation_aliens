#include "mainwindow.h"
#include "qstd.h"
using namespace qstd;
#include <QApplication>
#include "evolutionnary_process.h"

int main(int argc, char *argv[])
{
    Evolutionnary_process evo;
    evo.init();
    cout<<evo.toString()<<endl;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

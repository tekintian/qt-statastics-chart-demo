#include "widget.h"
//#include "chartdemo.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget w;
    w.show();

//    ChartDemo cd;
//    cd.show();

    return a.exec();
}

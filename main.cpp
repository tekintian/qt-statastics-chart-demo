#include "widget.h"
#include "myqchart.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    Widget w;
//    w.show();
    MyQChart cd;
    cd.show();

    return a.exec();
}

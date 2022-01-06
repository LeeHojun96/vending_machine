#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w1;
    w1.show();
//    Widget w2;
//    w2.show();
    return a.exec();
}

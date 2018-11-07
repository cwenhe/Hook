#include "QtHook.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtHook w;
    w.show();
    return a.exec();
}

#include "qtSerialport.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qtSerialport w;
    w.show();
    return a.exec();
}

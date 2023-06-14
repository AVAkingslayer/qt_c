#include "helpWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    helpWindow w;
    w.show();
    return a.exec();
}

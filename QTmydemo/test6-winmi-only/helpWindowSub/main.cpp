#include "helpWindowSub.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    helpWindowSub w;
    w.show();
    return a.exec();
}

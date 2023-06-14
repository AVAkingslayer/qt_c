#include "threadsiganl.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    threadsiganl w;
    w.show();
    return a.exec();
}

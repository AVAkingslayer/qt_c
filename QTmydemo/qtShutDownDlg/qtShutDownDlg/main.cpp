#include <QApplication>
#include <QtCore/QProcess>
#include <QDebug>
#include <QStringList>
#include "widget.h"
#include "SetSystemTime.h"
#include "ShutDownDlg.h"
#include "RestartApp.h"

class CSetSystemTime;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Widget w;
    //w.show();
    //ShutDownDlg();
    CSetSystemTime* settime;
    //QString datetimeStr = "2023-06-16 14:15:00";
    //qDebug()<<settime->SetSystemTime(datetimeStr);
    CRestartApp* restartapp;
    QString sProPath="D:/software_new/QT5.9.9/5.9.9/mingw53_32/bin/assistant.exe";
    restartapp->CreateProPath(sProPath);
    restartapp->KillProName(sProPath);
    return a.exec();
}

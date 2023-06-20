#ifndef CSHUTDOWNDLG_H
#define CSHUTDOWNDLG_H
#include <QApplication>
#include <QtCore/QProcess>
#include <QDebug>
#include <QStringList>

class CShutdownDlg
{
public:
    CShutdownDlg();
    void ShutDownDlg();//ShutDownDlg
    bool SetSystemTime();
};

#endif // CSHUTDOWNDLG_H

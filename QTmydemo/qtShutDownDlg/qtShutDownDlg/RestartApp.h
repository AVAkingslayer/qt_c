#ifndef CRESTARTAPP_H
#define CRESTARTAPP_H

#include <QWidget>
#include <QString>
class CRestartApp
{
public:
    CRestartApp();
    void CreateProPath(const QString sProPath);//创造进程
    void KillProName(const QString sProPath);//终值进程
};

#endif // CRESTARTAPP_H

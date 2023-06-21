#ifndef CRESTARTAPP_H
#define CRESTARTAPP_H

#include <QWidget>
#include <QString>
class CRestartApp
{
public:
    CRestartApp();
    void CreateProPath(const QString sProPath);//创造进程
    void KillProName(const QString sProPath);//终止进程
    int CheckTime(int time1,int time2);//时间戳比较time1 - time2
    QString GetExePath();//获取程序路径
    QString GetSysTime();//获取系统时间
    bool InitINI(const QString& sINIPath);//
    void WriteINI(const QString& sINIPath, const QString& key, const QString& val);
    QString ReadINI(const QString& sINIPath, const QString& key);
    void CheckRestartApp();
};

#endif // CRESTARTAPP_H

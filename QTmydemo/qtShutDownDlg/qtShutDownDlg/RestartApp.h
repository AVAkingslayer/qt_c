#ifndef CRESTARTAPP_H
#define CRESTARTAPP_H

#include <QWidget>
#include <QString>
class CRestartApp
{
public:
    CRestartApp();
    void CreateProPath(const QString sProPath);//�������
    void KillProName(const QString sProPath);//��ֹ����
    int CheckTime(int time1,int time2);//ʱ����Ƚ�time1 - time2
    QString GetExePath();//��ȡ����·��
    QString GetSysTime();//��ȡϵͳʱ��
    bool InitINI(const QString& sINIPath);//
    void WriteINI(const QString& sINIPath, const QString& key, const QString& val);
    QString ReadINI(const QString& sINIPath, const QString& key);
    void CheckRestartApp();
};

#endif // CRESTARTAPP_H

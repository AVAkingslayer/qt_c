#ifndef CRESTARTAPP_H
#define CRESTARTAPP_H

#include <QWidget>
#include <QString>
class CRestartApp
{
public:
    CRestartApp();
    void CreateProPath(const QString sProPath);//�������
    void KillProName(const QString sProPath);//��ֵ����
};

#endif // CRESTARTAPP_H

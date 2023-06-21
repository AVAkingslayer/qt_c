#include "RestartApp.h"
#include "qprocess.h"
#include "qdebug.h"
#include <QThread>
#include <QCoreApplication>
#include <QDir>
#include <QDateTime>
#include <QSettings>
const QString INI_PATH = ("time.ini");//ini��path
const QString PRO_NAME = ("time.ini");//���̵�����
const QString PRO_PATH = ("time.ini");//���̵�·��
CRestartApp::CRestartApp()
{

}

void CRestartApp::CreateProPath(const QString sProPath)//�������
{
    //����һ�� QProcess ����
    QProcess process;
    QString arguments;// ��ѡ����Ӳ������б���
    process.setProgram(sProPath);
    //process.setArguments(arguments);
    //��������
    process.start();
    //�ȴ��������
    process.waitForFinished();
    //�����̵��˳�״̬
    if(process.exitStatus()==  QProcess::NormalExit && process.exitCode() == 0){
        qDebug() << "���̳ɹ���ɣ�";
     }
     else
     {
        qDebug() << "����ִ��ʧ�ܣ�";
     }
}

void CRestartApp::KillProName(const QString sProName){
    // ����һ�� QProcess ����
    QProcess process;
    //����ǵ�һ���̾Ͳ�������?
    process.start(sProName); // ����������
    // �ȴ�һ��ʱ�䣬ȷ�������������
    if (!process.waitForStarted()) {
       qDebug() << "Failed to start the process";
    }
    QThread::msleep(100);//��ʱ0.1s
    process.kill();
}

//ʱ����Ƚ�time1 - time2
int CRestartApp::CheckTime(int time1,int time2)
{
    return (time1%100 + time1/100*60) - (time2%100 + time2/100*60);
}

//��ȡ����·��
QString CRestartApp::GetExePath()
{
    QString exefullpath = QCoreApplication::applicationFilePath();//���ص�ǰӦ�ó�������·��
    QString strdir = QDir::toNativeSeparators(exefullpath);//��б�� ��ȡ·���е�Ŀ¼����
    return strdir;
}
//��ȡϵͳʱ��
QString CRestartApp::GetSysTime()
{
    QDateTime cdt = QDateTime::currentDateTime();
    QString sTime = cdt.toString("hh:mm:ss");
    return sTime;
}
//��ʼ��ini
bool CRestartApp::InitINI(const QString& sINIPath)
{
    QString sPath = QCoreApplication::applicationDirPath() + "/" + sINIPath; // ini�ļ�ȫ·��
    QSettings settings(sPath, QSettings::IniFormat);

   if (!settings.contains("TIME1")) {
       settings.setValue("TIME1", GetSysTime());
       return false;
    }
   return true;
}

void CRestartApp::WriteINI(const QString& sINIPath, const QString& key, const QString& val)
{
    QString sPath = QCoreApplication::applicationDirPath() + "/" + sINIPath; // ini�ļ�ȫ·��
    QSettings settings(sPath, QSettings::IniFormat);
    settings.setValue("OSPA RestartApp/" + key, val);
}

QString CRestartApp::ReadINI(const QString& sINIPath, const QString& key)
{
    QString sPath = QCoreApplication::applicationDirPath() + "/" + sINIPath; // ini�ļ�ȫ·��
    QSettings settings(sPath, QSettings::IniFormat);
    return settings.value("OSPA RestartApp/" + key, "-1").toString();
}
//�ж�����
void CRestartApp::CheckRestartApp()
{
    QString iniPath = "RestartApp.ini";

    if (InitINI(iniPath)) // ��ʼ��ini
    {
#if 0
        QString stNow = GetSysTime();
        int ntNow = stNow.toInt();
        int ntPre1 = ReadINI(iniPath, "TIME1").toInt();
        if (ntPre1 > 0)
        {
            if (CheckTime(ntNow, ntPre1) < 30)
            {
                // ���������
                int ntPre2 = ReadINI(iniPath, "TIME2").toInt();
                if (ntPre2 > 0)
                {
                    // ����������
                    if (CheckTime(ntPre2, ntPre1) < 30)
                    {
                        // ���������
                        // ����ʧ�ܣ�������
                        // ...
                        KillProName(PRO_NAME);
                    }
                    else
                    {
                        // ��������������¼���
                        KillProName(PRO_NAME);
                        CreateProPath(PRO_PATH);
                    }
                    WriteINI(iniPath, "TIME1", "-1");
                    WriteINI(iniPath, "TIME2", "-1");
                }
                else
                {
                    // �ڶ�������
                    WriteINI(iniPath, "TIME2", stNow);
                    // ��һ�β���
                    KillProName(PRO_NAME);
                    CreateProPath(PRO_PATH);
                }
            }
            else
            {
                // ��������������¼���
                WriteINI(iniPath, "TIME1", "-1");
                WriteINI(iniPath, "TIME2", "-1");
                KillProName(PRO_NAME);
                CreateProPath(PRO_PATH);
            }
        }
        else
#endif
        {
            // ��һ������
            // WriteINI(iniPath, "TIME1", stNow);
            KillProName(PRO_NAME);
            CreateProPath(PRO_PATH);
        }
    }
    else
    {
        // û��ini�ļ�����һ������
        KillProName(PRO_NAME); // ��������
        CreateProPath(PRO_PATH); // ��������
    }
}

#include "RestartApp.h"
#include "qprocess.h"
#include "qdebug.h"
#include <QThread>
#include <QCoreApplication>
#include <QDir>
#include <QDateTime>
#include <QSettings>
const QString INI_PATH = ("time.ini");//ini的path
const QString PRO_NAME = ("time.ini");//进程的名字
const QString PRO_PATH = ("time.ini");//进程的路径
CRestartApp::CRestartApp()
{

}

void CRestartApp::CreateProPath(const QString sProPath)//创造进程
{
    //创建一个 QProcess 对象
    QProcess process;
    QString arguments;// 可选：添加参数到列表中
    process.setProgram(sProPath);
    //process.setArguments(arguments);
    //启动进程
    process.start();
    //等待进程完成
    process.waitForFinished();
    //检查进程的退出状态
    if(process.exitStatus()==  QProcess::NormalExit && process.exitCode() == 0){
        qDebug() << "进程成功完成！";
     }
     else
     {
        qDebug() << "进程执行失败！";
     }
}

void CRestartApp::KillProName(const QString sProName){
    // 创建一个 QProcess 对象
    QProcess process;
    //如果是单一进程就不用重启?
    process.start(sProName); // 先启动进程
    // 等待一段时间，确保进程启动完成
    if (!process.waitForStarted()) {
       qDebug() << "Failed to start the process";
    }
    QThread::msleep(100);//延时0.1s
    process.kill();
}

//时间戳比较time1 - time2
int CRestartApp::CheckTime(int time1,int time2)
{
    return (time1%100 + time1/100*60) - (time2%100 + time2/100*60);
}

//获取程序路径
QString CRestartApp::GetExePath()
{
    QString exefullpath = QCoreApplication::applicationFilePath();//返回当前应用程序完整路径
    QString strdir = QDir::toNativeSeparators(exefullpath);//反斜杠 提取路径中的目录部分
    return strdir;
}
//获取系统时间
QString CRestartApp::GetSysTime()
{
    QDateTime cdt = QDateTime::currentDateTime();
    QString sTime = cdt.toString("hh:mm:ss");
    return sTime;
}
//初始化ini
bool CRestartApp::InitINI(const QString& sINIPath)
{
    QString sPath = QCoreApplication::applicationDirPath() + "/" + sINIPath; // ini文件全路径
    QSettings settings(sPath, QSettings::IniFormat);

   if (!settings.contains("TIME1")) {
       settings.setValue("TIME1", GetSysTime());
       return false;
    }
   return true;
}

void CRestartApp::WriteINI(const QString& sINIPath, const QString& key, const QString& val)
{
    QString sPath = QCoreApplication::applicationDirPath() + "/" + sINIPath; // ini文件全路径
    QSettings settings(sPath, QSettings::IniFormat);
    settings.setValue("OSPA RestartApp/" + key, val);
}

QString CRestartApp::ReadINI(const QString& sINIPath, const QString& key)
{
    QString sPath = QCoreApplication::applicationDirPath() + "/" + sINIPath; // ini文件全路径
    QSettings settings(sPath, QSettings::IniFormat);
    return settings.value("OSPA RestartApp/" + key, "-1").toString();
}
//判断重启
void CRestartApp::CheckRestartApp()
{
    QString iniPath = "RestartApp.ini";

    if (InitINI(iniPath)) // 初始化ini
    {
#if 0
        QString stNow = GetSysTime();
        int ntNow = stNow.toInt();
        int ntPre1 = ReadINI(iniPath, "TIME1").toInt();
        if (ntPre1 > 0)
        {
            if (CheckTime(ntNow, ntPre1) < 30)
            {
                // 重启间隔短
                int ntPre2 = ReadINI(iniPath, "TIME2").toInt();
                if (ntPre2 > 0)
                {
                    // 第三次重启
                    if (CheckTime(ntPre2, ntPre1) < 30)
                    {
                        // 重启间隔短
                        // 补救失败，不处理
                        // ...
                        KillProName(PRO_NAME);
                    }
                    else
                    {
                        // 重启间隔长，重新计数
                        KillProName(PRO_NAME);
                        CreateProPath(PRO_PATH);
                    }
                    WriteINI(iniPath, "TIME1", "-1");
                    WriteINI(iniPath, "TIME2", "-1");
                }
                else
                {
                    // 第二次重启
                    WriteINI(iniPath, "TIME2", stNow);
                    // 第一次补救
                    KillProName(PRO_NAME);
                    CreateProPath(PRO_PATH);
                }
            }
            else
            {
                // 重启间隔长，重新计数
                WriteINI(iniPath, "TIME1", "-1");
                WriteINI(iniPath, "TIME2", "-1");
                KillProName(PRO_NAME);
                CreateProPath(PRO_PATH);
            }
        }
        else
#endif
        {
            // 第一次重启
            // WriteINI(iniPath, "TIME1", stNow);
            KillProName(PRO_NAME);
            CreateProPath(PRO_PATH);
        }
    }
    else
    {
        // 没有ini文件，第一次重启
        KillProName(PRO_NAME); // 结束进程
        CreateProPath(PRO_PATH); // 启动进程
    }
}

#include "RestartApp.h"
#include "qprocess.h"
#include "qdebug.h"
#include <QThread>
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

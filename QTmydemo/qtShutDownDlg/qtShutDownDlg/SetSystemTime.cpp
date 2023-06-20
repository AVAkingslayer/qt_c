#include "SetSystemTime.h"

bool CSetSystemTime::SetSystemTime(const QString& datetimeStr)
{
    //QProcess::execute("ls");//method1
    //change System Clock command
    QProcess *sysclkprocess = new QProcess();//method2
    QStringList arguments;
    arguments<<"-S"<<"date"<<"-s"<< datetimeStr;
    sysclkprocess->start("sudo", arguments);
    if (!sysclkprocess->waitForStarted()) {
            qDebug() << "Failed to start sudo process";
            return 0;
        }
    QString password = "s";
    sysclkprocess->write(password.toUtf8() + "\n");
    if (!sysclkprocess->waitForFinished()) {
            qDebug() << "Failed to wait for sudo process to finish";
            return 0;
    }
    QString output = sysclkprocess->readAllStandardOutput();
    qDebug() << "sysclk Output:" << output;

    //change hwclock command
    QProcess *hwclockprocess = new QProcess();//method2
    hwclockprocess->start("sudo hwclock --systohc");
    if (!hwclockprocess->waitForFinished()) {
        qDebug() << "Failed to wait for hwclock process to finish";
        return 0;
    }
    QString hwclockOutput = hwclockprocess->readAllStandardOutput();
    qDebug() << "hwclock Output:" << hwclockOutput;
    return 1;
}

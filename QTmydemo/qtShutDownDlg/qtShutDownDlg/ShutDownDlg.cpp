#include "ShutDownDlg.h"

void CShutdownDlg::ShutDownDlg()
{
    QProcess *sdprocess = new QProcess();//method2
    QStringList arguments;
        arguments << "-S" << "shutdown" << "-p" << "now";

        sdprocess->start("sudo", arguments);

        if (!sdprocess->waitForStarted()) {
            qDebug() << "Failed to start sudo process";
        }

        QString password = "s";
        sdprocess->write((password + "\n").toUtf8());

        if (!sdprocess->waitForFinished()) {
            qDebug() << "Failed to wait for sudo process to finish";
        }

}


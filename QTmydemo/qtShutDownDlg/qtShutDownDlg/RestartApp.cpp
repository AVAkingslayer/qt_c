#include "RestartApp.h"
#include "qprocess.h"
#include "qdebug.h"
#include <QThread>
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

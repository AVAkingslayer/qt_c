#include "threadsiganl.h"
#include "ui_threadsiganl.h"
#include <QDebug>

threadsiganl::threadsiganl(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(&threadA,SIGNAL(started()),this,SLOT(onthreadA_started()));
    connect(&threadA,SIGNAL(finished()),this,SLOT(onthreadA_finished()));
    connect(&threadA,SIGNAL(newValue(int,int)),this,SLOT(onthreadA_newValue(int,int)));//发出改变值的信号
}

threadsiganl::~threadsiganl()
{
    delete ui;
}

void threadsiganl::onthreadA_started()
{//线程的start信号相应的槽函数
    ui->LabA->setText("Thread状态：thread started");
}

void threadsiganl::onthreadA_finished()
{//线程的finish信号相应的槽函数
    ui->LabA->setText("Thread状态：thread finished");
}

void threadsiganl::onthreadA_newValue(int seq, int diceValue)
{//QDiceThred的newvalue()信号的响应槽函数，显示骰子次数和点数
    QString str = QString::asprintf("第%d次掷骰子，点数为：%d",seq,diceValue);//次数+骰子次数
    ui->plainTextEdit->appendPlainText(str);//设置显示字符 次数+骰子次数
    QPixmap pic;//图片显示
    QString filename = QString::asprintf("：/dict/images/d%d",diceValue);//设置图片名称
    qDebug()<<filename<<endl;
    pic.load(filename);
    ui->LabPic->setPixmap(pic);//设置显示的图片
}

//处理窗口中的5个按钮
void threadsiganl::on_btnStartThread_clicked()
{//启动线程 start
    threadA.start();
    ui->btnStartThread->setEnabled(false);
    ui->btnStopThread->setEnabled(true);
    ui->btnDiceBegin->setEnabled(true);//开始掷骰子(设置为可操作的状态)
    ui->btnDiceEnd->setEnabled(false);
}


void threadsiganl::on_btnDiceBegin_clicked()
{//开始 掷骰子按钮 begin
    threadA.diceBegin();
    ui->btnDiceBegin->setEnabled(false);
    ui->btnDiceEnd->setEnabled(true);
}

void threadsiganl::on_btnDiceEnd_clicked()
{//暂停 掷骰子按钮
    threadA.dicePause();
    ui->btnDiceBegin->setEnabled(true);
    ui->btnDiceEnd->setEnabled(false);
}

void threadsiganl::on_btnStopThread_clicked()
{//结束进程按钮
    threadA.stopThread();
}

void threadsiganl::on_btnClear_clicked()
{//清空文本按钮
    ui->plainTextEdit->clear();
}

void threadsiganl::closeEvent(QCloseEvent *event)//重载CloseEvent事件，在窗口关闭时确保线程被静止
{//窗口关闭事件，必须结束进程
    if(threadA.isRunning()){
        threadA.stopThread();
        threadA.wait();
    }
    event->accept();
}

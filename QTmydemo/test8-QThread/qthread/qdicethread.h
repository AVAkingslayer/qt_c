#ifndef QDICETHREAD_H
#define QDICETHREAD_H

#include <QThread>
class qdicethread:public QThread
{
    Q_OBJECT
public:
    int m_seq=0;//摇骰子次数序号
    int m_diceValue;//骰子的点数
    bool m_Paused = true;//投一次筛子
    bool m_stop = false;//停止线程

protected:
    void run() Q_DECL_OVERRIDE;//线程任务 虚函数
public:
     qdicethread();//重构函数
     //线程调用，主线程
     void diceBegin();//掷骰子一次
     void dicePause();//暂停
     void stopThread();//结束进程
signals:
     //产生新点数的信号
     void newValue(int seq,int dicevalue);//次序值，筛子值

};

#endif // QDICETHREAD_H

#include "qdicethread.h"
#include <QTime>
#include <QDebug>
qdicethread::qdicethread()//构造函数
{

}

void qdicethread::diceBegin()
{//开始掷骰子
    m_Paused = false;
}

void qdicethread::dicePause()
{//暂停掷骰子
    m_Paused = true;
}

void qdicethread::stopThread()
{//停止进程
    m_stop = true;
}

void qdicethread::run()//虚函数
{//线程任务
    m_stop = false;
    m_seq =0;//掷骰子的次数
    qsrand(QTime::currentTime().msec());//随机数初始化，qsrand是线程安全的
    while(!m_stop)//循环主体
    {
        if(!m_Paused)
        {
            m_diceValue = qrand();//获取随机数
            m_diceValue = (m_diceValue%6)+1;//在1-7中产生随机数
            qDebug()<<m_diceValue;
            m_seq++;
            emit newValue(m_seq,m_diceValue);//发射信号 这里的参数时能直接收到么？
        }
        msleep(500);//线程休眠500ms
    }
    //在m_stop==true中时结束线程任务
    quit();//退出线程的事件循环
}

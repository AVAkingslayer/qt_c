#include "qperson.h"
#include "widget.h"

QPerson::QPerson(QString fName,QObject *parent) : QObject(parent)//构造函数
{
    m_name = fName;
}

int QPerson::age()
{
    return m_age;
}

//设置年龄，增加年龄，年龄都是会变的
void QPerson::setAge(int value)//设置年龄
{
    m_age =value;
    emit(ageChanged(m_age));//发射信号
    //发射信号允许对象间的通信，ageChanged信号通知了其他对象，表示m_age的值已经改变了。
    //通常情况下，ageChanged信号会被连接到一个槽函数，这个槽函数会根据新的年龄值来执行一些操作，例如更新用户界面中显示的年龄值。
}

void QPerson::incAge()//增加年龄
{
    m_age++;
    emit(ageChanged(m_age));
}

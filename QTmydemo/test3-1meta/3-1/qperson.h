#ifndef QPERSON_H
#define QPERSON_H

#include <QObject>

//继承于Qobject的QPerson类
class QPerson : public QObject
{
    Q_OBJECT
    //CLASSINFO附加信息
    Q_CLASSINFO("Author","ava");//设置作者
    Q_CLASSINFO("Company","UESTC");//设置公司
    Q_CLASSINFO("Version","1.1.0");//版本信息
    //属性信息(3个属性+1信号)
    Q_PROPERTY(type age READ age WRITE setAge NOTIFY ageChanged)//年龄 设置可读函数age 可写函数setAge NOTIFY是可选的，用于设置一个信号，当属性值变化时发射此信号ageChanged。
    Q_PROPERTY(Qstring name MEMBER m_name)//姓名访问 MEMBER指定一个成员变量与属性关联，成为可读可写的属性，无需再设置READ和WRITE。
    Q_PROPERTY(int score MEMBER m_score)

private:
    unsigned m_age =10;//年龄
    QString m_name;//姓名
    int m_score=79;//分数


public:
    explicit QPerson(QString fName, QObject *parent = nullptr);//构造函数

    int age();//和Q_PROPERTY关联的公共函数
    void setAge(int value);
    void incAge();//增加年龄 按refator生成函数，按F4回来

signals:
    void ageChanged(int value);//只有一个信号，可以用取地址的方式
};

#endif // QPERSON_H

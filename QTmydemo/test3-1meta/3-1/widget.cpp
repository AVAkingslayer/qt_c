#include "widget.h"
#include "ui_widget.h"
#include  <QMetaProperty>
#include <QWidget>
//h文件定义了boy，girl,就不用在这里初始化
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    boy = new QPerson("王小明");
    boy ->setProperty("score",95);//Q
    boy->setProperty("age",10);
    boy->setProperty("sex","Boy");//动态属性
    connect(boy,&QPerson::ageChanged,this,&Widget::on_ageChanged);//QPerson中只有一个agechanged信号，则可以用取地址的方式，缺省函数参数

    girl = new QPerson("张小丽");
    girl->setProperty("score",100);
    girl->setProperty("age",13);
    girl->setProperty("sex","Girl");//动态属性
    connect(girl,&QPerson::ageChanged,this,&Widget::on_ageChanged);

    ui->spinBoxBoy->setProperty("isBoy",true);//给spin创建属性 逻辑型动态属性
    ui->spinBoxGirl->setProperty("isBoy",false);
    connect(ui->spinBoxGirl,&QSpinBox::valueChanged,this,&Widget::on_spin_valueChanged);//实际上是可以这么写的
    //connect(ui->spinBoxGirl,SIGNAL(valueChanged(int)),this,SLOT(on_spin_valueChanged(int)));//QspinBox有两个参数不同的valueChanged信号 wid
    connect(ui->spinBoxBoy,SIGNAL(valueChanged(int)),this,SLOT(on_spin_valueChanged(int)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_ageChanged(int value)//自定义槽函数用于响应QPerson的ageChanged()信号
{
    Q_UNUSED(value);
    QPerson *aPerson = qobject_cast<QPerson *>(sender());//类型投射 因为信号发射者是QPerson类型对象boy或girl，所以可以用qobject_cast()将发射者投射为具体的类型。
    QString hisName = aPerson->property("name").toString();//姓名 name是用MEMBER进行了定义的
    QString hisSex = aPerson->property("sex").toString();//动态属性
    int hisAge = aPerson->age();//通过接口函数获得属性,速度更快
    //int hisAge = aPerson->property("age").toInt();//通过属性获得年龄
    ui->plainTextEdit->appendPlainText(hisName+","+hisSex+QString::asprintf(",年龄=%d",hisAge));
}

void Widget::on_spin_valueChanged(int argl)//同类型组件的同一信号编写一个槽函数
{//响应界面上spinBox的valueChanged(int)信号
    Q_UNUSED(argl);//避免编译错误
    QSpinBox *spinbox = qobject_cast<QSpinBox *>(sender());//投射到sender()上用QObject::sender()可以获取信号发射者的指针。
    if(spinbox->property("isBoy").toBool())//如果知道信号发射者的类型，可以将指针投射为确定的类型，然后使用这个确定类的接口函数.
        boy->setAge(spinbox->value());//转为bool类型
    else
        girl->setAge(spinbox->value());

}


void Widget::on_BtnBotincr_clicked()//boy增长一岁 不是自定义的不需要用connect
{//boy增长年龄 调用qperson中的incAge会发射valuechanged信号
    boy->incAge();
}

void Widget::on_BtnGirlincr_clicked()//girl增长一岁
{//girl增长年龄会 发射valuechanged信号
    girl->incAge();
}

void Widget::on_Btnclinfo_clicked()
{//“类的元对象信息”按钮
    const QMetaObject *meta = boy->metaObject();//通过boy->metaObject()获得对象boy的元对象
    ui->plainTextEdit->clear();
    ui->plainTextEdit->appendPlainText("==元对象信息==\n");
    ui->plainTextEdit->appendPlainText(QString("类名称：%1\n").arg(meta->className()));//meta->className()如QPerson
    ui->plainTextEdit->appendPlainText("property");//属性
    for(int i =meta->propertyOffset();i<meta->propertyCount();i++){
        QMetaProperty prop=meta->property(i);
        const char* propName=prop.name();
        QString propValue =boy->property(propName).toString();
        ui->plainTextEdit->appendPlainText(QString("属性名称=%1，属性值=%2").arg(propName).arg(boy->property(propName).toString()));
    }
    ui->plainTextEdit->appendPlainText("");//空格
    ui->plainTextEdit->appendPlainText("classinfo");
    for(int i = meta->classInfoOffset();i<meta->classInfoCount();++i){
        QMetaClassInfo classInfo = meta->classInfo(i);
        ui->plainTextEdit->appendPlainText(QString("Name = %1；Value=%2").arg(classInfo.name()).arg(classInfo.value()));

    }

}

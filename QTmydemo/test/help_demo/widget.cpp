#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)//构造函数
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //宏的形式
    connect(ui->cmdlineEdit,SIGNAL(returnPressed()),this,SLOT(on_comitButton_clicked()));//信号与槽要进行连接 :谁发出信号 发出什么信号 谁处理信号 怎么处理
    //地址+槽函数的形式
    connect(ui->cancelButton,&QPushButton::clicked,this,&Widget::on_cancelButton_clicked);
    //直接在this中写内联函数，这样就不用写槽函数了
    connect(ui->brosesbutton,&QPushButton::clicked,[this]{
     QMessageBox::information(this,"信息","点击浏览")
    })
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_comitButton_clicked()//槽函数 确定按钮
{
    //获取lineedit数据 返回文本内容 Qstring类名 创建字符串对象
    QString program=ui->cmdlineEdit->text();
    //创建一个process 对象
    QProcess *myProcess = new QProcess(this);
    myProcess->start(program);
}

void Widget::on_cancelButton_clicked()
{
    this->close();
}

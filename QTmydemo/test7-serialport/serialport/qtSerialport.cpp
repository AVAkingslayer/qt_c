#include "qtSerialport.h"
#include "ui_qtSerialport.h"
#include <QDebug>
#include<QMessageBox>
#include <QTimer>

qtSerialport::qtSerialport(QWidget *parent)//修改继承的类名
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mySerial = new QSerialPort(this);//分配内存
    connect(mySerial,SIGNAL(readyRead()),this,SLOT(Read_data()));//信号接收
    //创建周期发送，时间显示，延时接受定时器，并且初始化
    PriecSendTime = new QTimer(this);
    PriecSendTime->setInterval(1000);//默认周期为1000ms
    //每1s就直接调用一次发送按钮，这会导致没有按下发送按钮他也会发送
    connect(PriecSendTime,SIGNAL(timeout()),this,SLOT(on_send_button_clicked()));


}

qtSerialport::~qtSerialport()
{
    delete ui;
}
/***************************************
* func      :Get_Serial_Port
* describe  :获取可用端口号
* para      :none
* return    :QList<QSerialPortInfo>,所有获取的串口信息
* **************************************/
QList<QSerialPortInfo> qtSerialport::Get_Serial_Port()
{
    QList<QSerialPortInfo> ports;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        //qDebug()<<info.portName();
        ports.append(info);
    }
    return ports;
}

/*将串口数据以HEX形式显示出来，并用空格隔开*/
void qtSerialport::refresh_text(QTextEdit *text, QByteArray temp)
{
    QString data;
    int cnt = temp.size();
    for(int i = 0; i < cnt ; i +=2)
    {
        data = temp.mid(i,2);                               //一个字节数据之间显示一个空格
        data += " ";
        text->insertPlainText(data);
    }

}

/***************************************
* func      :on_open_button_clicked
* describe  :打开该串口号
* para      :none
* return    :none
* **************************************/
void qtSerialport::on_open_button_clicked()
{
    QSerialPort::BaudRate buadrate;//波特率
    QSerialPort::DataBits databits;//数据位
    QSerialPort::Parity parity;//奇偶校验
    QSerialPort::StopBits stopbits;//停止位
    switch (ui->baudrate->currentText().toInt()) {//设置波特率
    case 1200:
        buadrate =  QSerialPort::Baud1200;
        break;
    case 4800:
        buadrate =  QSerialPort::Baud4800;
        break;
    case 9600:
        buadrate =  QSerialPort::Baud9600;
        break;
    case 38400:
        buadrate =  QSerialPort::Baud38400;
        break;
    case 115200:
        buadrate = QSerialPort::Baud115200;
        break;
    default:
        break;
    }

    switch (ui->databit->currentText().toInt()) {//设置数据位
    case 6:
        databits = QSerialPort::Data6;
        break;
    case 7:
        databits = QSerialPort::Data7;
        break;
    case 8:
        databits = QSerialPort::Data8;
        break;
    default:
        break;
    }

    switch (ui->stopbit->currentText().toInt()) {//设置数据位
    case 1:
        stopbits = QSerialPort::OneStop;
        break;
    case 2:
        stopbits = QSerialPort::TwoStop;
        break;
    default:
        break;
     }

     if(ui->checkbit->currentText()=="NONE"){//设置校验位
            parity =  QSerialPort::NoParity;
     }else if(ui->checkbit->currentText() == "EVEN")
     {
         parity = QSerialPort::EvenParity;
     }else if(ui->checkbit->currentText() == "ODD")
     {
         parity = QSerialPort::OddParity;
     }else if(ui->checkbit->currentText() == "SPACE")
     {
         parity = QSerialPort::SpaceParity;
     }else if(ui->checkbit->currentText() == "MARK")
     {
         parity = QSerialPort::MarkParity;
     }

     if(ui->open_button->text() == QString("打开")){
      /*设置串口属性*/
        mySerial->setPortName(ui->port->currentText());//端口号，COM1,COM2...
        mySerial->setBaudRate(buadrate);
        mySerial->setDataBits(databits);
        mySerial->setStopBits(stopbits);
        mySerial->setParity(parity);

        /*串口打开情况下按键显示关闭*/
        ui->open_button->setText("关闭");

        if(mySerial->open(QIODevice::ReadWrite) == false)//打开串口失败
        {
         QMessageBox::warning(NULL,"提示","串口打开失败！");//弹出获取按钮
         return;
        }
        ui->port->setEnabled(false);                      //串口打开情况下,设置性质的按钮
        ui->baudrate->setEnabled(false);
        ui->databit->setEnabled(false);
        ui->checkbit->setEnabled(false);
        ui->stopbit->setEnabled(false);
      }
     else{
         mySerial->close();                             //关闭串口
         ui->open_button->setText("打开");
         ui->port->setEnabled(true);
         ui->baudrate->setEnabled(true);
         ui->databit->setEnabled(true);
         ui->checkbit->setEnabled(true);
         ui->stopbit->setEnabled(true);

     }


}

/***************************************
* func      :on_getport_button_clicked
* describe  :获取可用端口号 获取串口
* para      :none
* return    :none
* **************************************/
void qtSerialport::on_getport_button_clicked()//转到槽就可以编写槽函数代码 获取可用的端口号
{
    if(ui->open_button->text() == QString("关闭"))
    {
        return;
    }
    ui->port->clear();//清理端口
    QList<QSerialPortInfo> port;
    port = this->Get_Serial_Port();//获取可用的端口号 调用上级函数
    for(int i =0;i<port.size();i++){
        ui->port->addItem(port.at(i).portName());//用于将可用端口的名称添加到用户界面的下拉列表中
    }
}
/***************************************
* func      :Read_data
* describe  :读取串口接收的数据
* para      :none
* return    :none
* 要么转为hex方式 要么读原文
* **************************************/
void qtSerialport::Read_data()
{
    QByteArray recieve_data = mySerial->readAll();
    if(ui->r_hex->isChecked()){//如果hex勾选上了
        recieve_data = recieve_data.toHex().toUpper();
        refresh_text(ui->r_ed,recieve_data);
    }
    else{//如果没有勾选上，那么直接显示文字
        ui->r_ed->insertPlainText(QString(recieve_data));
    }

}
/***************************************
* func      :on_send_button_clicked
* describe  :发送串口数据
* para      :none
* return    :none
* **************************************/
void qtSerialport::on_send_button_clicked()
{
    QByteArray data_buf = ui->s_ed->toPlainText().toUtf8();
    if(ui->s_hex->isChecked()){
        if(data_buf.isEmpty()){
            return;
        }
        int cnt = data_buf.size();//要发送的字符的长度
        char *data = data_buf.data();//数据
        for(int i =0;i<cnt;i++){//检测是否有非法字节
            if((data[i])>='0'&&(data[i]<='9'))
                continue;
            else if((data[i])>='a'&&(data[i]<='f'))
                continue;
            else if((data[i])>='A'&&(data[i]<='F'))
                continue;
            else if((data[i])==' ')//输入为空格
                continue;
            else
            {
                QMessageBox::warning(NULL,"提示","输入非16进制");
                return;
            }

        }
        data_buf =data_buf.fromHex(data_buf);
    }
    mySerial->write(data_buf);

}

//清空接收到的数据
void qtSerialport::on_clear_recieve_button_clicked()
{
    ui->r_ed->clear();
}

//HEX状态改变的话
void qtSerialport::on_r_hex_stateChanged(int arg1)//传入状态发生变化
{
    QByteArray data_buf;
    data_buf = ui->r_ed->toPlainText().toUtf8();
    ui->r_ed->clear();
    if(arg1 == 2)//HEX选中
    {
        data_buf = data_buf.toHex().toUpper();//首先输出hex字符串 再将小写字母转换为大写字母
        refresh_text(ui->r_ed,data_buf);
    }
    else if(arg1 ==0){
          ui->r_ed->setText(QString(data_buf.fromHex(data_buf)));
    }

}

void qtSerialport::on_clearsend_button_clicked()//清除发送区
{
    ui->s_ed->clear();
}

void qtSerialport::on_s_hex_stateChanged(int arg1)
{
   QByteArray data_buf;
   data_buf = ui->s_ed->toPlainText().toUtf8();//将收到的字节流转化为字符
   ui->s_ed->clear();
   if(arg1 ==2)//hex选中
   {
       data_buf = data_buf.toHex().toUpper();
       refresh_text(ui->s_ed,data_buf);
   }
   else if(arg1 ==0){
       ui->s_ed->setText(QString(data_buf.fromHex(data_buf)));
   }
}
//勾选周期性函数
void qtSerialport::on_s_timer_stateChanged(int arg1)
{
    if(arg1 == false)//并没有选中
    {
        PriecSendTime->stop();//关闭定时器
        ui->s_ed->setEnabled(true);//使能输出窗口
    }
    else
     {
        //启动定时器
        PriecSendTime->start(ui->timer->text().toInt());//设置周期
        ui->s_ed->setEnabled(false);//关闭输出窗口
    }
}

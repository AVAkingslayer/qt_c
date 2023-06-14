#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>     // 提供系统中存在的串口信息
#include <QTextBrowser>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class qtSerialport : public QMainWindow
{
    Q_OBJECT

public:
    qtSerialport(QWidget *parent = nullptr);
    ~qtSerialport();
    QList<QSerialPortInfo> Get_Serial_Port();//获取端口可用号
     void refresh_text(QTextEdit *text,QByteArray temp);//更新串口

private slots://按键的槽函数

    void on_open_button_clicked();//打开
    void on_getport_button_clicked();//获取串口
    void Read_data();//读数据
    void on_send_button_clicked();//发数据

    void on_clear_recieve_button_clicked();//清理接收到的数据

    void on_r_hex_stateChanged(int arg1);//复选框勾上hex以后

    void on_clearsend_button_clicked();

    void on_s_hex_stateChanged(int arg1);

    void on_s_timer_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
    QSerialPort *mySerial;//串口对象
    QTimer *PriecSendTime;//周期发送定时器，和多行的循环发送公用
};
#endif // MAINWINDOW_H

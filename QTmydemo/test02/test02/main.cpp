

#include <QApplication>
#include <Qwidget>
#include <QPushButton>
#include <QMessageBox>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);//创建一个QT应用程序

    QWidget window;//创建一个窗口
    window.resize(500,120);//设置窗口大小 宽200像素 高120像素
    window.setWindowTitle("hello world");//设置窗口标题

    QPushButton button("click me",&window);//创建一个按钮，并将它添加到窗口
    button.setGeometry(10,10,80,30);//设置按钮的位置和大小 左上角位于（10,10），宽80像素，高30像素

    QObject::connect(&button,&QPushButton::clicked,[&](){//将按钮的clicked信号连接到一个lambda表达式上
        QMessageBox::information(&window,"message","Hello World!");//点击按钮时弹出一个对话框
    });

    window.show();//显示窗口
    return app.exec();

}

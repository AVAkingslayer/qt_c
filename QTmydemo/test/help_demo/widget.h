#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QProcess>
#include <QMessageBox>
//跳出一个对话框
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots://槽函数必须加上关键字

    void on_comitButton_clicked();//确认键
    void on_cancelButton_clicked();//取消键

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H

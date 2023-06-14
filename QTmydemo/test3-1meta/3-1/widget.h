#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <qperson.h>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
//自定义变量
private:
    QPerson *boy;
    QPerson *girl;
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    Ui::Widget *ui;
private slots:
    //自定义槽函数
    void on_ageChanged(int value);
    void on_spin_valueChanged(int argl);//spinbox
    //三个界面按钮的槽函数
    void on_BtnBotincr_clicked();//boy增长一岁

    void on_BtnGirlincr_clicked();//girl增长一岁

    void on_Btnclinfo_clicked();//元信息的查看

};
#endif // WIDGET_H

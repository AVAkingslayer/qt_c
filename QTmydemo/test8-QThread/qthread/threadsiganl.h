#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include    "qdicethread.h"
//处理按钮事件 +子线程连接的业务逻辑处理
QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class threadsiganl : public QDialog
{
    Q_OBJECT
private:
    qdicethread threadA;//子进程
protected:
    void closeEvent(QCloseEvent *event);//重载CloseEvent事件，在窗口关闭时确保线程被静止，在关闭窗口后会触发closeEvent
public:
    threadsiganl(QWidget *parent = nullptr);
    ~threadsiganl();
private slots:
    void    onthreadA_started();
    void    onthreadA_finished();
    void    onthreadA_newValue(int seq, int diceValue);

    void on_btnStartThread_clicked();

    void on_btnDiceBegin_clicked();

    void on_btnDiceEnd_clicked();

    void on_btnStopThread_clicked();

    void on_btnClear_clicked();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H

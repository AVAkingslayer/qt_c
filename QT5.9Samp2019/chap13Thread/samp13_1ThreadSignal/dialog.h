﻿#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include    "qdicethread.h"
//处理按钮事件 +子线程连接的业务逻辑处理
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

private:
    QDiceThread   threadA;//子线程
protected:
    void    closeEvent(QCloseEvent *event);

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void    onthreadA_started();
    void    onthreadA_finished();
    void    onthreadA_newValue(int seq, int diceValue);

    void on_btnClear_clicked();

    void on_btnDiceEnd_clicked();

    void on_btnDiceBegin_clicked();

    void on_btnStopThread_clicked();

    void on_btnStartThread_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H

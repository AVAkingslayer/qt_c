#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class helpWindow : public QMainWindow
{
    Q_OBJECT

public://构造函数，析构函数要改名字
    helpWindow(QWidget *parent = nullptr);
    ~helpWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

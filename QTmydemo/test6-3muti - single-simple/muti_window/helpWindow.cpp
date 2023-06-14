#include "helpWindow.h"
#include "ui_helpWindow.h"
#include    <QFileDialog>
#include "formdoc.h"
#include <QDebug>
helpWindow::helpWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

helpWindow::~helpWindow()
{
    delete ui;

}



void helpWindow::on_actWidgetInsite_triggered()//点击helpwidgeta按钮后 打开widget 独立窗口
{
    FormDoc *formDoc = new FormDoc(this);
    //formDoc->setAttribute(Qt::WA_DeleteOnClose);
    //关闭时自动删除
    formDoc->setWindowTitle("help_window");
    formDoc->setWindowFlag(Qt::Window,true);//独立窗口
    formDoc->setWindowFlag(Qt::CustomizeWindowHint,true);//允许用户自定义窗口
    formDoc ->setWindowFlag(Qt::WindowMinMaxButtonsHint,false);//关闭最小化最大化按钮
    formDoc->setWindowFlag(Qt::WindowCloseButtonHint,true);//显示关闭按钮
    //formDoc>setWindowFlag(Qt::WindowStaysOnTopHint,true);
    formDoc->setWindowOpacity(0.9);//窗口透明度
    //formDoc->setWindowModality(Qt::WindowModal);//设置窗体模态性，该模态类型下，当前窗口会阻塞父窗口以及其他兄弟窗口的交互能力
    formDoc->setWindowModality(Qt::NonModal);//设置窗体模态性，不会阻塞其他窗口
    formDoc->setFixedSize(800,600);//窗口大小可调
    formDoc->move(0, 100);//窗口位置初始化可调
    formDoc->show(); //在单独的窗口中显示
    qDebug() << "Entering  function3...";
}



void helpWindow::on_tabWidget_tabCloseRequested(int index)//tabwidget关闭的请求
{//关闭Tab
    if(ui->tabWidget->count()==1)ui->tabWidget->setVisible(false);//隐藏
    if(index<0)return;//如果是-1,就没有任何的子界面
    QWidget* tab = ui->tabWidget->widget(index);
    tab->close();
}



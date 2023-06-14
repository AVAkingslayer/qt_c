#include "mainwindow.h"
#include "ui_mainwindow.h"
#include    <QFileDialog>
#include "formdoc.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->tabWidget);//放置在中心
    setWindowState(Qt::WindowMaximized);//最大化mainwindow
    ui->tabWidget->clear();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actWidgetInsite_triggered()//点击helpwidget文档后 打开widget
{//创建QFromDoc窗体，并且在tabwidget中显示
    FormDoc *formDoc = new FormDoc(this);//创建一个FormDoc对象，并将主窗口指针作为父对象传递给它。
    formDoc->setAttribute(Qt::WA_DeleteOnClose);//关闭时自动删除，对象的内存空间会被自动释放，避免关闭多个formDoc对象，由于没有及时释放内存，导致内存泄漏
    int cur=ui->tabWidget->addTab(formDoc,QString::asprintf("help %d",ui->tabWidget->count()));//将formDoc对象添加到QTabWidget控件中，并将其显示在一个新的选项卡页上
    ui->tabWidget->setCurrentIndex(cur);//设置当前选中的选项卡为新添加的选项卡。
    ui->tabWidget->setVisible(true);//将QTabWidget控件设置为可见状态，确保新添加的选项卡可以在界面上显示出来。

}

void MainWindow::on_tabWidget_tabCloseRequested(int index)//tabwidget关闭的请求
{//关闭Tab
    if(ui->tabWidget->count()==1)ui->tabWidget->setVisible(false);//隐藏
    if(index<0)return;//如果是-1,就没有任何的子界面
    QWidget* tab = ui->tabWidget->widget(index);
    tab->close();
}

void MainWindow::keyPressEvent(QKeyEvent * event)//如果设置只读模式，就没有光标了。但是如果设置为编辑模式，enter键会直接改变文本，导致键值读不到。
{
    //当前widget响应按键事件
    // setFocusPolicy(Qt::StrongFocus);
    qDebug()<<event->key();
    switch (event->key())
    {

        case Qt::Key_Escape:
            {
            qDebug() <<"ESC";
            int currentIndex = ui->tabWidget->currentIndex();//删除对应的QTabWidget控件 获取当前tabWidget的值
            ui->tabWidget->removeTab(currentIndex);//删除tabwidget页面
            qDebug() <<currentIndex;//显示的是页面数
            break;}
        // 回车键
//        case Qt::Key_Return:
//            qDebug() <<"Enter";

//            break;
        // F1键
        case Qt::Key_F1:
            qDebug() <<"F1";
            break;
    }
 }

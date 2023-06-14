#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressBar>
#include <QLabel>
#include <QSpinBox>
#include <QFontComboBox>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
     //UI界面设计生成的槽函数
    void on_actbold_triggered(bool checked);//粗体Action
    void on_actitalic_triggered(bool checked);//斜体Action
    void on_actunderline_triggered(bool checked);//下划线Action

    void on_textEdit_copyAvailable(bool b);//当前选择的文字发生变化,更新粗体、斜体、下划线3个action的checked状态
    void on_textEdit_selectionChanged();//有文字可copy时更新cut,copy的Enable状态

//        void on_actNew_triggered();//新建文件
//        void on_actOpen_triggered();//打开文件

//        void on_actFont_triggered();//字体选择对话框
//        void on_actToolbarLab_triggered(bool checked); //设置工具栏按钮样式

    //  自定义槽函数
    void on_spinBoxFontSize_valueChanged(int aFontSize);//改变字体大小的SpinBox的响应
    void on_comboFont_currentIndexChanged(const QString &arg1);//FontCombobox的响应，选择字体名称

private:
    Ui::MainWindow *ui;

    QLabel *lable;
    QProgressBar *progressBar;
    QSpinBox *spinbox;
    QFontComboBox *fontcomboBox;
    void iniSignalSlots(); //关联信号与槽 connect
    void InitUI();//初始化
};


#endif // MAINWINDOW_H

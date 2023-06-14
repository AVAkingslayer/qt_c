#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::InitUI()//特别添加了不能直接UI添加的部件
{
    //设置底部状态栏 显示当前文件的label
    lable = new QLabel;
    lable->setMinimumWidth(150);//设置lable最小值
    lable->setText("设置当前文件：");
    ui->statusbar->addWidget(lable);//加载ui中的状态栏，并且做addwidget动作

    //设置进底部状态栏 显示字体大小的进度
    progressBar = new QProgressBar;
    progressBar->setMinimumWidth(200);//设置宽度200
    progressBar->setMaximum(50);//最大值
    progressBar->setMinimum(5);//最小值
    progressBar->setValue(ui->textEdit->font().pointSize());//progressBar的值就是textedit中的字体大小 常使用点（point）作为单位，不同于pixel
    ui->statusbar->addWidget(progressBar);//添加到状态栏

    //设置顶部工具栏 添加组件spinbox 数字添加框（调节字体大小）
    spinbox = new QSpinBox;
    spinbox->setMinimumWidth(50);
    spinbox->setMaximum(50);//最大值
    spinbox->setMinimum(5);//最小值
    spinbox->setValue(ui->textEdit->font().pointSize());
    ui->toolBar->addWidget(new QLabel("字体大小"));
    ui->toolBar->addWidget(spinbox);//把spinbox添加到工具栏

    ui->toolBar->addSeparator();//添加分隔条

    //添加字体格式到 工具栏
    ui->toolBar->addWidget(new QLabel("字体"));
    fontcomboBox =new QFontComboBox;
    fontcomboBox->setMinimumWidth(50);
    ui->toolBar->addWidget(fontcomboBox);
    setCentralWidget(ui->textEdit);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("MIX-UI");
    InitUI();//加载UI控件
    setCentralWidget(ui->textEdit);//设置窗口中心部件 ui->textEdit
    iniSignalSlots();
}

MainWindow::~MainWindow()
{
    delete ui;
}
//ui自动生成的槽函数
void MainWindow::on_actbold_triggered(bool checked)//connectslotsbyname 名字对应就可以直接用
{
    QTextCharFormat fmt;//设置字体格式
    if(checked)
        fmt.setFontWeight(QFont::Bold);
    else
        fmt.setFontWeight(QFont::Normal);
    ui->textEdit->mergeCurrentCharFormat(fmt);//应用到光标指定文本中
}

void MainWindow::on_actitalic_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt = ui->textEdit->currentCharFormat();//获取当前光标文字，跟上面的功能一样
    fmt.setFontItalic(checked);
    ui->textEdit->mergeCurrentCharFormat(fmt);

}


void MainWindow::on_actunderline_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt=ui->textEdit->currentCharFormat();
    fmt.setFontUnderline(checked);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}

void MainWindow::on_textEdit_copyAvailable(bool b)//有文字可copy时更新cut,copy的Enable状态
{
    ui->actcut->setEnabled(b);
    ui->actcopy->setEnabled(b);
    ui->actpaste->setEnabled(b);
}

void MainWindow::on_textEdit_selectionChanged()//当前选择的文字发生变化，更新粗体、斜体、下划线3个action的checked状态 不加的话不能重叠状态
{
    QTextCharFormat fmt;
    fmt = ui->textEdit->currentCharFormat();//获取文字格式
    ui->actitalic->setChecked(fmt.fontItalic());//是否斜体
    ui->actbold->setChecked(fmt.font().bold()); //是否粗体
    ui->actunderline->setChecked(fmt.fontUnderline()); //是否有下划线
}


//自定义槽函数
void MainWindow::on_spinBoxFontSize_valueChanged(int aFontSize)//改变字体大小spinbox
{
     QTextCharFormat fmt;
     fmt.setFontPointSize(aFontSize);//设置字体大小
     ui->textEdit->mergeCurrentCharFormat(fmt);//更新
     progressBar->setValue(aFontSize);//把bar值与字体大小进行关联

}

void MainWindow::on_comboFont_currentIndexChanged(const QString &arg1)//选择字体
{
     QTextCharFormat fmt;
     fmt.setFontFamily(arg1);//设置字体名字
     ui->textEdit->mergeCurrentCharFormat(fmt);
}

void MainWindow::iniSignalSlots()//关联信号与槽函数
{
    connect(spinbox,SIGNAL(valueChanged(int)),this,SLOT(on_spinBoxFontSize_valueChanged(int)));//更改字体大小与槽函数进行关联
    connect(fontcomboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(on_comboFont_currentIndexChanged(const QString &)));//更改字体样式与槽函数关联

}

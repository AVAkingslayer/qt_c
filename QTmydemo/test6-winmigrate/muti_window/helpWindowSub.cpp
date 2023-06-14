#include "helpWindowSub.h"
#include "ui_helpWindowSub.h"
#include <QTextCursor>

HelpWindowSub::HelpWindowSub(QWidget *parent) :
   QWidget(parent),
    ui(new Ui::HelpWindowSub)
{

    ui->setupUi(this);
    textEdit = new QTextEdit(this);
     // 创建垂直布局管理器并添加子控件
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(textEdit);
    // 设置当前QWidget的布局管理器
     setLayout(layout);
     // 加载并显示HTML文件
     loadHtmlFile("F:/UESTC/qt_demo/QTmydemo/QT5.9/test6-3muti - single-simple/muti_window/ES2448UM.htm");
     // 设置窗口固定大小
      setFixedSize(800, 600);  // 设置宽度为800，高度为600
      setWindowTitle("帮助窗口");
      setWindowModality(Qt::NonModal);//设置窗体模态性，不会阻塞其他窗口);
     // 创建状态栏
     statusBar = new QStatusBar(this);
     // 添加状态栏
     layout->addWidget(statusBar);//继承widget类，跟mainwindow有区别
     //statusBar->showMessage("返回到目录");
     QPushButton *backButton = new QPushButton("Back", this);//定义back按钮
     connect(backButton, &QPushButton::clicked, this, &HelpWindowSub::on_backButton_clicked);//按下back键，返回到文档的第一页
     //layout->addWidget(backButton);//直接跑到状态栏外面去了
     statusBar->addPermanentWidget(backButton);

}

HelpWindowSub::~HelpWindowSub()
{
    delete ui;
}

void HelpWindowSub::loadHtmlFile(const QString& filePath)
{
    // 读取HTML文件的内容
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
        QString htmlContent = stream.readAll();
        file.close();

        // 设置QTextEdit对象的HTML内容
        textEdit->setHtml(htmlContent);
    }
}

void HelpWindowSub::on_backButton_clicked()
{
    // 在这里编写处理返回按钮点击事件的代码
    QTextCursor cursor = textEdit->textCursor();
    cursor.movePosition(QTextCursor::Start);
    textEdit->setTextCursor(cursor);
}


#include "formdoc.h"
#include "ui_formdoc.h"
#include <QTextCursor>

FormDoc::FormDoc(QWidget *parent) :
   QWidget(parent),
    ui(new Ui::FormDoc)
{

    ui->setupUi(this);
    // 创建QTextEdit对象
    textEdit = new QTextEdit(this);
     // 创建垂直布局管理器并添加子控件
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(textEdit);
    // 设置当前QWidget的布局管理器
     setLayout(layout);
     // 加载并显示HTML文件
     loadHtmlFile("F:/UESTC/qt_demo/QTmydemo/QT5.9/test6-3muti - C-single/muti_window/ES.htm");

     // 创建状态栏
     statusBar = new QStatusBar(this);
     // 添加状态栏
     layout->addWidget(statusBar);//继承widget类，跟mainwindow有区别
     //statusBar->showMessage("返回到目录");
     QPushButton *backButton = new QPushButton("Back", this);//定义back按钮
     connect(backButton, &QPushButton::clicked, this, &FormDoc::on_backButton_clicked);//按下back键，返回到文档的第一页
     //layout->addWidget(backButton);//直接跑到状态栏外面去了
     statusBar->addPermanentWidget(backButton);

     //在formDoc中处理按钮点击事件

}

FormDoc::~FormDoc()
{
    delete ui;
}

void FormDoc::loadHtmlFile(const QString& filePath)
{
    // 读取HTML文件的内容
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
        QString htmlContent = stream.readAll();
        file.close();

        // 设置QTextEdit对象的HTML内容
        //textEdit->setReadOnly(true);
        textEdit->setHtml(htmlContent);
    }
}

void FormDoc::on_backButton_clicked()
{
    // 在这里编写处理返回按钮点击事件的代码
}

void FormDoc::moveCursorUp()
{
    QTextCursor cursor = textEdit->textCursor();
    cursor.movePosition(QTextCursor::Up);
    textEdit->setTextCursor(cursor);
}

void FormDoc::moveCursorDown()
{
    QTextCursor cursor = textEdit->textCursor();
    cursor.movePosition(QTextCursor::Down);
    textEdit->setTextCursor(cursor);
}

void FormDoc::moveCursorLeft()
{
    QTextCursor cursor = textEdit->textCursor();
    cursor.movePosition(QTextCursor::Left);
    textEdit->setTextCursor(cursor);
}

void FormDoc::moveCursorRight()
{
    QTextCursor cursor = textEdit->textCursor();
    cursor.movePosition(QTextCursor::Right);
    textEdit->setTextCursor(cursor);
}

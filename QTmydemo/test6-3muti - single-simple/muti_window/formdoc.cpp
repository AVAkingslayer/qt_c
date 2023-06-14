#include "formdoc.h"
#include "ui_formdoc.h"
#include <QTextCursor>
#include <QTextDocument>
#include <QTextBlock>
#include <QScrollBar>
#include <QAbstractTextDocumentLayout>
#include <QTextBlockUserData>
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
     loadHtmlFile("F:/UESTC/qt_demo/QTmydemo/QT5.9/test6-3muti - single-simple/muti_window/ES2448UM.htm");

     // 创建状态栏
     statusBar = new QStatusBar(this);
     // 添加状态栏
     layout->addWidget(statusBar);//继承widget类，跟mainwindow有区别
     //statusBar->showMessage("返回到目录");
     QPushButton *nextpageButton = new QPushButton("下一页", this);//定义翻页按钮
     QPushButton *lastpageButton = new QPushButton("上一页", this);//定义翻页按钮
     QPushButton *backButton = new QPushButton("back", this);//定义back按钮
     statusBar->addPermanentWidget(nextpageButton);
     statusBar->addPermanentWidget(lastpageButton);
     statusBar->addPermanentWidget(backButton);

     connect(backButton, &QPushButton::clicked, this, &FormDoc::on_backButton_clicked);//按下back键，返回到文档的第一页
    //connect(nextpageButton, &QPushButton::clicked, this, &FormDoc::on_nextPageButton_clicked);//按下nextpageButton键，返回到文档的第一页
     //connect(lastpageButton, &QPushButton::clicked, this, &FormDoc::on_previousPageButton_clicked);//按下lastpageButton键，返回到文档的第一页
     //QTextCursor cursor=textEdit->textCursor();//定义光标
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
        textEdit->setHtml(htmlContent);
    }
}

void FormDoc::on_backButton_clicked()
{
    // 在这里编写处理返回按钮点击事件的代码
    QTextCursor cursor = textEdit->textCursor();
    cursor.movePosition(QTextCursor::Start);
    textEdit->setTextCursor(cursor);
}



void FormDoc::on_nextPageButton_clicked()
{
    QTextCursor cursor=textEdit->textCursor();//定义光标
    cursor.movePosition(QTextCursor::End);//Block不好用
    textEdit->setTextCursor(cursor);
}



void FormDoc::on_previousPageButton_clicked()
{


}

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 创建QTextEdit对象
     textEdit = new QTextEdit(this);
     setCentralWidget(textEdit);
     QTextCursor cursor = textEdit->textCursor();
     //jumpToAnchor(textEdit,"myanchor");
    // 加载并显示HTML文件
     loadHtmlFile("F:/UESTC/qt_demo/QTmydemo/QT5.9/test6-4openhtmtxt/test6_4openhtmtxt/ES4712UM.mht");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadHtmlFile(const QString& filePath)
{
    // 读取HTML文件的内容
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
         stream.setCodec("UTF-8");
        QString htmlContent = stream.readAll();
        file.close();

        // 设置QTextEdit对象的HTML内容
        //textEdit->setReadOnly(true);
        textEdit->setHtml(htmlContent);
    }
}

void MainWindow::jumpToAnchor(QTextEdit* textEdit, const QString& anchor)
{
    // 获取文档光标
    QTextCursor cursor = textEdit->textCursor();

    // 从文档开始位置开始查找超链接
    cursor.setPosition(0);
    while (!cursor.isNull()) {
        if (cursor.anchor() == anchor) {
            // 如果找到了超链接，则将光标移动到该超链接位置，并滚动到该位置
            textEdit->setTextCursor(cursor);
            textEdit->scrollToAnchor(anchor);
            break;
        }
        // 继续查找下一个字符
        cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor, 0);
    }
}


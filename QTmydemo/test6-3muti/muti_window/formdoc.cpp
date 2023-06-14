#include "formdoc.h"
#include "ui_formdoc.h"


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
     loadHtmlFile("F:/UESTC/qt_demo/QTmydemo/QT5.9/test6-4openhtmtxt/test6_4openhtmtxt/ES2448UM.htm");


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




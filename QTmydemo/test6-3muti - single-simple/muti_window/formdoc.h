#ifndef FORMDOC_H
#define FORMDOC_H

#include <QWidget>
#include <QtCore/QObject>
#include <QTextBrowser>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QDebug>
#include <QKeyEvent>
#include <QTextCursor>
#include <QStatusBar>
#include <QPushButton>
#include <QTextBlockUserData>
namespace Ui {
class FormDoc;
}

class FormDoc : public QWidget
{
    Q_OBJECT

public:
    explicit FormDoc(QWidget *parent = nullptr);
    ~FormDoc();

private:
    Ui::FormDoc *ui;
    QTextEdit* textEdit;
    QVBoxLayout* layout;
    QTextBrowser* textBrowser;//浏览窗口
    QStatusBar *statusBar;//底部状态栏
    QPushButton *backButton;//返回跳转按钮
    QPushButton *nextpageButton;//下一页按钮
    QPushButton *lastpageButton;//上一页按钮
    FormDoc *formDoc;  // 添加成员变量
    QTextBlockUserData *userData;
    //QTextCursor cursor;

private slots:
    void loadHtmlFile(const QString& filePath);
    void on_backButton_clicked();//back按钮
    void on_nextPageButton_clicked();//向后翻页
    void on_previousPageButton_clicked();//向前翻页

};

#endif // FORMDOC_H

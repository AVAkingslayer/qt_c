#ifndef HELPWINDOWSUB_H
#define HELPWINDOWSUB_H

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

namespace Ui {
class HelpWindowSub;
}

class HelpWindowSub : public QWidget
{
    Q_OBJECT

public:
    explicit HelpWindowSub(QWidget *parent = nullptr);
    ~HelpWindowSub();

private:
    Ui::HelpWindowSub *ui;
    QTextEdit* textEdit;
    QVBoxLayout* layout;
    QTextBrowser* textBrowser;//浏览窗口
    QStatusBar *statusBar;//底部状态栏
    QPushButton *backButton;//返回跳转按钮
    HelpWindowSub *helpWindowSub;  // 添加成员变量
private slots:
    void loadHtmlFile(const QString& filePath);
    void on_backButton_clicked();//back按钮

};

#endif // HELPWINDOWSUB_H

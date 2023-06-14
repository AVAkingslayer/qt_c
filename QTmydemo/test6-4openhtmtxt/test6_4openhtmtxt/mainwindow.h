#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QTextBrowser>
#include <QTextCursor>
#include <libmhtml/mhtml.hpp>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTextEdit* textEdit;
    QTextCursor cursor;
    void loadHtmlFile(const QString& filePath);
    void jumpToAnchor(QTextEdit* textEdit, const QString& anchor);
};
#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore/QObject>
#include "helpWindowSub.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class helpWindow : public QMainWindow
{
    Q_OBJECT

public:
    helpWindow(QWidget *parent = nullptr);
    ~helpWindow();

private slots:
    void on_actWidgetInsite_triggered();
    void on_tabWidget_tabCloseRequested(int index);

private:
    Ui::MainWindow *ui;
    HelpWindowSub *helpWindowSub;//改名

};
#endif // MAINWINDOW_H

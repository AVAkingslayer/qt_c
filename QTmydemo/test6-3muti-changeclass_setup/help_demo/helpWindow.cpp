#include "helpWindow.h"
#include "ui_helpWindow.h"

helpWindow::helpWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

helpWindow::~helpWindow()
{
    delete ui;
}


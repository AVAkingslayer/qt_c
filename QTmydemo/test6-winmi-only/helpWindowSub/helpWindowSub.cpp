#include "helpWindowSub.h"
#include "ui_helpWindowSub.h"

helpWindowSub::helpWindowSub(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

}

helpWindowSub::~helpWindowSub()
{
    delete ui;
}


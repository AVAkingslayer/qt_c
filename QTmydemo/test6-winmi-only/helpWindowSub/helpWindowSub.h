#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class helpWindowSub : public QWidget
{
    Q_OBJECT

public:
    helpWindowSub(QWidget *parent = nullptr);
    ~helpWindowSub();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H

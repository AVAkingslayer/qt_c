/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *cmdlineEdit;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *comitButton;
    QPushButton *brosesbutton;
    QPushButton *cancelButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(800, 600);
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 80, 101, 16));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(80, 130, 68, 15));
        cmdlineEdit = new QLineEdit(Widget);
        cmdlineEdit->setObjectName(QStringLiteral("cmdlineEdit"));
        cmdlineEdit->setGeometry(QRect(160, 130, 113, 21));
        widget = new QWidget(Widget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(50, 180, 293, 30));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        comitButton = new QPushButton(widget);
        comitButton->setObjectName(QStringLiteral("comitButton"));

        horizontalLayout->addWidget(comitButton);

        brosesbutton = new QPushButton(widget);
        brosesbutton->setObjectName(QStringLiteral("brosesbutton"));

        horizontalLayout->addWidget(brosesbutton);

        cancelButton = new QPushButton(widget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "\350\257\267\350\276\223\345\205\245\345\221\275\344\273\244", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "\346\211\223\345\274\200\357\274\232", Q_NULLPTR));
        comitButton->setText(QApplication::translate("Widget", "\347\241\256\345\256\232", Q_NULLPTR));
        brosesbutton->setText(QApplication::translate("Widget", "\346\265\217\350\247\210", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("Widget", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

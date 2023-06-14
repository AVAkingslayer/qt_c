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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *labelBoy;
    QSpinBox *spinBoxBoy;
    QPushButton *BtnBotincr;
    QPushButton *Btnclinfo;
    QLabel *labelGirl;
    QSpinBox *spinBoxGirl;
    QPushButton *BtnGirlincr;
    QPushButton *Btnclear;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(439, 340);
        gridLayout_2 = new QGridLayout(Widget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        labelBoy = new QLabel(Widget);
        labelBoy->setObjectName(QStringLiteral("labelBoy"));

        gridLayout->addWidget(labelBoy, 0, 0, 1, 1);

        spinBoxBoy = new QSpinBox(Widget);
        spinBoxBoy->setObjectName(QStringLiteral("spinBoxBoy"));

        gridLayout->addWidget(spinBoxBoy, 0, 1, 1, 1);

        BtnBotincr = new QPushButton(Widget);
        BtnBotincr->setObjectName(QStringLiteral("BtnBotincr"));

        gridLayout->addWidget(BtnBotincr, 0, 2, 1, 1);

        Btnclinfo = new QPushButton(Widget);
        Btnclinfo->setObjectName(QStringLiteral("Btnclinfo"));

        gridLayout->addWidget(Btnclinfo, 0, 3, 1, 1);

        labelGirl = new QLabel(Widget);
        labelGirl->setObjectName(QStringLiteral("labelGirl"));

        gridLayout->addWidget(labelGirl, 1, 0, 1, 1);

        spinBoxGirl = new QSpinBox(Widget);
        spinBoxGirl->setObjectName(QStringLiteral("spinBoxGirl"));

        gridLayout->addWidget(spinBoxGirl, 1, 1, 1, 1);

        BtnGirlincr = new QPushButton(Widget);
        BtnGirlincr->setObjectName(QStringLiteral("BtnGirlincr"));

        gridLayout->addWidget(BtnGirlincr, 1, 2, 1, 1);

        Btnclear = new QPushButton(Widget);
        Btnclear->setObjectName(QStringLiteral("Btnclear"));

        gridLayout->addWidget(Btnclear, 1, 3, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        plainTextEdit = new QPlainTextEdit(Widget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        gridLayout_2->addWidget(plainTextEdit, 1, 0, 1, 1);


        retranslateUi(Widget);
        QObject::connect(Btnclear, SIGNAL(clicked()), plainTextEdit, SLOT(clear()));

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        labelBoy->setText(QApplication::translate("Widget", "\350\256\276\347\275\256\347\224\267\345\255\251\345\271\264\351\276\204", Q_NULLPTR));
        BtnBotincr->setText(QApplication::translate("Widget", "boy\351\225\277\345\244\247\344\270\200\345\262\201", Q_NULLPTR));
        Btnclinfo->setText(QApplication::translate("Widget", "\347\261\273\347\232\204\345\205\203\345\257\271\350\261\241\344\277\241\346\201\257", Q_NULLPTR));
        labelGirl->setText(QApplication::translate("Widget", "\350\256\276\347\275\256\345\245\263\345\255\251\345\271\264\351\276\204", Q_NULLPTR));
        BtnGirlincr->setText(QApplication::translate("Widget", "girl\351\225\277\345\244\247\344\270\200\345\262\201", Q_NULLPTR));
        Btnclear->setText(QApplication::translate("Widget", "\346\270\205\347\251\272\346\226\207\346\234\254\346\241\206", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

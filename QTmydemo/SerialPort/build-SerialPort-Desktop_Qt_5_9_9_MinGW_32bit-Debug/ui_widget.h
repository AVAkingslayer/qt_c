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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QLabel *label_3;
    QComboBox *comboBox_3;
    QLabel *label_4;
    QComboBox *comboBox_4;
    QLabel *label_5;
    QComboBox *comboBox_5;
    QLabel *label_6;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QLabel *label_11;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_8;
    QLabel *label_10;
    QPushButton *pushButton_8;
    QCheckBox *checkBox_7;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(928, 638);
        textEdit = new QTextEdit(Widget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(190, 30, 561, 391));
        textEdit_2 = new QTextEdit(Widget);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(190, 450, 481, 91));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 30, 141, 31));
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(30, 210, 141, 31));
        pushButton_2->setCheckable(true);
        pushButton_2->setChecked(false);
        pushButton_2->setAutoRepeatInterval(-1);
        pushButton_2->setAutoDefault(false);
        formLayoutWidget = new QWidget(Widget);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(30, 70, 157, 141));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        comboBox = new QComboBox(formLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBox);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setFamily(QStringLiteral("3ds"));
        label_2->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        comboBox_2 = new QComboBox(formLayoutWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        formLayout->setWidget(1, QFormLayout::FieldRole, comboBox_2);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        comboBox_3 = new QComboBox(formLayoutWidget);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));

        formLayout->setWidget(2, QFormLayout::FieldRole, comboBox_3);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        comboBox_4 = new QComboBox(formLayoutWidget);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));

        formLayout->setWidget(3, QFormLayout::FieldRole, comboBox_4);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        comboBox_5 = new QComboBox(formLayoutWidget);
        comboBox_5->setObjectName(QStringLiteral("comboBox_5"));

        formLayout->setWidget(4, QFormLayout::FieldRole, comboBox_5);

        label_6 = new QLabel(Widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 260, 71, 16));
        verticalLayoutWidget = new QWidget(Widget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 280, 121, 131));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        checkBox = new QCheckBox(verticalLayoutWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        verticalLayout->addWidget(checkBox);

        checkBox_2 = new QCheckBox(verticalLayoutWidget);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        verticalLayout->addWidget(checkBox_2);

        checkBox_3 = new QCheckBox(verticalLayoutWidget);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));

        verticalLayout->addWidget(checkBox_3);

        pushButton_4 = new QPushButton(verticalLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        label_11 = new QLabel(Widget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(30, 430, 61, 16));
        verticalLayoutWidget_2 = new QWidget(Widget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(30, 450, 121, 131));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        checkBox_4 = new QCheckBox(verticalLayoutWidget_2);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));

        verticalLayout_2->addWidget(checkBox_4);

        checkBox_5 = new QCheckBox(verticalLayoutWidget_2);
        checkBox_5->setObjectName(QStringLiteral("checkBox_5"));

        verticalLayout_2->addWidget(checkBox_5);

        checkBox_6 = new QCheckBox(verticalLayoutWidget_2);
        checkBox_6->setObjectName(QStringLiteral("checkBox_6"));

        verticalLayout_2->addWidget(checkBox_6);

        pushButton_5 = new QPushButton(verticalLayoutWidget_2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        verticalLayout_2->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(verticalLayoutWidget_2);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        verticalLayout_2->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(Widget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(680, 450, 71, 91));
        horizontalLayoutWidget = new QWidget(Widget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(190, 550, 481, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(horizontalLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout->addWidget(label_7);

        label_9 = new QLabel(horizontalLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout->addWidget(label_9);

        label_8 = new QLabel(horizontalLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout->addWidget(label_8);

        label_10 = new QLabel(horizontalLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout->addWidget(label_10);

        pushButton_8 = new QPushButton(horizontalLayoutWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        horizontalLayout->addWidget(pushButton_8);

        checkBox_7 = new QCheckBox(horizontalLayoutWidget);
        checkBox_7->setObjectName(QStringLiteral("checkBox_7"));

        horizontalLayout->addWidget(checkBox_7);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lineEdit = new QLineEdit(horizontalLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMaximumSize(QSize(71, 16777215));
        lineEdit->setMouseTracking(false);

        horizontalLayout_2->addWidget(lineEdit);

        label_12 = new QLabel(horizontalLayoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMaximumSize(QSize(12, 16777215));

        horizontalLayout_2->addWidget(label_12);


        horizontalLayout->addLayout(horizontalLayout_2);

        label_13 = new QLabel(Widget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(30, 10, 61, 16));
        label_14 = new QLabel(Widget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(190, 10, 54, 12));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Widget", "\346\211\253\346\217\217\344\270\262\345\217\243", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Widget", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "\344\270\262\345\217\243\345\217\267\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "\346\263\242\347\211\271\347\216\207\357\274\232", Q_NULLPTR));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("Widget", "300", Q_NULLPTR)
         << QApplication::translate("Widget", "600", Q_NULLPTR)
         << QApplication::translate("Widget", "1200", Q_NULLPTR)
         << QApplication::translate("Widget", "2400", Q_NULLPTR)
         << QApplication::translate("Widget", "4800", Q_NULLPTR)
         << QApplication::translate("Widget", "9600", Q_NULLPTR)
         << QApplication::translate("Widget", "14400", Q_NULLPTR)
         << QApplication::translate("Widget", "19200", Q_NULLPTR)
         << QApplication::translate("Widget", "38400", Q_NULLPTR)
         << QApplication::translate("Widget", "56000", Q_NULLPTR)
         << QApplication::translate("Widget", "57600", Q_NULLPTR)
         << QApplication::translate("Widget", "115200", Q_NULLPTR)
         << QApplication::translate("Widget", "128000", Q_NULLPTR)
         << QApplication::translate("Widget", "256000", Q_NULLPTR)
         << QApplication::translate("Widget", "460800", Q_NULLPTR)
        );
        label_3->setText(QApplication::translate("Widget", "\346\225\260\346\215\256\344\275\215\357\274\232", Q_NULLPTR));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("Widget", "5", Q_NULLPTR)
         << QApplication::translate("Widget", "6", Q_NULLPTR)
         << QApplication::translate("Widget", "7", Q_NULLPTR)
         << QApplication::translate("Widget", "8", Q_NULLPTR)
        );
        label_4->setText(QApplication::translate("Widget", "\346\240\241\351\252\214\344\275\215\357\274\232", Q_NULLPTR));
        comboBox_4->clear();
        comboBox_4->insertItems(0, QStringList()
         << QApplication::translate("Widget", "Even", Q_NULLPTR)
         << QApplication::translate("Widget", "Mark", Q_NULLPTR)
         << QApplication::translate("Widget", "None", Q_NULLPTR)
         << QApplication::translate("Widget", "Odd", Q_NULLPTR)
        );
        label_5->setText(QApplication::translate("Widget", "\345\201\234\346\255\242\344\275\215\357\274\232", Q_NULLPTR));
        comboBox_5->clear();
        comboBox_5->insertItems(0, QStringList()
         << QApplication::translate("Widget", "One", Q_NULLPTR)
         << QApplication::translate("Widget", "OnePoimtFive", Q_NULLPTR)
         << QApplication::translate("Widget", "Two", Q_NULLPTR)
        );
        label_6->setText(QApplication::translate("Widget", "\346\216\245\346\224\266\345\214\272\350\256\276\347\275\256", Q_NULLPTR));
        checkBox->setText(QApplication::translate("Widget", "\346\226\207\346\234\254\346\216\245\346\224\266", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("Widget", "\345\215\201\345\205\255\350\277\233\345\210\266\346\216\245\346\224\266", Q_NULLPTR));
        checkBox_3->setText(QApplication::translate("Widget", "\346\232\202\345\201\234\346\216\245\346\224\266", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Widget", "\346\270\205\347\251\272\346\216\245\346\224\266\345\214\272", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Widget", "\344\277\235\345\255\230\346\226\207\344\273\266", Q_NULLPTR));
        label_11->setText(QApplication::translate("Widget", "\345\217\221\351\200\201\345\214\272\350\256\276\347\275\256", Q_NULLPTR));
        checkBox_4->setText(QApplication::translate("Widget", "\346\226\207\346\234\254\345\217\221\351\200\201", Q_NULLPTR));
        checkBox_5->setText(QApplication::translate("Widget", "\345\215\201\345\205\255\350\277\233\345\210\266\345\217\221\351\200\201", Q_NULLPTR));
        checkBox_6->setText(QApplication::translate("Widget", "\350\207\252\345\212\250\346\215\242\350\241\214", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("Widget", "\346\211\223\345\274\200\346\226\207\344\273\266", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("Widget", "\346\270\205\351\231\244\345\217\221\351\200\201\345\214\272", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("Widget", "\345\217\221\351\200\201", Q_NULLPTR));
        label_7->setText(QApplication::translate("Widget", "\345\217\221\351\200\201\345\255\227\350\212\202\357\274\232", Q_NULLPTR));
        label_9->setText(QApplication::translate("Widget", "0", Q_NULLPTR));
        label_8->setText(QApplication::translate("Widget", "\346\216\245\346\224\266\345\255\227\350\212\202\357\274\232", Q_NULLPTR));
        label_10->setText(QApplication::translate("Widget", "0", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("Widget", "\345\244\215\344\275\215\350\256\241\346\225\260", Q_NULLPTR));
        checkBox_7->setText(QApplication::translate("Widget", "\345\256\232\346\227\266\345\217\221\351\200\201", Q_NULLPTR));
        label_12->setText(QApplication::translate("Widget", "ms", Q_NULLPTR));
        label_13->setText(QApplication::translate("Widget", "\344\270\262\345\217\243\350\256\276\347\275\256", Q_NULLPTR));
        label_14->setText(QApplication::translate("Widget", "\346\225\260\346\215\256\346\230\276\347\244\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

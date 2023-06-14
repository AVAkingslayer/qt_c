/********************************************************************************
** Form generated from reading UI file 'qtSerialport.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTSERIALPORT_H
#define UI_QTSERIALPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *label;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QPushButton *open_button;
    QComboBox *stopbit;
    QComboBox *databit;
    QLabel *label_2;
    QPushButton *clear_recieve_button;
    QLabel *label_3;
    QCheckBox *r_hex;
    QPushButton *getport_button;
    QComboBox *checkbit;
    QLabel *label_4;
    QLabel *label_6;
    QComboBox *baudrate;
    QComboBox *port;
    QGroupBox *groupBox_2;
    QLabel *label_7;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QPushButton *clearsend_button;
    QPushButton *send_button;
    QCheckBox *s_hex;
    QCheckBox *s_timer;
    QLineEdit *timer;
    QGroupBox *groupBox_3;
    QLabel *label_13;
    QTextEdit *s_ed;
    QGroupBox *groupBox_4;
    QLabel *label_14;
    QTextEdit *r_ed;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(814, 490);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(580, 20, 211, 291));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 68, 15));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 40, 201, 241));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        open_button = new QPushButton(layoutWidget);
        open_button->setObjectName(QStringLiteral("open_button"));

        gridLayout->addWidget(open_button, 7, 0, 1, 1);

        stopbit = new QComboBox(layoutWidget);
        stopbit->setObjectName(QStringLiteral("stopbit"));

        gridLayout->addWidget(stopbit, 4, 1, 1, 1);

        databit = new QComboBox(layoutWidget);
        databit->setObjectName(QStringLiteral("databit"));

        gridLayout->addWidget(databit, 2, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setTextFormat(Qt::AutoText);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        clear_recieve_button = new QPushButton(layoutWidget);
        clear_recieve_button->setObjectName(QStringLiteral("clear_recieve_button"));

        gridLayout->addWidget(clear_recieve_button, 8, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        r_hex = new QCheckBox(layoutWidget);
        r_hex->setObjectName(QStringLiteral("r_hex"));

        gridLayout->addWidget(r_hex, 8, 0, 1, 1);

        getport_button = new QPushButton(layoutWidget);
        getport_button->setObjectName(QStringLiteral("getport_button"));

        gridLayout->addWidget(getport_button, 7, 1, 1, 1);

        checkbit = new QComboBox(layoutWidget);
        checkbit->setObjectName(QStringLiteral("checkbit"));

        gridLayout->addWidget(checkbit, 5, 1, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        baudrate = new QComboBox(layoutWidget);
        baudrate->setObjectName(QStringLiteral("baudrate"));
        baudrate->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(baudrate, 1, 1, 1, 1);

        port = new QComboBox(layoutWidget);
        port->setObjectName(QStringLiteral("port"));

        gridLayout->addWidget(port, 0, 1, 1, 1);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(570, 320, 221, 141));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 10, 68, 20));
        layoutWidget1 = new QWidget(groupBox_2);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 30, 194, 77));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        clearsend_button = new QPushButton(layoutWidget1);
        clearsend_button->setObjectName(QStringLiteral("clearsend_button"));

        gridLayout_2->addWidget(clearsend_button, 0, 1, 1, 1);

        send_button = new QPushButton(layoutWidget1);
        send_button->setObjectName(QStringLiteral("send_button"));

        gridLayout_2->addWidget(send_button, 0, 0, 1, 1);

        s_hex = new QCheckBox(layoutWidget1);
        s_hex->setObjectName(QStringLiteral("s_hex"));

        gridLayout_2->addWidget(s_hex, 1, 0, 1, 1);

        s_timer = new QCheckBox(layoutWidget1);
        s_timer->setObjectName(QStringLiteral("s_timer"));

        gridLayout_2->addWidget(s_timer, 2, 0, 1, 1);

        timer = new QLineEdit(layoutWidget1);
        timer->setObjectName(QStringLiteral("timer"));
        timer->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(timer, 2, 1, 1, 1, Qt::AlignRight);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 290, 541, 171));
        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 10, 68, 15));
        s_ed = new QTextEdit(groupBox_3);
        s_ed->setObjectName(QStringLiteral("s_ed"));
        s_ed->setGeometry(QRect(10, 30, 511, 121));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(20, 20, 541, 261));
        label_14 = new QLabel(groupBox_4);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(10, 10, 68, 15));
        r_ed = new QTextEdit(groupBox_4);
        r_ed->setObjectName(QStringLiteral("r_ed"));
        r_ed->setGeometry(QRect(10, 20, 511, 231));
        MainWindow->setCentralWidget(centralwidget);
        groupBox_4->raise();
        groupBox_3->raise();
        groupBox_2->raise();
        groupBox->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 814, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("MainWindow", "\346\216\247\345\210\266\345\214\272", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215", Q_NULLPTR));
        open_button->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200", Q_NULLPTR));
        stopbit->clear();
        stopbit->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", Q_NULLPTR)
         << QApplication::translate("MainWindow", "2", Q_NULLPTR)
        );
        databit->clear();
        databit->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "7", Q_NULLPTR)
         << QApplication::translate("MainWindow", "8", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("MainWindow", "\347\253\257\345\217\243", Q_NULLPTR));
        clear_recieve_button->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\346\216\245\346\224\266", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        r_hex->setText(QApplication::translate("MainWindow", "HEX", Q_NULLPTR));
        getport_button->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226\344\270\262\345\217\243", Q_NULLPTR));
        checkbit->clear();
        checkbit->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "NONE", Q_NULLPTR)
         << QApplication::translate("MainWindow", "ODD", Q_NULLPTR)
         << QApplication::translate("MainWindow", "EVEN", Q_NULLPTR)
         << QApplication::translate("MainWindow", "MARK", Q_NULLPTR)
        );
        label_4->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215", Q_NULLPTR));
        baudrate->clear();
        baudrate->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1200", Q_NULLPTR)
         << QApplication::translate("MainWindow", "2400", Q_NULLPTR)
         << QApplication::translate("MainWindow", "4800", Q_NULLPTR)
         << QApplication::translate("MainWindow", "9600", Q_NULLPTR)
         << QApplication::translate("MainWindow", "19200", Q_NULLPTR)
         << QApplication::translate("MainWindow", "38400", Q_NULLPTR)
         << QApplication::translate("MainWindow", "57600", Q_NULLPTR)
        );
        groupBox_2->setTitle(QString());
        label_7->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\345\214\272", Q_NULLPTR));
        clearsend_button->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\345\217\221\351\200\201", Q_NULLPTR));
        send_button->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", Q_NULLPTR));
        s_hex->setText(QApplication::translate("MainWindow", "HEX", Q_NULLPTR));
        s_timer->setText(QApplication::translate("MainWindow", "\345\221\250\346\234\237\345\217\221\351\200\201", Q_NULLPTR));
        timer->setText(QApplication::translate("MainWindow", "1000", Q_NULLPTR));
        groupBox_3->setTitle(QString());
        label_13->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\345\214\272", Q_NULLPTR));
        groupBox_4->setTitle(QString());
        label_14->setText(QApplication::translate("MainWindow", "\346\216\245\346\224\266\345\214\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTSERIALPORT_H

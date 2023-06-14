/********************************************************************************
** Form generated from reading UI file 'threadsiganl.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THREADSIGANL_H
#define UI_THREADSIGANL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnStartThread;
    QPushButton *btnDiceBegin;
    QPushButton *btnDiceEnd;
    QPushButton *btnStopThread;
    QPushButton *btnClear;
    QHBoxLayout *horizontalLayout_3;
    QPlainTextEdit *plainTextEdit;
    QLabel *LabPic;
    QLabel *LabA;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(800, 600);
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 10, 781, 491));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnStartThread = new QPushButton(groupBox);
        btnStartThread->setObjectName(QStringLiteral("btnStartThread"));

        horizontalLayout->addWidget(btnStartThread);

        btnDiceBegin = new QPushButton(groupBox);
        btnDiceBegin->setObjectName(QStringLiteral("btnDiceBegin"));
        btnDiceBegin->setEnabled(false);

        horizontalLayout->addWidget(btnDiceBegin);

        btnDiceEnd = new QPushButton(groupBox);
        btnDiceEnd->setObjectName(QStringLiteral("btnDiceEnd"));
        btnDiceEnd->setEnabled(false);

        horizontalLayout->addWidget(btnDiceEnd);

        btnStopThread = new QPushButton(groupBox);
        btnStopThread->setObjectName(QStringLiteral("btnStopThread"));
        btnStopThread->setEnabled(false);

        horizontalLayout->addWidget(btnStopThread);

        btnClear = new QPushButton(groupBox);
        btnClear->setObjectName(QStringLiteral("btnClear"));

        horizontalLayout->addWidget(btnClear);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        plainTextEdit = new QPlainTextEdit(groupBox);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        horizontalLayout_3->addWidget(plainTextEdit);

        LabPic = new QLabel(groupBox);
        LabPic->setObjectName(QStringLiteral("LabPic"));
        LabPic->setMinimumSize(QSize(150, 0));
        LabPic->setPixmap(QPixmap(QString::fromUtf8(":/dict/images/d0.jpg")));
        LabPic->setScaledContents(false);

        horizontalLayout_3->addWidget(LabPic);


        verticalLayout->addLayout(horizontalLayout_3);

        LabA = new QLabel(groupBox);
        LabA->setObjectName(QStringLiteral("LabA"));

        verticalLayout->addWidget(LabA);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "qThreadSignal", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Dialog", "\347\272\277\347\250\213", Q_NULLPTR));
        btnStartThread->setText(QApplication::translate("Dialog", "\345\220\257\345\212\250\347\272\277\347\250\213", Q_NULLPTR));
        btnDiceBegin->setText(QApplication::translate("Dialog", "\345\274\200\345\247\213", Q_NULLPTR));
        btnDiceEnd->setText(QApplication::translate("Dialog", "\346\232\202\345\201\234", Q_NULLPTR));
        btnStopThread->setText(QApplication::translate("Dialog", "\347\273\223\346\235\237\347\272\277\347\250\213", Q_NULLPTR));
        btnClear->setText(QApplication::translate("Dialog", "\346\270\205\347\251\272\346\226\207\346\234\254", Q_NULLPTR));
        LabPic->setText(QString());
        LabA->setText(QApplication::translate("Dialog", "Thread\347\212\266\346\200\201\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THREADSIGANL_H

/********************************************************************************
** Form generated from reading UI file 'helpWindowSub.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPWINDOWSUB_H
#define UI_HELPWINDOWSUB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HelpWindowSub
{
public:
    QAction *actClose;

    void setupUi(QWidget *HelpWindowSub)
    {
        if (HelpWindowSub->objectName().isEmpty())
            HelpWindowSub->setObjectName(QStringLiteral("HelpWindowSub"));
        HelpWindowSub->resize(400, 300);
        actClose = new QAction(HelpWindowSub);
        actClose->setObjectName(QStringLiteral("actClose"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/images/132.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actClose->setIcon(icon);

        retranslateUi(HelpWindowSub);

        QMetaObject::connectSlotsByName(HelpWindowSub);
    } // setupUi

    void retranslateUi(QWidget *HelpWindowSub)
    {
        HelpWindowSub->setWindowTitle(QApplication::translate("HelpWindowSub", "Form", Q_NULLPTR));
        actClose->setText(QApplication::translate("HelpWindowSub", "\345\205\263\351\227\255", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actClose->setToolTip(QApplication::translate("HelpWindowSub", "\345\205\263\351\227\255\346\234\254\347\252\227\345\217\243", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class HelpWindowSub: public Ui_HelpWindowSub {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPWINDOWSUB_H

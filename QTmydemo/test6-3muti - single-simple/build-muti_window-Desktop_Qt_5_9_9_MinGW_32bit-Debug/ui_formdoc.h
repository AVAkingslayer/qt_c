/********************************************************************************
** Form generated from reading UI file 'formdoc.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMDOC_H
#define UI_FORMDOC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormDoc
{
public:
    QAction *actClose;

    void setupUi(QWidget *FormDoc)
    {
        if (FormDoc->objectName().isEmpty())
            FormDoc->setObjectName(QStringLiteral("FormDoc"));
        FormDoc->resize(400, 300);
        actClose = new QAction(FormDoc);
        actClose->setObjectName(QStringLiteral("actClose"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/images/132.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actClose->setIcon(icon);

        retranslateUi(FormDoc);

        QMetaObject::connectSlotsByName(FormDoc);
    } // setupUi

    void retranslateUi(QWidget *FormDoc)
    {
        FormDoc->setWindowTitle(QApplication::translate("FormDoc", "Form", Q_NULLPTR));
        actClose->setText(QApplication::translate("FormDoc", "\345\205\263\351\227\255", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actClose->setToolTip(QApplication::translate("FormDoc", "\345\205\263\351\227\255\346\234\254\347\252\227\345\217\243", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class FormDoc: public Ui_FormDoc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMDOC_H

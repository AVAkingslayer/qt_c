/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actnew;
    QAction *actopenfile;
    QAction *actclear;
    QAction *actcut;
    QAction *actcopy;
    QAction *actpaste;
    QAction *actbold;
    QAction *actitalic;
    QAction *actunderline;
    QAction *actclose;
    QWidget *centralwidget;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(774, 461);
        actnew = new QAction(MainWindow);
        actnew->setObjectName(QStringLiteral("actnew"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/images/new2.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actnew->setIcon(icon);
        actopenfile = new QAction(MainWindow);
        actopenfile->setObjectName(QStringLiteral("actopenfile"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/images/open3.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actopenfile->setIcon(icon1);
        actclear = new QAction(MainWindow);
        actclear->setObjectName(QStringLiteral("actclear"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/images/103.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actclear->setIcon(icon2);
        actcut = new QAction(MainWindow);
        actcut->setObjectName(QStringLiteral("actcut"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/images/cut.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actcut->setIcon(icon3);
        actcopy = new QAction(MainWindow);
        actcopy->setObjectName(QStringLiteral("actcopy"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/images/120.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actcopy->setIcon(icon4);
        actpaste = new QAction(MainWindow);
        actpaste->setObjectName(QStringLiteral("actpaste"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/images/paste.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actpaste->setIcon(icon5);
        actbold = new QAction(MainWindow);
        actbold->setObjectName(QStringLiteral("actbold"));
        actbold->setCheckable(true);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/images/BLD.BMP"), QSize(), QIcon::Normal, QIcon::Off);
        actbold->setIcon(icon6);
        actitalic = new QAction(MainWindow);
        actitalic->setObjectName(QStringLiteral("actitalic"));
        actitalic->setCheckable(true);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/images/ITL.BMP"), QSize(), QIcon::Normal, QIcon::Off);
        actitalic->setIcon(icon7);
        actunderline = new QAction(MainWindow);
        actunderline->setObjectName(QStringLiteral("actunderline"));
        actunderline->setCheckable(true);
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/images/images/UNDRLN.BMP"), QSize(), QIcon::Normal, QIcon::Off);
        actunderline->setIcon(icon8);
        actclose = new QAction(MainWindow);
        actclose->setObjectName(QStringLiteral("actclose"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/images/images/exit.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actclose->setIcon(icon9);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(150, 50, 256, 192));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 774, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menu->addSeparator();
        menu->addAction(actopenfile);
        menu->addAction(actnew);
        menu->addAction(actclose);
        menu_2->addAction(actcut);
        menu_2->addAction(actcopy);
        menu_2->addAction(actpaste);
        menu_3->addAction(actbold);
        menu_3->addAction(actitalic);
        menu_3->addAction(actunderline);
        toolBar->addAction(actnew);
        toolBar->addAction(actopenfile);
        toolBar->addAction(actclear);
        toolBar->addAction(actcut);
        toolBar->addAction(actcopy);
        toolBar->addAction(actpaste);
        toolBar->addAction(actitalic);
        toolBar->addAction(actbold);
        toolBar->addAction(actunderline);

        retranslateUi(MainWindow);
        QObject::connect(actclear, SIGNAL(triggered()), textEdit, SLOT(clear()));
        QObject::connect(actcopy, SIGNAL(triggered()), textEdit, SLOT(copy()));
        QObject::connect(actclose, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(actcut, SIGNAL(triggered()), textEdit, SLOT(cut()));
        QObject::connect(actpaste, SIGNAL(triggered()), textEdit, SLOT(paste()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actnew->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actnew->setToolTip(QApplication::translate("MainWindow", "\346\226\260\345\273\272\346\226\207\344\273\266", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actnew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actopenfile->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actopenfile->setToolTip(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actopenfile->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actclear->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actclear->setToolTip(QApplication::translate("MainWindow", "\346\270\205\347\251\272\346\226\207\344\273\266", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actcut->setText(QApplication::translate("MainWindow", "\345\211\252\345\210\207", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actcut->setToolTip(QApplication::translate("MainWindow", "\345\211\252\345\210\207\346\226\207\344\273\266", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actcopy->setText(QApplication::translate("MainWindow", "\345\244\215\345\210\266", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actcopy->setToolTip(QApplication::translate("MainWindow", "\345\244\215\345\210\266\346\226\207\344\273\266", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actcopy->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actpaste->setText(QApplication::translate("MainWindow", "\347\262\230\350\264\264", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actpaste->setToolTip(QApplication::translate("MainWindow", "\347\262\230\350\264\264\346\226\207\344\273\266", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actpaste->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actbold->setText(QApplication::translate("MainWindow", "\347\262\227\344\275\223", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actbold->setToolTip(QApplication::translate("MainWindow", "\347\262\227\344\275\223", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actitalic->setText(QApplication::translate("MainWindow", "\346\226\234\344\275\223", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actitalic->setToolTip(QApplication::translate("MainWindow", "\346\226\234\344\275\223", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actunderline->setText(QApplication::translate("MainWindow", "\344\270\213\345\210\222\347\272\277", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actunderline->setToolTip(QApplication::translate("MainWindow", "\347\262\227\344\275\223", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actclose->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actclose->setToolTip(QApplication::translate("MainWindow", "\345\205\263\351\227\255\346\226\207\344\273\266", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("MainWindow", "\347\274\226\350\276\221", Q_NULLPTR));
        menu_3->setTitle(QApplication::translate("MainWindow", "\346\240\274\345\274\217", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

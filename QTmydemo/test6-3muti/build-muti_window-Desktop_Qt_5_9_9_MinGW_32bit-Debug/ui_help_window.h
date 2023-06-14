/********************************************************************************
** Form generated from reading UI file 'help_window.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELP_WINDOW_H
#define UI_HELP_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_help_window
{
public:
    QAction *actWindowInsite;
    QAction *actWidgetInsite;
    QAction *actQuit;
    QAction *actDoc_Open;
    QAction *actWindow;
    QAction *actWidget;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *help_window)
    {
        if (help_window->objectName().isEmpty())
            help_window->setObjectName(QStringLiteral("help_window"));
        help_window->resize(800, 600);
        help_window->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        actWindowInsite = new QAction(help_window);
        actWindowInsite->setObjectName(QStringLiteral("actWindowInsite"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/images/2.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actWindowInsite->setIcon(icon);
        actWidgetInsite = new QAction(help_window);
        actWidgetInsite->setObjectName(QStringLiteral("actWidgetInsite"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/images/100.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actWidgetInsite->setIcon(icon1);
        actQuit = new QAction(help_window);
        actQuit->setObjectName(QStringLiteral("actQuit"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/images/132.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actQuit->setIcon(icon2);
        actDoc_Open = new QAction(help_window);
        actDoc_Open->setObjectName(QStringLiteral("actDoc_Open"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/images/122.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actDoc_Open->setIcon(icon3);
        actWindow = new QAction(help_window);
        actWindow->setObjectName(QStringLiteral("actWindow"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/images/3.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actWindow->setIcon(icon4);
        actWidget = new QAction(help_window);
        actWidget->setObjectName(QStringLiteral("actWidget"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/images/804.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actWidget->setIcon(icon5);
        centralwidget = new QWidget(help_window);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(220, 90, 127, 80));
        tabWidget->setTabsClosable(true);
        help_window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(help_window);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        help_window->setMenuBar(menubar);
        statusbar = new QStatusBar(help_window);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        help_window->setStatusBar(statusbar);
        toolBar = new QToolBar(help_window);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setContextMenuPolicy(Qt::DefaultContextMenu);
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        help_window->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actWidgetInsite);
        toolBar->addAction(actQuit);

        retranslateUi(help_window);
        QObject::connect(actQuit, SIGNAL(triggered()), help_window, SLOT(close()));

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(help_window);
    } // setupUi

    void retranslateUi(QMainWindow *help_window)
    {
        help_window->setWindowTitle(QApplication::translate("help_window", "MainWindow", Q_NULLPTR));
        actWindowInsite->setText(QApplication::translate("help_window", "\345\265\214\345\205\245\345\274\217MainWindow", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actWindowInsite->setToolTip(QApplication::translate("help_window", "\345\265\214\345\205\245\345\274\217MainWindow", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actWidgetInsite->setText(QApplication::translate("help_window", "helpWidget", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actWidgetInsite->setToolTip(QApplication::translate("help_window", "Widget\345\265\214\345\205\245\345\274\217\347\252\227\344\275\223", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actQuit->setText(QApplication::translate("help_window", "\351\200\200\345\207\272", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actQuit->setToolTip(QApplication::translate("help_window", "\351\200\200\345\207\272\346\234\254\347\263\273\347\273\237", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actDoc_Open->setText(QApplication::translate("help_window", "\346\211\223\345\274\200\346\226\207\346\241\243", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actDoc_Open->setToolTip(QApplication::translate("help_window", "\346\211\223\345\274\200\346\226\207\346\241\243", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actWindow->setText(QApplication::translate("help_window", "\347\213\254\347\253\213MainWindow\347\252\227\345\217\243", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actWindow->setToolTip(QApplication::translate("help_window", "\347\213\254\347\253\213MainWindow\347\252\227\345\217\243", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actWidget->setText(QApplication::translate("help_window", "\347\213\254\347\253\213Widget\347\252\227\345\217\243", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actWidget->setToolTip(QApplication::translate("help_window", "\346\226\260\345\273\272Widget\347\213\254\347\253\213\347\252\227\345\217\243", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolBar->setWindowTitle(QApplication::translate("help_window", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class help_window: public Ui_help_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELP_WINDOW_H

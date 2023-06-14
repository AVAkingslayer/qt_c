#ifndef FORMDOC_H
#define FORMDOC_H

#include <QWidget>
#include <QtCore/QObject>
#include <QTextBrowser>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QDebug>
#include <QKeyEvent>
#include <QTextCursor>
#include "mainwindow.h"
namespace Ui {
class FormDoc;
}

class FormDoc : public QWidget
{
    Q_OBJECT

public:
    explicit FormDoc(QWidget *parent = nullptr);
    ~FormDoc();

private:
    Ui::FormDoc *ui;
    QTextEdit* textEdit;
    QVBoxLayout* layout;
    QTextBrowser* textBrowser;
private slots:
    void loadHtmlFile(const QString& filePath);
   // void keyPressEvent(QKeyEvent *event);

};

#endif // FORMDOC_H

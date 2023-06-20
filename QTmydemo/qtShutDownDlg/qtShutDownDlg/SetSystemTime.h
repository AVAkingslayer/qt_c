#ifndef CSETSYSTEMTIME_H
#define CSETSYSTEMTIME_H

#include <QApplication>
#include <QtCore/QProcess>
#include <QDebug>
#include <QStringList>
class CSetSystemTime
{
public:
    CSetSystemTime();
    bool SetSystemTime(const QString& datetimeStr);
};

#endif // CSETSYSTEMTIME_H

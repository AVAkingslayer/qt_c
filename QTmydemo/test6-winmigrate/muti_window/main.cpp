#include "helpWindowSub.h"
#include <QApplication>
#include <QCoreApplication>
#include <QDebug>
#include <QMessageLogContext>
void customMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    if (type != QtWarningMsg || !msg.contains("QCssParser::parseHexColor: Unknown color name")) {
        // 不是警告信息或者不包含特定的警告消息，直接输出
        qInstallMessageHandler(0);
        qWarning() << msg;
        qInstallMessageHandler(customMessageHandler);
    }
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HelpWindowSub w;
    w.show();
    // 安装自定义消息处理函数
    qInstallMessageHandler(customMessageHandler);
    return a.exec();
}

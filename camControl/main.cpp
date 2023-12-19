#include <QtCore/QCoreApplication>
#include <QThread> 
#include "camera.h"
#include "listenWebsocket.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    camera cacamera;
    //cacamera.sendOn();
    cacamera.sendBottom();
    QThread::msleep(5000);
    cacamera.sendTop();

    ListenWebsocket listenWebSocket;
    listenWebSocket.run();

    return a.exec();
}

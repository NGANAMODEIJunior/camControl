#include <QtCore/QCoreApplication>
#include <QThread> 
#include "camera.h"
#include "listenWebsocket.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //on crée l'objet pour initier la liaison Websocket
    ListenWebsocket listenWebSocket;
    listenWebSocket.run();
    return a.exec();
}

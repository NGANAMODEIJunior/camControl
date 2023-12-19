#include "listenWebSocket.h"

ListenWebsocket::ListenWebsocket(QObject* parent) : QObject(parent), webSocketServer(nullptr) {
}

void ListenWebsocket::onNewConnection() {
    QWebSocket* socket = webSocketServer->nextPendingConnection();

    connect(socket, &QWebSocket::textMessageReceived, this, &ListenWebsocket::processMessage);
    connect(socket, &QWebSocket::disconnected, socket, &QWebSocket::deleteLater);
}

void ListenWebsocket::processMessage(QString message) {
    // Traitez le message re�u
    qDebug() << "Action re�ue : " << message;

    // Ici, vous pouvez ajouter la logique pour r�pondre au message si n�cessaire
}

void ListenWebsocket::run() {
    // Cr�ez le serveur WebSocket
    webSocketServer = new QWebSocketServer(QStringLiteral("WebSocket Server"), QWebSocketServer::NonSecureMode, this);

    // Configurez le slot appel� lorsqu'une nouvelle connexion est �tablie
    connect(webSocketServer, &QWebSocketServer::newConnection, this, &ListenWebsocket::onNewConnection);

    // �coutez sur le port sp�cifi� (remplacez le port par le port r�el que vous utilisez)
    if (webSocketServer->listen(QHostAddress::Any, 9002)) {
        qDebug() << "Serveur WebSocket �coutant sur le port 9002";
        QCoreApplication::instance()->exec();  // D�marrer l'application Qt
    }
    else {
        qCritical() << "Impossible de d�marrer le serveur WebSocket";
    }
}

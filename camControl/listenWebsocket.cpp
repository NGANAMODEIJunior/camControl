#include "listenWebSocket.h"

ListenWebsocket::ListenWebsocket(QObject* parent) : QObject(parent), webSocketServer(nullptr) {
}

void ListenWebsocket::onNewConnection() {
    QWebSocket* socket = webSocketServer->nextPendingConnection();

    connect(socket, &QWebSocket::textMessageReceived, this, &ListenWebsocket::processMessage);
    connect(socket, &QWebSocket::disconnected, socket, &QWebSocket::deleteLater);
}

void ListenWebsocket::processMessage(QString message) {
    // Traitez le message reçu
    qDebug() << "Action reçue : " << message;

    // Ici, vous pouvez ajouter la logique pour répondre au message si nécessaire
}

void ListenWebsocket::run() {
    // Créez le serveur WebSocket
    webSocketServer = new QWebSocketServer(QStringLiteral("WebSocket Server"), QWebSocketServer::NonSecureMode, this);

    // Configurez le slot appelé lorsqu'une nouvelle connexion est établie
    connect(webSocketServer, &QWebSocketServer::newConnection, this, &ListenWebsocket::onNewConnection);

    // Écoutez sur le port spécifié (remplacez le port par le port réel que vous utilisez)
    if (webSocketServer->listen(QHostAddress::Any, 9002)) {
        qDebug() << "Serveur WebSocket écoutant sur le port 9002";
        QCoreApplication::instance()->exec();  // Démarrer l'application Qt
    }
    else {
        qCritical() << "Impossible de démarrer le serveur WebSocket";
    }
}

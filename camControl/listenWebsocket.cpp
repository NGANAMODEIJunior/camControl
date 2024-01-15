#include "listenWebSocket.h"
#include "camera.h"
#include <QThread>

ListenWebsocket::ListenWebsocket(QObject* parent) : QObject(parent), webSocketServer(nullptr) {
}

void ListenWebsocket::onNewConnection() {
    QWebSocket* socket = webSocketServer->nextPendingConnection();

    connect(socket, &QWebSocket::textMessageReceived, this, &ListenWebsocket::processMessage);
    connect(socket, &QWebSocket::disconnected, socket, &QWebSocket::deleteLater);
}

void ListenWebsocket::processMessage(QString message) {
    // Traitez le message reçu pour appeler la méthode nécessaire
    qDebug() << "Action reçue : " << message;
    if (message == "allumer") {
        Cam1.sendOn();

    }
    else if (message == "haut") {
        Cam1.sendTop();

    }
    else if (message == "droite") {
        Cam1.sendRight();

    }
    else if (message == "gauche") {
        Cam1.sendLeft();

    }
    else if (message == "bas") {
        Cam1.sendBottom();

    }
    else if (message == "eteindre") {
        Cam1.sendOff();

    }
    else if (message == "reset") {
        Cam1.reset();

    }
    else if (message == "oui") {
        Cam1.reset();
        Cam1.sendOui();
        QThread::sleep(1);
        Cam1.reset();

    }
    else if (message == "non") {
        Cam1.reset();
        Cam1.sendNon();
        QThread::sleep(1);
        Cam1.reset();

    }

    

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

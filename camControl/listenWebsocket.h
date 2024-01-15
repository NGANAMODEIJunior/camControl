#pragma once

#include <QObject>
#include <QCoreApplication>
#include <QWebSocketServer>
#include <QWebSocket>
#include "camera.h" 


class ListenWebsocket : public QObject {
    Q_OBJECT
public:
    explicit ListenWebsocket(QObject* parent = nullptr);

    // Méthode pour initialiser et exécuter le serveur WebSocket
    void run();

private slots:
    // Méthode appelée lorsqu'une connexion WebSocket est établie
    void onNewConnection();

    // Méthode appelée lorsqu'un message est reçu
    void processMessage(QString message);

private:
    // Instance du serveur WebSocket
    QWebSocketServer* webSocketServer;
    // Instance de la caméra
    camera Cam1;
};

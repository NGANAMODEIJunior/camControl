#pragma once

#include <QObject>
#include <QCoreApplication>
#include <QWebSocketServer>
#include <QWebSocket>

class ListenWebsocket : public QObject {
    Q_OBJECT
public:
    explicit ListenWebsocket(QObject* parent = nullptr);

    // M�thode pour initialiser et ex�cuter le serveur WebSocket
    void run();

private slots:
    // M�thode appel�e lorsqu'une connexion WebSocket est �tablie
    void onNewConnection();

    // M�thode appel�e lorsqu'un message est re�u
    void processMessage(QString message);

private:
    // Instance du serveur WebSocket
    QWebSocketServer* webSocketServer;
};

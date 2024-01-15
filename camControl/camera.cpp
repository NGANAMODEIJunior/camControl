#include "camera.h"
#include "connectTCP.h"
#include <QDebug>
#include <QByteArray>
#include <QThread>

//constructeur
camera::camera() {
}

//destructeur
camera::~camera() {
}

//méthode pour allumer la cam
void camera::sendOn() {
    std::string hexData = "81 01 04 00 02 FF";
    // Convertir la chaîne hexadécimale en QByteArray
    QByteArray byteArray = QByteArray::fromHex(hexData.c_str());

    // Appeler la méthode de la classe ConnectTCP pour envoyer les données
    ConnectTCP connection;
    if (connection.connectToServer("192.168.64.218", 950)) {
        connection.sendHexData(byteArray.constData(), byteArray.size());
    }
}

//méthode pour éteindre la cam
void camera::sendOff() {
    std::string hexData = "81 01 04 00 03 FF";
    // Convertir la chaîne hexadécimale en QByteArray
    QByteArray byteArray = QByteArray::fromHex(hexData.c_str());

    // Appeler la méthode de la classe ConnectTCP pour envoyer les données
    ConnectTCP connection;
    if (connection.connectToServer("192.168.64.218", 950)) {
        connection.sendHexData(byteArray.constData(), byteArray.size());
    }
}

//méthode pour déplacer la cam vers la gauche
void camera::sendLeft() {
    std::string hexData = "81 01 06 01 16 10 01 03 FF";
    // Convertir la chaîne hexadécimale en QByteArray
    QByteArray byteArray = QByteArray::fromHex(hexData.c_str());

    // Appeler la méthode de la classe ConnectTCP pour envoyer les données
    ConnectTCP connection;
    if (connection.connectToServer("192.168.64.218", 950)) {
        connection.sendHexData(byteArray.constData(), byteArray.size());
    }
}

//méthode pour déplacer la cam vers la droite
void camera::sendRight() {
    std::string hexData = "81 01 06 01 16 10 02 03 FF";
    // Convertir la chaîne hexadécimale en QByteArray
    QByteArray byteArray = QByteArray::fromHex(hexData.c_str());

    // Appeler la méthode de la classe ConnectTCP pour envoyer les données
    ConnectTCP connection;
    if (connection.connectToServer("192.168.64.218", 950)) {
        connection.sendHexData(byteArray.constData(), byteArray.size());
    }
    // Vous pouvez ajouter la logique de gestion des erreurs ici
}

//méthode pour déplacer la cam vers le haut
void camera::sendTop() {
    std::string hexData = "81 01 06 01 01 05 03 01 FF";
    // Convertir la chaîne hexadécimale en QByteArray
    QByteArray byteArray = QByteArray::fromHex(hexData.c_str());

    // Appeler la méthode de la classe ConnectTCP pour envoyer les données
    ConnectTCP connection;
    if (connection.connectToServer("192.168.64.218", 950)) {
        connection.sendHexData(byteArray.constData(), byteArray.size());
    }
    // Vous pouvez ajouter la logique de gestion des erreurs ici
}

//méthode pour déplacer la cam vers la bas
void camera::sendBottom() {
    std::string hexData = "81 01 06 01 05 05 03 02 FF";
    // Convertir la chaîne hexadécimale en QByteArray
    QByteArray byteArray = QByteArray::fromHex(hexData.c_str());

    // Appeler la méthode de la classe ConnectTCP pour envoyer les données
    ConnectTCP connection;
    if (connection.connectToServer("192.168.64.218", 950)) {
        connection.sendHexData(byteArray.constData(), byteArray.size());
    }
    // Vous pouvez ajouter la logique de gestion des erreurs ici
}

//méthode pour remettre la position par défaut
void camera::reset()
{
    std::string hexData = "81 01 06 04 FF";
    // Convertir la chaîne hexadécimale en QByteArray
    QByteArray byteArray = QByteArray::fromHex(hexData.c_str());

    // Appeler la méthode de la classe ConnectTCP pour envoyer les données
    ConnectTCP connection;
    if (connection.connectToServer("192.168.64.218", 950)) {
        connection.sendHexData(byteArray.constData(), byteArray.size());
    }
    // Vous pouvez ajouter la logique de gestion des erreurs ici
}

//méthode pour faire un mouvement oui (comme un hauchement de tête)
void camera::sendOui()
{
    for (int i = 0; i < 3; i++) {
        this->sendTop();
        QThread::sleep(1);
        this->sendBottom();
        QThread::sleep(1);
    }
}

//méthode pour faire un mouvement non (comme un hauchement de tête)
void camera::sendNon()
{
    for (int i = 0; i < 3; i++) {
        this->sendLeft();
        QThread::sleep(1);
        this->sendRight();
        QThread::sleep(1);
    }
}

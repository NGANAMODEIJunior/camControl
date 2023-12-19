#include "camera.h"
#include "connectTCP.h"
#include <QDebug>
#include <QByteArray>

camera::camera() {
    //appeler méthodes ici
    //sendBottom();
    // Initialiser d'autres membres si nécessaire
}

camera::~camera() {
    // Implémenter le destructeur si nécessaire
}

void camera::sendOn() {
    std::string hexData = "81 01 04 00 02 FF";
    // Convertir la chaîne hexadécimale en QByteArray
    QByteArray byteArray = QByteArray::fromHex(hexData.c_str());

    // Appeler la méthode de la classe ConnectTCP pour envoyer les données
    ConnectTCP connection;
    if (connection.connectToServer("192.168.64.218", 950)) {
        connection.sendHexData(byteArray.constData(), byteArray.size());
    }
    // Vous pouvez ajouter la logique de gestion des erreurs ici
}


void camera::sendOff() {
    std::string hexData = "81 01 04 00 03 FF";
    // Convertir la chaîne hexadécimale en QByteArray
    QByteArray byteArray = QByteArray::fromHex(hexData.c_str());

    // Appeler la méthode de la classe ConnectTCP pour envoyer les données
    ConnectTCP connection;
    if (connection.connectToServer("192.168.64.218", 950)) {
        connection.sendHexData(byteArray.constData(), byteArray.size());
    }
    // Vous pouvez ajouter la logique de gestion des erreurs ici
}

void camera::sendLeft() {
    std::string hexData = "81 01 06 01 16 10 01 03 FF";
    // Convertir la chaîne hexadécimale en QByteArray
    QByteArray byteArray = QByteArray::fromHex(hexData.c_str());

    // Appeler la méthode de la classe ConnectTCP pour envoyer les données
    ConnectTCP connection;
    if (connection.connectToServer("192.168.64.218", 950)) {
        connection.sendHexData(byteArray.constData(), byteArray.size());
    }
    // Vous pouvez ajouter la logique de gestion des erreurs ici
}

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
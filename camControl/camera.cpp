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

//m�thode pour allumer la cam
void camera::sendOn() {
    std::string hexData = "81 01 04 00 02 FF";
    // Convertir la cha�ne hexad�cimale en QByteArray
    QByteArray byteArray = QByteArray::fromHex(hexData.c_str());

    // Appeler la m�thode de la classe ConnectTCP pour envoyer les donn�es
    ConnectTCP connection;
    if (connection.connectToServer("192.168.64.218", 950)) {
        connection.sendHexData(byteArray.constData(), byteArray.size());
    }
}

//m�thode pour �teindre la cam
void camera::sendOff() {
    std::string hexData = "81 01 04 00 03 FF";
    // Convertir la cha�ne hexad�cimale en QByteArray
    QByteArray byteArray = QByteArray::fromHex(hexData.c_str());

    // Appeler la m�thode de la classe ConnectTCP pour envoyer les donn�es
    ConnectTCP connection;
    if (connection.connectToServer("192.168.64.218", 950)) {
        connection.sendHexData(byteArray.constData(), byteArray.size());
    }
}

//m�thode pour d�placer la cam vers la gauche
void camera::sendLeft() {
    std::string hexData = "81 01 06 01 16 10 01 03 FF";
    // Convertir la cha�ne hexad�cimale en QByteArray
    QByteArray byteArray = QByteArray::fromHex(hexData.c_str());

    // Appeler la m�thode de la classe ConnectTCP pour envoyer les donn�es
    ConnectTCP connection;
    if (connection.connectToServer("192.168.64.218", 950)) {
        connection.sendHexData(byteArray.constData(), byteArray.size());
    }
}

//m�thode pour d�placer la cam vers la droite
void camera::sendRight() {
    std::string hexData = "81 01 06 01 16 10 02 03 FF";
    // Convertir la cha�ne hexad�cimale en QByteArray
    QByteArray byteArray = QByteArray::fromHex(hexData.c_str());

    // Appeler la m�thode de la classe ConnectTCP pour envoyer les donn�es
    ConnectTCP connection;
    if (connection.connectToServer("192.168.64.218", 950)) {
        connection.sendHexData(byteArray.constData(), byteArray.size());
    }
    // Vous pouvez ajouter la logique de gestion des erreurs ici
}

//m�thode pour d�placer la cam vers le haut
void camera::sendTop() {
    std::string hexData = "81 01 06 01 01 05 03 01 FF";
    // Convertir la cha�ne hexad�cimale en QByteArray
    QByteArray byteArray = QByteArray::fromHex(hexData.c_str());

    // Appeler la m�thode de la classe ConnectTCP pour envoyer les donn�es
    ConnectTCP connection;
    if (connection.connectToServer("192.168.64.218", 950)) {
        connection.sendHexData(byteArray.constData(), byteArray.size());
    }
    // Vous pouvez ajouter la logique de gestion des erreurs ici
}

//m�thode pour d�placer la cam vers la bas
void camera::sendBottom() {
    std::string hexData = "81 01 06 01 05 05 03 02 FF";
    // Convertir la cha�ne hexad�cimale en QByteArray
    QByteArray byteArray = QByteArray::fromHex(hexData.c_str());

    // Appeler la m�thode de la classe ConnectTCP pour envoyer les donn�es
    ConnectTCP connection;
    if (connection.connectToServer("192.168.64.218", 950)) {
        connection.sendHexData(byteArray.constData(), byteArray.size());
    }
    // Vous pouvez ajouter la logique de gestion des erreurs ici
}

//m�thode pour remettre la position par d�faut
void camera::reset()
{
    std::string hexData = "81 01 06 04 FF";
    // Convertir la cha�ne hexad�cimale en QByteArray
    QByteArray byteArray = QByteArray::fromHex(hexData.c_str());

    // Appeler la m�thode de la classe ConnectTCP pour envoyer les donn�es
    ConnectTCP connection;
    if (connection.connectToServer("192.168.64.218", 950)) {
        connection.sendHexData(byteArray.constData(), byteArray.size());
    }
    // Vous pouvez ajouter la logique de gestion des erreurs ici
}

//m�thode pour faire un mouvement oui (comme un hauchement de t�te)
void camera::sendOui()
{
    for (int i = 0; i < 3; i++) {
        this->sendTop();
        QThread::sleep(1);
        this->sendBottom();
        QThread::sleep(1);
    }
}

//m�thode pour faire un mouvement non (comme un hauchement de t�te)
void camera::sendNon()
{
    for (int i = 0; i < 3; i++) {
        this->sendLeft();
        QThread::sleep(1);
        this->sendRight();
        QThread::sleep(1);
    }
}

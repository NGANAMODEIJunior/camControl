// ConnectTCP.cpp

#include "ConnectTCP.h"
#include <iostream>
#include <cstring>

#ifdef _WIN32
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/types.h>  // Ajoutez cette ligne
#endif

ConnectTCP::ConnectTCP() : clientSocket(-1) {
    // Initialiser d'autres membres si nécessaire
}

ConnectTCP::~ConnectTCP() {
    if (clientSocket != -1) {
#ifdef _WIN32
        closesocket(clientSocket);
        WSACleanup();
#else
        close(clientSocket);
#endif
    }
}

bool ConnectTCP::connectToServer(const char* ipAddress, int port) {
#ifdef _WIN32
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Erreur lors de l'initialisation de Winsock." << std::endl;
        return false;
    }
#endif

    // Création de la socket
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        std::cerr << "Erreur lors de la création de la socket." << std::endl;
#ifdef _WIN32
        WSACleanup();
#endif
        return false;
    }

    // Configuration de l'adresse du serveur
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);

#ifdef _WIN32
    serverAddress.sin_addr.s_addr = inet_addr(ipAddress);
#else
    if (inet_pton(AF_INET, ipAddress, &serverAddress.sin_addr) <= 0) {
        std::cerr << "Erreur lors de la conversion de l'adresse IP." << std::endl;
#ifdef _WIN32
        closesocket(clientSocket);
        WSACleanup();
#else
        close(clientSocket);
#endif
        return false;
    }
#endif

    // Connexion au serveur
    if (connect(clientSocket, reinterpret_cast<struct sockaddr*>(&serverAddress), sizeof(serverAddress)) == -1) {
        std::cerr << "Erreur lors de la connexion au serveur." << std::endl;
#ifdef _WIN32
        closesocket(clientSocket);
        WSACleanup();
#else
        close(clientSocket);  // Fermer la socket en cas d'échec de la connexion
#endif
        return false;
    }

    return true;
}

bool ConnectTCP::sendHexData(const char* data, size_t size) {
    if (clientSocket == -1) {
        std::cerr << "La socket n'est pas correctement initialisée." << std::endl;
        return false;
    }

    // Envoi des données
    int bytesSent = send(clientSocket, data, size, 0);
    if (bytesSent == -1) {
        std::cerr << "Erreur lors de l'envoi des données." << std::endl;
        return false;
    }

    return true;
}



#pragma once
// ConnectTCP.h

#ifndef CONNECTTCP_H
#define CONNECTTCP_H

#include <string>

class ConnectTCP {
public:
    ConnectTCP();
    ~ConnectTCP();

    bool connectToServer(const char* ipAddress, int port);
    bool sendHexData(const char* data, size_t size);

private:
    int clientSocket;

};

#endif  // CONNECTTCP_H

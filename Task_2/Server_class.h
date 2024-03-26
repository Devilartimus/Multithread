#ifndef SERVER_CLASS_H
#define SERVER_CLASS_H

#include <iostream>
#include <string>

class Server
{

private:
    std::string m_serverAddress;
    int m_port;
    void analyze(const char* data);

public:
    Server(const std::string& serverAddress, int port) : m_serverAddress(serverAddress), m_port(port) {}
    bool connectAndReceive();

};

#endif

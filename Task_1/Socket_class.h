#ifndef CLIENT_SOCKET_CLASS_H
#define CLIENT_SOCKET_CLASS_H

#include <iostream>
#include <cstring>

class ClientSocket
{
private:
    int m_socket_fd = -1;

public:
    ClientSocket() {}
    ~ClientSocket();
    bool create();
    bool connect(const char* address, unsigned short port);
    bool send(const int& data);
    bool close();
};

#endif


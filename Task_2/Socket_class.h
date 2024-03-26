#ifndef SERVERSOCKET_CLASS_H
#define SERVERSOCKET_CLASS_H

#include <iostream>
#include <cstring>

class ServerSocket
{
public:
    ServerSocket(unsigned short port) : m_port(port), m_socket_fd(-1), m_client_socket_fd(-1) {}
    ~ServerSocket();
    bool setup();
    ssize_t receive(char* buffer, size_t size);
    bool close();


private:
    unsigned short m_port;
    int m_socket_fd;
    int m_client_socket_fd;

    bool create();
    bool bind();
    bool listen(int backlog);
    bool accept();
};

#endif



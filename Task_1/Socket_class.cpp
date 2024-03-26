#ifndef SOCKET_CLASS_CPP
#define SOCKET_CLASS_CPP

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#include "Socket_class.h"

ClientSocket::~ClientSocket()
{
    close();
}

bool ClientSocket::create()
{
    m_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    return m_socket_fd != -1;
}

bool ClientSocket::connect(const char* address, unsigned short port)
{
    struct sockaddr_in serverAddr;
    std::memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);

    struct hostent* host = gethostbyname(address);
    if (host == nullptr)
        return false;

    std::memcpy(&serverAddr.sin_addr, host->h_addr, host->h_length);

    return ::connect(m_socket_fd, reinterpret_cast<struct sockaddr*>(&serverAddr), sizeof(serverAddr)) != -1;
}

bool ClientSocket::send(const int& data)
{
    return ::send(m_socket_fd, std::to_string(data).c_str(), sizeof(std::to_string(data)), 0) != -1;
}

bool ClientSocket::close()
{
    if (m_socket_fd != -1)
    {
        ::close(m_socket_fd);
        m_socket_fd = -1;
        return true;
    }
    return false;
}

#endif

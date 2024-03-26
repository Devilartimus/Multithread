#ifndef SOCKET_CLASS_CPP
#define SOCKET_CLASS_CPP

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "Socket_class.h"

ServerSocket::~ServerSocket()
{
    close();
}

bool ServerSocket::setup()
{
    if (!create())
    {
        std::cerr << "Error: Unable to create socket\n";
        return false;
    }

    if (!bind())
    {
        std::cerr << "Error: Unable to bind socket\n";
        return false;
    }

    if (!listen(5))
    {
        std::cerr << "Error: Unable to listen on socket\n";
        return false;
    }

    if (!accept())
    {
        std::cerr << "Error: Unable to accept connection\n";
        return false;
    }

    return true;
}

ssize_t ServerSocket::receive(char* buffer, size_t size)
{
    return ::recv(m_client_socket_fd, buffer, size, 0);
}

bool ServerSocket::close()
{
    if (m_socket_fd != -1)
    {
        ::close(m_socket_fd);
        m_socket_fd = -1;
        return true;
    }
    return false;
}

bool ServerSocket::create()
{
    m_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    return m_socket_fd != -1;
}

bool ServerSocket::bind()
{
    struct sockaddr_in serverAddr;
    std::memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(m_port);
    return ::bind(m_socket_fd, reinterpret_cast<struct sockaddr*>(&serverAddr), sizeof(serverAddr)) != -1;
}

bool ServerSocket::listen(int backlog)
{
    return ::listen(m_socket_fd, backlog) != -1;
}

bool ServerSocket::accept()
{
    struct sockaddr_in clientAddr;
    socklen_t clientAddrSize = sizeof(clientAddr);
    m_client_socket_fd = ::accept(m_socket_fd, reinterpret_cast<struct sockaddr*>(&clientAddr), &clientAddrSize);
    return m_client_socket_fd != -1;
}


#endif

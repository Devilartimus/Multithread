#ifndef SERVER_CLASS_CPP
#define SERVER_CLASS_CPP

#include <unistd.h>

#include "Server_class.h"
#include "Socket_class.h"

void Server::analyze(const char* data)
{
    if (strlen(data) > 2 && (strlen(data) % 32) == 0)
    {
        std::cout << "Data received: " << data << std::endl;
    } else {
        std::cout << "Error: Invalid number of characters or not a multiple of 32." << std::endl;
    }
}

bool Server::connectAndReceive()
{
    ServerSocket serverSocket(m_port);
    if (!serverSocket.setup())
    {
        std::cerr << "Error: Failed to setup server socket\n";
        return false;
    }

    char buffer[256];
    ssize_t bytesRead = serverSocket.receive(buffer, sizeof(buffer));
    if (bytesRead < 0)
    {
        std::cerr << "Error: Unable to receive data\n";
        return false;
    } else if (bytesRead == 0)
    {
        std::cerr << "Connection closed by server\n";
        return false;
    } else
    {
        buffer[bytesRead] = '\0';
        analyze(buffer);
        return true;
    }
}

#endif

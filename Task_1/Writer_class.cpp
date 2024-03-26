#ifndef WRITER_CLASS_CPP
#define WRITER_CLASS_CPP

#include <thread>
#include <iostream>
#include <cctype>

#include "Writer_class.h"

struct Addr
{
    const char* addr = "127.0.0.1";
    int port = 12345;
};

void Writer::operator()()
{
    while (true)
    {
        auto data = bufferQueue.pop();

        std::cout << "\n\nReceived string: " << data << std::endl;

        int sum = 0;
        for (char a : data)
        {
            if (std::isdigit(a))
                sum += a - '0';
        }

        std::cout << "Sum of digits: " << sum << std::endl;

        while (true)
        {
            ClientSocket clientSocket;
            if (!clientSocket.create())
            {
                std::cerr << "Error: Unable to create socket\n";
                break;
            }

            Addr ServerAddr;
            if (!clientSocket.connect(ServerAddr.addr, ServerAddr.port))
            {
                std::cerr << "Error: Unable to connect to server\n";
                clientSocket.close();
                continue;
            }

            if (!clientSocket.send(sum))
            {
                std::cerr << "Error: Unable to send data\n";
            }

            clientSocket.close();
            break;
        }
    }
}

#endif

//
// Created by Konstantinos on 10/28/2022.
//

#include "SimpleSocket.hpp"

// Default constructor

MARIS::SimpleSocket::SimpleSocket(int domain, int service, int protocol, int port, u_long interface_)
{
    // Define address structure
    address.sin_family = domain;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(interface_);

    // Establish socket
    sock = socket(domain, service, protocol);

    test_socket(sock);
}

// Test connection virtual function

void MARIS::SimpleSocket::test_socket(int socket)
{
    // Confirm that the socket or connection has been properly established
    if (socket < 0)
    {
        perror("Failed to connect");
        exit(EXIT_FAILURE);
    }
}

// Getter function

struct sockaddr_in MARIS::SimpleSocket::get_address()
{
    return address;
}

int MARIS::SimpleSocket::get_socket()
{
    return sock;
}
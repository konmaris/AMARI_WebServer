#ifndef WEBSERVER_SIMPLESOCKET_HPP
#define WEBSERVER_SIMPLESOCKET_HPP

#include <stdio.h>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>

namespace MARIS
{
    class SimpleSocket
    {
    private:
        struct sockaddr_in address;
        int sock;

    public:
        // Constructor
        SimpleSocket(int domain, int service, int protocol, int port, u_long interface_);

        // Virtual function to connect to network
        virtual int connect_to_network(int socket, struct sockaddr_in address) = 0;

        // Function to test sockets and connections
        void test_socket(int socket);

        // Getter functions
        struct sockaddr_in get_address();
        int get_socket();
    };
}

#endif // WEBSERVER_SIMPLESOCKET_HPP

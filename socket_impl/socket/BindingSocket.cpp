//
// Created by Konstantinos on 10/28/2022.
//

#include "BindingSocket.hpp"

// Constructor
MARIS::BindingSocket::BindingSocket(int domain, int service, int protocol, int port, u_long interface_) : SimpleSocket(domain, service, protocol, port, interface_)
{
    // Establish network connection
    int binded = connect_to_network(get_socket(), get_address());
    test_socket(binded);
}

// Implementation of connect_to_network virtual function
int MARIS::BindingSocket::connect_to_network(int sock, struct sockaddr_in address)
{

    return bind(sock, (struct sockaddr *)&address, sizeof(address));
}

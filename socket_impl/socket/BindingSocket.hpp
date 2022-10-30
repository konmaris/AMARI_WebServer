//
// Created by Konstantinos on 10/28/2022.
//

#ifndef WEBSERVER_BINDINGSOCKET_HPP
#define WEBSERVER_BINDINGSOCKET_HPP

#include <stdio.h>
#include "SimpleSocket.hpp"

namespace MARIS {
    class BindingSocket: public SimpleSocket
    {
    public:
        // Constructor
        BindingSocket(int domain, int service, int protocol, int port, u_long interface_);

        // Virtual function from parent
        int connect_to_network(int sock, struct sockaddr_in address);
    };
}

#endif //WEBSERVER_BINDINGSOCKET_HPP

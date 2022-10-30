//
// Created by Konstantinos on 10/28/2022.
//

#ifndef WEBSERVER_LISTENINGSOCKET_HPP
#define WEBSERVER_LISTENINGSOCKET_HPP

#include <stdio.h>
#include "BindingSocket.hpp"

namespace MARIS
{
    class ListeningSocket : public BindingSocket
    {
    public:
        ListeningSocket(int domain, int service, int protocol, int port, u_long interface_, int backlog_);
        void start_listening();
        void set_listening(int _listening);
        void set_backlog(int _backlog);

    private:
        int backlog;
        int listening;
    };

}

#endif // WEBSERVER_LISTENINGSOCKET_HPP

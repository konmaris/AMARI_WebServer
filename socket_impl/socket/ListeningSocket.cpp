//
// Created by Konstantinos on 10/28/2022.
//

#include "ListeningSocket.hpp"

MARIS::ListeningSocket::ListeningSocket(int domain, int service, int protocol, int port, u_long interface_,
                                        int backlog_) : BindingSocket(domain, service, protocol, port, interface_)
{
    set_backlog(backlog_);
    start_listening();
    test_socket(listening);
}

void MARIS::ListeningSocket::set_listening(int _listening)
{
    listening = _listening;
}

void MARIS::ListeningSocket::set_backlog(int _backlog)
{
    backlog = _backlog;
}

void MARIS::ListeningSocket::start_listening()
{
    set_listening(listen(get_socket(), backlog));
}

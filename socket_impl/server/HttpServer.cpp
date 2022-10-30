#include "HttpServer.hpp"

MARIS::HttpServer::HttpServer(int domain, int service, int protocol, int port, u_long interface_, int backlog_)
{
    socket = new ListeningSocket(domain, service, protocol, port, interface_, backlog_);
}

int MARIS::HttpServer::get_new_socket()
{
    return new_socket;
}

void MARIS::HttpServer::set_new_socket(int new_socket_)
{
    new_socket = new_socket_;
}

char *MARIS::HttpServer::get_request_buffer()
{
    return request_buffer;
}

MARIS::ListeningSocket *MARIS::HttpServer::get_socket()
{
    return socket;
}

void MARIS::HttpServer::accepter()
{
    struct sockaddr_in address = get_socket()->get_address();
    int addrlen = sizeof(address);
    new_socket = accept(get_socket()->get_socket(), (struct sockaddr *)&address, (socklen_t *)&addrlen);
    read(new_socket, request_buffer, 30000);
}

#ifndef WEBSERVER_HTTPSERVER_HPP
#define WEBSERVER_HTTPSERVER_HPP

#include <stdio.h>
#include <sstream>
// #include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>

#include "../socket/ListeningSocket.hpp"

namespace MARIS
{
    class HttpServer
    {
    private:
        ListeningSocket *socket;
        char request_buffer[30000];
        int new_socket;
        virtual void launch() = 0;
        virtual void handler() = 0;
        virtual void responder(std::string req_type, std::string content_type, const char *headers, const char *content) = 0;

    public:
        int get_new_socket();
        void set_new_socket(int new_socket_);
        char *get_request_buffer();
        HttpServer(int domain, int service, int protocol, int port, u_long interface_, int backlog_);
        ListeningSocket *get_socket();
        void accepter();
    };
}

#endif
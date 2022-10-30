#ifndef WEBSERVER_MYSERVER_HPP
#define WEBSERVER_MYSERVER_HPP

#include <iostream>
#include "../../socket_impl/server/HttpServer.hpp"

namespace MARIS
{
    class MyServer : public HttpServer
    {
    public:
        void handler();
        void responder(std::string req_type, std::string content_type, const char *headers, const char *content);
        void launch();
        MyServer(int port);
    };
}

#endif
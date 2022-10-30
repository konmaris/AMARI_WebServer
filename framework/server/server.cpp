#include "server.hpp"

using namespace std;

MARIS::MyServer::MyServer(int port) : HttpServer(AF_INET, SOCK_STREAM, 0, port, INADDR_ANY, 10)
{
    std::cout << "Server listening on port: " << port << std::endl;
    std::cout << "http://localhost:" << port << " (cmd+click to open link)" << std::endl
              << std::endl;
}

void MARIS::MyServer::launch()
{
    while (true)
    {
        accepter();
        handler();
    }
}

void MARIS::MyServer::handler()
{
    string get_request = get_request_buffer();

    cout << get_request << endl;

    string first_line;

    for (int i = 0; i < get_request.length(); i++)
    {
        if (get_request[i] == '\n')
        {
            break;
        }
        first_line += get_request[i];
    }

    string first_line_no_http_v;

    for (int i = first_line.find('/'); i < first_line.length(); i++)
    {
        if (first_line[i] == ' ')
        {
            break;
        }
        first_line_no_http_v += first_line[i];
    }

    string file_type;

    for (int i = first_line_no_http_v.find_last_of('.') + 1; i < first_line_no_http_v.length(); i++)
    {
        if (first_line_no_http_v[i] != '/')
        {
            file_type += first_line_no_http_v[i];
        }
        else
        {
            file_type = "html";
        }
    }

    if (file_type == "html")
    {
        const char *headers = "HTTP/1.1 200 OK\nAccess-Control-Allow-Origin: *\nContent-Type: text/html\nConnection: close\n\n";

        fstream my_file;
        stringstream html;

        my_file.open("/Users/konmaris/Desktop/WebServer/static/index.html", std::ios::in);

        if (!my_file)
        {
            std::cout << "No such file";
        }
        else
        {
            for (std::string line; getline(my_file, line);)
            {
                html << line << std::endl;
            }
        }

        const std::string tmp = html.str();
        const char *html_ = tmp.c_str();

        responder("GET", "text/html", headers, html_);
    }
    else if (file_type == "css")
    {
        const char *headers = "HTTP/1.1 200 OK\nAccess-Control-Allow-Origin: *\nContent-Type: text/css\nConnection: close\n\n";

        fstream my_file;
        stringstream css;

        my_file.open("/Users/konmaris/Desktop/WebServer/static/style.css", std::ios::in);

        if (!my_file)
        {
            std::cout << "No such file";
        }
        else
        {
            for (std::string line; getline(my_file, line);)
            {
                css << line << std::endl;
            }
        }

        const std::string tmp = css.str();
        const char *css_ = tmp.c_str();

        responder("GET", "text/css", headers, css_);
    }
    else if (file_type == "js")
    {
        const char *headers = "HTTP/1.1 200 OK\nAccess-Control-Allow-Origin: *\nContent-Type: text/javascript\nConnection: close\n\n";

        fstream my_file;
        stringstream js;

        my_file.open("/Users/konmaris/Desktop/WebServer/static/index.js", std::ios::in);

        if (!my_file)
        {
            std::cout << "No such file";
        }
        else
        {
            for (std::string line; getline(my_file, line);)
            {
                js << line << std::endl;
            }
        }

        const std::string tmp = js.str();
        const char *js_ = tmp.c_str();

        responder("GET", "text/javascript", headers, js_);
    }
    else
    {
        const char *headers = "HTTP/1.1 200 OK\nAccess-Control-Allow-Origin: *\nContent-Type: text/plain\nConnection: close\n\n";
        responder("GET", "text/plain", headers, "Hello world!");
    }
}

void MARIS::MyServer::responder(string req_type, string content_type, const char *headers, const char *content)
{
    write(get_new_socket(), headers, strlen(headers));
    write(get_new_socket(), content, strlen(content));

    // cout << req_type << " " << content_type << endl;

    close(get_new_socket());
}

#include "framework/server/server.hpp"

int main()
{
    MARIS::MyServer s1(8080);

    s1.launch();

    return 0;
}
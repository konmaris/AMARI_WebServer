# AMARI Web Server

## Open source project based on C++

### Compile instructions

Execute the following command (needs g++ or gcc compiler):

```
g++ main.cpp framework/server/server.cpp socket_impl/server/HttpServer.cpp socket_impl/socket/SimpleSocket.cpp socket_impl/socket/BindingSocket.cpp socket_impl/socket/ListeningSocket.cpp -o server.out
```

Then execute the compiled object file (here named server.out) by entering into the terminal:

```
./server.out
```

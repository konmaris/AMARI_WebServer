# AMARI Web Server

## Open source project based on C++

### Compile instructions

Execute the following command (needs g++ or gcc compiler):

```
g++ Servers/main.cpp Servers/TestServer.cpp Servers/SimpleServer.cpp Sockets/SimpleSocket.cpp Sockets/BindingSocket.cpp Sockets/ListeningSocket.cpp -o server.out
```

Then execute the compiled object file (here named server.out) by entering into the terminal:

```
./server.out
```

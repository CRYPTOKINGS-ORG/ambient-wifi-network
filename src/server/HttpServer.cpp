#include "HttpServer.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

HttpServer::HttpServer(int port) : port(port) {}

void HttpServer::start() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in address{};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    bind(server_fd, (struct sockaddr*)&address, sizeof(address));
    listen(server_fd, 10);

    std::cout << "HTTP Server running on port " << port << std::endl;

    while (true) {
        int addrlen = sizeof(address);
        int new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);

        std::string response =
            "HTTP/1.1 200 OK\nContent-Type: text/plain\n\nAmbient WiFi Running";

        send(new_socket, response.c_str(), response.size(), 0);
        close(new_socket);
    }
}

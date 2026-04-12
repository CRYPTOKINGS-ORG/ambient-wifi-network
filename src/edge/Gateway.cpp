#include "Gateway.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

Gateway::Gateway(int port) : port(port) {}

void Gateway::start() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;

    bind(sockfd, (struct sockaddr*)&addr, sizeof(addr));
    listen(sockfd, 5);

    std::cout << "Gateway listening on port " << port << std::endl;

    while (true) {
        int client = accept(sockfd, nullptr, nullptr);
        char buffer[1024] = {0};
        read(client, buffer, 1024);
        std::cout << "Received: " << buffer << std::endl;
        close(client);
    }
}

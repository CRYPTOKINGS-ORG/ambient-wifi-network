#include "server/HttpServer.h"
#include "edge/Gateway.h"
#include "utils/EnvLoader.h"

int main() {
    EnvLoader env(".env");

    int port = std::stoi(env.get("PORT"));
    int gatewayPort = std::stoi(env.get("GATEWAY_PORT"));

    HttpServer server(port);
    Gateway gateway(gatewayPort);

    std::thread serverThread([&]() { server.start(); });
    std::thread gatewayThread([&]() { gateway.start(); });

    serverThread.join();
    gatewayThread.join();

    return 0;
}

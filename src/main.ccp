#include "core/Config.h"
#include "core/Logger.h"
#include "net/HttpServer.h"
#include "edge/Gateway.h"

int main() {
    Config config(".env");

    int port = config.getInt("PORT");
    int gatewayPort = config.getInt("GATEWAY_PORT");

    Logger::info("Starting system...");

    HttpServer server(port, config);
    Gateway gateway(gatewayPort);

    std::thread t1([&]() { server.start(); });
    std::thread t2([&]() { gateway.start(); });

    t1.join();
    t2.join();

    return 0;
}

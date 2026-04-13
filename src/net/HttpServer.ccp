#include "HttpServer.h"
#include "../security/TLS.h"
#include "../core/Logger.h"
#include <unistd.h>

HttpServer::HttpServer(int port, Config& config)
    : port(port), config(config), pool(config.getInt("THREAD_POOL_SIZE")) {}

void HttpServer::start() {
    SSL_CTX* ctx = TLS::createContext();
    TLS::configure(ctx);

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_fd, (sockaddr*)&addr, sizeof(addr));
    listen(server_fd, 50);

    Logger::info("HTTPS Server running...");

    while (true) {
        int client = accept(server_fd, nullptr, nullptr);

        pool.enqueue([this, client, ctx]() {
            SSL* ssl = SSL_new(ctx);
            SSL_set_fd(ssl, client);

            if (SSL_accept(ssl) <= 0) {
                SSL_free(ssl);
                close(client);
                return;
            }

            char buffer[4096] = {0};
            SSL_read(ssl, buffer, sizeof(buffer));

            std::string response = router.handle(buffer);

            SSL_write(ssl, response.c_str(), response.size());

            SSL_free(ssl);
            close(client);
        });
    }
}

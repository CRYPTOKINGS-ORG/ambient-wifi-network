#pragma once
#include "../core/Config.h"
#include "Router.h"
#include "ThreadPool.h"
#include <openssl/ssl.h>

class HttpServer {
public:
    HttpServer(int port, Config& config);
    void start();

private:
    int port;
    Config& config;
    Router router;
    ThreadPool pool;
};

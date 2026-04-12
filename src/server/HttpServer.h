#pragma once
class HttpServer {
public:
    HttpServer(int port);
    void start();
private:
    int port;
};

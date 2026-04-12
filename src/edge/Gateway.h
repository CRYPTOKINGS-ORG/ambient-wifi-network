#pragma once

class Gateway {
public:
    Gateway(int port);
    void start();
private:
    int port;
};

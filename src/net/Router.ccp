#include "Router.h"

std::string Router::handle(const std::string& request) {

    if (request.find("GET /") != std::string::npos) {
        return "HTTP/1.1 302 Found\r\nLocation: http://portal.local\r\n\r\n";
    }

    if (request.find("GET /api/captive") != std::string::npos) {
        return "HTTP/1.1 200 OK\nContent-Type: application/json\n\n{\"status\":\"free\"}";
    }

    if (request.find("POST /api/auth") != std::string::npos) {
        return "HTTP/1.1 200 OK\nContent-Type: application/json\n\n{\"token\":\"abc123\"}";
    }

    return "HTTP/1.1 404 Not Found\n\n";
}

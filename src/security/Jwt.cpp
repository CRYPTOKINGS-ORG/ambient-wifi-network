#include "Jwt.h"

std::string Jwt::sign(const std::string& payload) {
    return "jwt_" + payload;
}

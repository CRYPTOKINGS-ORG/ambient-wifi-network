#include "AuthService.h"

std::string AuthService::generateToken(const std::string& deviceId) {
    return "token_" + deviceId;
}
